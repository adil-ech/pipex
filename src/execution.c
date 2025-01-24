/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:17:01 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/24 23:31:03 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char *get_command_path(char *cmd)
{
    char **paths;
    char *full_path;
    char *path_env;
    int i;

    if (ft_strchr(cmd, '/'))
    {
        if (access(cmd, X_OK) == 0)
            return (ft_strdup(cmd));
        error_exit("Command not found or not executable");
    }
    path_env = getenv("PATH");
    if (!path_env)
        error_exit("PATH environment variable not found");
    paths = ft_old_split(path_env, ':');
    i = 0;
    while (paths[i])
    {
        full_path = ft_strjoin(paths[i], "/");
        full_path = ft_strjoin(full_path, cmd);
        if (access(full_path, X_OK) == 0)
        {
            free_darray(paths);
            return (full_path);
        }
        free(full_path);
        i++;
    }
    free_darray(paths);
    error_exit("Command not found");
    return (NULL);
}

void exec_cmd(char *cmd, int infd, int outfd, char **envp)
{
    char **args;
    char *cmd_path;

    if (dup2(infd, STDIN_FILENO) == -1 || dup2(outfd, STDOUT_FILENO) == -1)
        error_exit("dup2 failed");
    close(infd);
    close(outfd);
    args = ft_split(cmd);
    cmd_path = get_command_path(args[0]);
    execve(cmd_path, args, envp);
    perror("execve failed");
    exit(errno);
}

void pipex_exec(int argc, char **argv, char **envp)
{
    int pipefd[2];
    int infile, outfile;
    pid_t pid;

    if (argc != 5)
        error_exit("Usage: ./pipex infile cmd1 cmd2 outfile");
    infile = open(argv[1], O_RDONLY);
    if (infile == -1)
        error_exit("Error opening infile");
    outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (outfile == -1)
        error_exit("Error opening outfile");
    if (pipe(pipefd) == -1)
        error_exit("pipe failed");
    pid = fork();
    if (pid == -1)
        error_exit("fork failed");
    if (pid == 0)
    {
        close(pipefd[0]);
        exec_cmd(argv[2], infile, pipefd[1], envp);
    }
    close(pipefd[1]);
    pid = fork();
    if (pid == -1)
        error_exit("fork failed");
    if (pid == 0)
    {
        close(pipefd[1]);
        exec_cmd(argv[3], pipefd[0], outfile, envp);
    }
    close(pipefd[0]);
    wait(NULL);
    wait(NULL);
}

// static void	exec_cmd(t_cmd *cmd, int infd, int outfd, char **env)
// {
// 	if (dup2(infd, STDIN_FILENO) == -1 || dup2(outfd, STDOUT_FILENO) == -1)
// 		error_exit("dup2 failed for input");
// 	close(infd);
// 	close(outfd);
// 	if (!cmd->path)
// 	{
// 		error_exit("error commane not found");
// 		exit(EXIT_FAILURE);
// 	}
// 	execve(cmd->path, cmd->args, env);
// 	perror("execve failed");
// 	exit(EXIT_FAILURE);
// }

// void	pipex_exec(t_ppx *pipex, char **env)
// {
// 	pid_t	pid;
// 	int		pipefd[2];
// 	int		infd;
// 	int		outfd;


// 	infd = 0;
// 	if (pipe(pipefd) == -1)
// 		error_exit("Error creating pipe\n");
// 	pid = fork();
// 	if (pid == -1)
// 		error_exit("Error during fork\n");
// 	if (pid == 0)
// 	{
// 		close(pipefd[0]);
// 		infd = open(pipex->file1, O_RDONLY);
// 		if (infd < 0)
// 			error_exit("Error opening file\n");
// 		exec_cmd(&pipex->cmd1[0], infd, pipefd[1], env);
// 	}
// 	close(pipefd[1]);
// 	pid = fork();
// 	if (pid == -1)
// 		error_exit("Error during fork\n");
// 	if (pid == 0)
// 	{
// 		outfd = open(pipex->file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 		if (outfd < 0)
// 			error_exit("Error opemimg outfile\n");
// 		exec_cmd(&pipex->cmd1[1], infd, outfd, env);
// 	}
// 	close(infd);
// 	while (wait(NULL) > 0)
// 		;
// }
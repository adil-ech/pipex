/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:29:52 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/28 17:33:39 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**parse_command(const char *cmd)
{
	char	**args;

	args = ft_old_split(cmd, ' ');
	return (args);
}

static char	*findynorm(char *cmd)
{
	char	*path;
	char	**paths;
	char	*cmd_path;
	int		i;

	path = getenv("PATH");
	if (!path)
		return (NULL);
	paths = ft_old_split(path, ':');
	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin_free(cmd_path, cmd);
		if (access(cmd_path, X_OK) == 0)
		{
			free_darray(paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free_darray(paths);
	return (NULL);
}

char	*findcomms(char *cmd)
{
	char	*cmd_path;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		else
			return (NULL);
	}
	cmd_path = findynorm(cmd);
	if (cmd_path)
		return (cmd_path);
	else
		return (NULL);
}

void	parsprocess(char **av, char **env, t_ppx *pipex)
{
	if (pipex->pid == 0)
	{
		close(pipex->pipefd[0]);
		child_process(pipex->infile, pipex->pipefd[1], av[2], env);
	}
	else
	{
		waitpid(pipex->pid, NULL, 0);
		close(pipex->pipefd[1]);
		pipex->pid = fork();
		if (pipex->pid == -1)
			pidfail(pipex);
		if (pipex->pid == 0)
		{
			child_process(pipex->pipefd[0], pipex->outfile, av[3], env);
		}
		else
		{
			close(pipex->pipefd[0]);
			close(pipex->outfile);
			waitpid(pipex->pid, NULL, 0);
		}
	}
}

void	parsmepls(char **av, char **env, t_ppx *pipex)
{
	pipex->pid = fork();
	if (pipex->pid == -1)
		pidfail(pipex);
	parsprocess(av, env, pipex);
}

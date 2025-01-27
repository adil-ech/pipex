/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:14:49 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/25 21:06:10 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	execute_command(const char *cmd, char **env)
{
	char	**args;
	char	*cmd_path;

	args = parse_command(cmd);
	if (!args || !args[0])
	{
		free_darray(args);
		error_exit("Command not found", 127);
	}
	cmd_path = findcomms(args[0]);
	if (!cmd_path)
	{
		free_darray(args);
		error_exit("Command not found", 127);
	}
	execve(cmd_path, args, env);
	free(cmd_path);
	free_darray(args);
	error_exit("Execution failed", 1);
}

void	child_process(int infd, int outfd, const char *cmd, char **env)
{
	if (dup2(infd, STDIN_FILENO) == -1
		|| dup2(outfd, STDOUT_FILENO) == -1)
		error_exit("Duplication failed", 1);
	close(infd);
	close(outfd);
	execute_command(cmd, env);
}

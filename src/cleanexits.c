/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanexits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:11:01 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/24 23:28:22 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_cmd(t_cmd *cmd)
{
	if (cmd)
	{
		if (cmd->path)
			free(cmd->path);
		if (cmd->args)
			free_darray(cmd->args);
	}
}
void	free_pipex(t_ppx *pipex)
{
	if (pipex)
	{
		if (pipex->cmd1)
		{
			free_cmd(pipex->cmd1);
			free(pipex->cmd1);
		}
		if (pipex->cmd2)
		{
			free_cmd(pipex->cmd2);
			free(pipex->cmd2);
		}
	}
}

void error_exit(const char *msg)
{
	perror(msg);
	// free_pipex(pipex);
	// closefd()
	exit(EXIT_FAILURE);
}

void	free_darray(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
	}
	free(arr);
}

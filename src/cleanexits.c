/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanexits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:11:01 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/28 17:32:05 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

void	error_exit(const char *message, int exit_code)
{
	perror (message);
	exit (exit_code);
}

void	pidfail(t_ppx *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	error_exit("Fork failed", 1);
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

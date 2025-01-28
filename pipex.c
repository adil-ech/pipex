/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:31:21 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/28 17:43:57 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	fprocess(char **av, t_ppx *pipex)
{
	pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile == -1)
	{
		ft_putstr_fd("Error: couldnt open the infile. continuing...\n", 2);
		pipex->infile = open("/dev/null", O_RDONLY);
		if (pipex->infile == -1)
			error_exit("Failed to open /dev/null", 1);
	}
	pipex->outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile == -1)
	{
		close(pipex->infile);
		error_exit("Error opening outfile", 1);
	}
	if (pipe(pipex->pipefd) == -1)
	{
		close(pipex->infile);
		close(pipex->outfile);
		error_exit("Pipe creation failed", 1);
	}
}

int	main(int ac, char **av, char **env)
{
	t_ppx	pipex;

	if (ac != 5)
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
		return (1);
	}
	fprocess(av, &pipex);
	parsmepls(av, env, &pipex);
	close(pipex.infile);
	close(pipex.outfile);
	return (0);
}

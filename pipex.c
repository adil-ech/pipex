/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:31:21 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/24 23:34:04 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	f()
{
	system("leaks pipex");
}
int main(int ac, char **av, char **envp)
{
	atexit(f);
	t_ppx pipex;

	if (ac != 5)
	{
		ft_printf("Invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	pipex_exec(ac, av, envp);
	free_pipex(&pipex);
	return (EXIT_SUCCESS);
}

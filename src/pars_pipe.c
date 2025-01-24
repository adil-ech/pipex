/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:27:49 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/24 23:04:41 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	*getpath(char **env)
{
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			return (*env + 5);
		env++;
	}
	return (NULL);	
}

static char	*isvalidcomm(char *cmd, char **env)
{
	char	*path_env;
	char	**paths;
	char	*full_path;
	char	*tmp;
	int		i;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		else
			return (NULL);
	}
	path_env = getpath(env);
	if (!path_env)
		return (NULL);
	paths = ft_old_split(path_env, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full_path, X_OK) == 0)
		{
			free_darray(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_darray(paths);
	return (NULL);
}

static void	pars_cmd(char *cmd_str, char **env, t_cmd *cmd)
{
	char	**parts;

	parts = ft_split(cmd_str);
	if (!parts)
		error_exit("Error Command pars failed");
	cmd->path = isvalidcomm(parts[0], env);
	cmd->args = parts;
	if (!cmd->args)
		ft_printf("Warning: command {%s} is invalid\n", parts[0]);
}

int	pars_args(char **av, char **env, t_ppx *pipex)
{
	if (access(av[1], R_OK) != 0)
		error_exit("Error unvalid access to infile");
	if (access(av[4], W_OK) != 0 && open(av[4], O_WRONLY | O_CREAT, 0644) == -1)
		error_exit("Error unvalid access to outfile");
	pipex->file1 = av[1];
	pipex->file2 = av[4];
	pipex->cmd1 = malloc(sizeof(t_cmd));
	pipex->cmd2 = malloc(sizeof(t_cmd));
	if (!pipex->cmd1 || !pipex->cmd2)
		error_exit("Error allc failed");
	pars_cmd(av[2], env, pipex->cmd1);
	pars_cmd(av[3], env, pipex->cmd2);	
	if (!pipex->cmd1->path)
		ft_printf("Warning Invalid cmd1\n");
	if (!pipex->cmd2->path)
		ft_printf("Warning Invalid cmd2\n");
	return (0);
}

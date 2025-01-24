/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:31:49 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/24 23:25:26 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct	s_cmd
{
	char	*path;
	char	**args;
}	t_cmd;

typedef struct s_ppx
{
	char	*file1;
	char	*file2;
	t_cmd	*cmd1;
	t_cmd	*cmd2;
}	t_ppx;

//pipe utils
int		pars_args(char **av, char **env, t_ppx *pipex);
void	free_pipex(t_ppx *pipex);
void	error_exit(const char *msg);
void	free_darray(char **arr);
void	free_cmd(t_cmd *cmd);
// void	pipex_exec(t_ppx *pipex, char **env);
void pipex_exec(int argc, char **argv, char **envp);
//utils
int		ft_printf(const char *str, ...);
char	**ft_split(char const *s);
int		iswhitespace(int c);
char	**ft_old_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t num);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
#endif
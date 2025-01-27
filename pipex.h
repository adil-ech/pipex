/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:31:49 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/25 18:43:51 by adechaji         ###   ########.fr       */
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

typedef struct s_ppx
{
	int		infile;
	int		outfile;
	int		pipefd[2];
	pid_t	pid;
}	t_ppx;

//pipe utils
void	error_exit(const char *message, int exit_code);
void	free_darray(char **arr);
char	*ft_strjoin_free(char *s1, char *s2, int to_free);
void	parsmepls(char **av, char **env, t_ppx *pipex);
char	*findcomms(char *cmd);
char	**parse_command(const char *cmd);
void	child_process(int infd, int outfd, const char *cmd, char **env);
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
void	ft_putstr_fd(char *s, int fd);

#endif
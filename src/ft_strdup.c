/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:37:09 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/22 22:49:51 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		slen;
	int		i;

	i = 0;
	slen = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * slen + 1);
	if (!str)
		return (NULL);
	while (i < slen)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

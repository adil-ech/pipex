/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:03:33 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/23 00:22:16 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmps;

	tmps = (unsigned char *)s;
	while (n > 0)
	{
		*tmps = 0;
		tmps++;
		n--;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_extra_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:17:38 by adechaji          #+#    #+#             */
/*   Updated: 2024/11/20 23:35:46 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_uns_nbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_put_uns_nbr(n / 10);
	if (count < 0)
		return (-1);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	print_low_hex(unsigned int num)
{
	char	*hexa;
	char	holder[16];
	int		count;
	int		i;

	hexa = "0123456789abcdef";
	i = 0;
	count = 0;
	if (num == 0)
		return (write(1, "0", 1));
	while (num)
	{
		holder[i++] = hexa[num % 16];
		num /= 16;
	}
	while (i--)
		count += write(1, &holder[i], 1);
	return (count);
}

int	print_up_hex(unsigned int num)
{
	char	*hexa;
	char	holder[16];
	int		count;
	int		i;

	hexa = "0123456789ABCDEF";
	i = 0;
	count = 0;
	if (num == 0)
		return (write(1, "0", 1));
	while (num)
	{
		holder[i++] = hexa[num % 16];
		num /= 16;
	}
	while (i--)
		count += write(1, &holder[i], 1);
	return (count);
}

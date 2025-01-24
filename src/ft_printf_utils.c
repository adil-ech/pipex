/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:36:21 by adechaji          #+#    #+#             */
/*   Updated: 2024/11/20 23:39:17 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[count])
		write(1, &str[count++], 1);
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		count += ft_putchar('-');
		if (count < 0)
			return (-1);
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	if (count < 0)
		return (-1);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_strcount(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	print_hex(unsigned long num)
{
	char	*hexa;
	char	holder[16];
	int		count;
	int		i;

	hexa = "0123456789abcdef";
	i = 0;
	count = 0;
	if (num == 0)
		return (write(1, "0x0", 3));
	count += write(1, "0x", 2);
	while (num)
	{
		holder[i++] = hexa[num % 16];
		num /= 16;
	}
	while (i--)
		count += write(1, &holder[i], 1);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:18:42 by adechaji          #+#    #+#             */
/*   Updated: 2024/11/20 23:40:09 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	toprint(va_list track, const char str)
{
	int	print;

	print = 0;
	if (str == 'c')
		print += ft_putchar(va_arg(track, int));
	else if (str == 's')
		print += ft_putstr(va_arg(track, char *));
	else if (str == 'p')
		print += print_hex((unsigned long)va_arg(track, void *));
	else if (str == 'd' || str == 'i')
		print += ft_putnbr(va_arg(track, int));
	else if (str == 'u')
		print += ft_put_uns_nbr(va_arg(track, unsigned int));
	else if (str == 'x')
		print += print_low_hex(va_arg(track, unsigned int));
	else if (str == 'X')
		print += print_up_hex(va_arg(track, unsigned int));
	else if (str == '%')
		print += write(1, "%", 1);
	return (print);
}

int	ft_printf(const char *str, ...)
{
	va_list		track;
	int			i;
	int			printer;

	i = 0;
	printer = 0;
	va_start(track, str);
	if (write(1, "", 0) == -1)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1])
			{
				printer += toprint(track, str[i + 1]);
				i++;
			}
		}
		else
			printer += ft_putchar(str[i]);
		i++;
	}
	va_end(track);
	return (printer);
}

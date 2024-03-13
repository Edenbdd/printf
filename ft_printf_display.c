/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aubertra <aubertra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:40:14 by aubertra          #+#    #+#             */
/*   Updated: 2024/03/13 20:02:00 by aubertra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned_nb(unsigned int arguments)
{
	int				len;
	unsigned int	temp;

	len = 0;
	temp = arguments;
	if (arguments == 0)
		len++;
	while (temp > 0)
	{
		temp /= 10;
		len++;
	}
	if (arguments <= 9)
		ft_putchar_fd(arguments + 48, 1);
	if (arguments > 9)
	{
		print_unsigned_nb(arguments / 10);
		print_unsigned_nb(arguments % 10);
	}
	return (len);
}

int	print_nb(int arguments)
{
	int	len;

	len = 0;
	ft_putnbr_fd(arguments, 1);
	if (arguments == 0)
		len++;
	if (arguments < 0)
	{
		if (arguments == -2147483648)
			len += 11;
		else
		{
			arguments = -arguments;
			len++;
		}
	}
	while (arguments > 0)
	{
		arguments /= 10;
		len++;
	}
	return (len);
}

int	hexa_len(unsigned int arguments)
{
	int	len;

	len = 0;
	if (arguments == 0)
		len++;
	while (arguments > 0)
	{
		arguments /= 16;
		len ++;
	}
	return (len);
}

int	print_hexa(const char mandatory, unsigned int arguments)
{
	char	*list;
	int		len;

	len = 0;
	if (mandatory == 'x')
		list = "0123456789abcdef";
	else if (mandatory == 'X')
		list = "0123456789ABCDEF";
	if (arguments < 16)
		ft_putchar_fd(list[arguments], 1);
	else
	{
		print_hexa(mandatory, (arguments / 16));
		print_hexa(mandatory, (arguments % 16));
	}
	len += hexa_len(arguments);
	return (len);
}

int	print_str(char *arguments)
{
	int	len;

	len = 0;
	if (arguments == NULL)
		return (write(1, "(null)", 6));
	ft_putstr_fd(arguments, 1);
	while (arguments[len])
		len++;
	return (len);
}

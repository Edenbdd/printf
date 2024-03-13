/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aubertra <aubertra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:27:15 by aubertra          #+#    #+#             */
/*   Updated: 2024/03/13 19:54:02 by aubertra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(const char mandatory, unsigned long long pointer)
{
	char				*list;
	int					len;
	unsigned long long	temp;

	temp = pointer;
	len = 0;
	while (temp > 0)
	{
		temp /= 16;
		len++;
	}
	list = "0123456789abcdef";
	if (pointer < 16)
		ft_putchar_fd(list[pointer], 1);
	else
	{
		print_pointer(mandatory, (pointer / 16));
		print_pointer(mandatory, (pointer % 16));
	}
	return (len + 2);
}

int	print_char(const char mandatory, va_list arguments)
{
	if (mandatory == 'c')
		ft_putchar_fd(va_arg(arguments, int), 1);
	else
		ft_putchar_fd('%', 1);
	return (1);
}

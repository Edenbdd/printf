/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aubertra <aubertra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:17:26 by aubertra          #+#    #+#             */
/*   Updated: 2024/03/13 11:12:09 by aubertra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_type(va_list arguments, const char mandatory)
{
	unsigned long long	stock_ptr;

	if (mandatory == 'd' || mandatory == 'i')
		return (print_nb(va_arg(arguments, int)));
	else if (mandatory == 'u')
		return (print_unsigned_nb(va_arg(arguments, int)));
	else if (mandatory == 'x' || mandatory == 'X')
		return (print_hexa(mandatory, va_arg(arguments, unsigned int)));
	else if (mandatory == 's')
		return (print_str(va_arg(arguments, char *)));
	else if (mandatory == 'c' || mandatory == '%')
		return (print_char(mandatory, arguments));
	else if (mandatory == 'p')
	{
		stock_ptr = va_arg(arguments, unsigned long long);
		if (stock_ptr == 0)
			return (write (1, "(nil)", 5));
		write(1, "0x", 2);
		return (print_pointer(mandatory, stock_ptr));
	}
	return (0);
}

int	ft_printf(const char *mandatory, ...)
{
	va_list	arguments;
	int		len;
	int		count;

	va_start(arguments, mandatory);
	len = 0;
	count = 0;
	while (mandatory[count] != '\0')
	{
		if (mandatory[count] == '%')
		{
			len += ft_type(arguments, mandatory[count + 1]);
			count++;
		}
		else
		{
			ft_putchar_fd(mandatory[count], 1);
			len++;
		}
		count ++;
	}
	va_end(arguments);
	return (len);
}
/*
int	main(void)
{
    	printf("%d\n", ft_printf("le chiffre préféré de maman est %X\n", 546546));
    	printf("le chiffre préféré de maman est %X\n", 546546);
    	return (0);
}
*/


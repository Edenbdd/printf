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
		if (va_arg(arguments, unsigned long long) == 0)
			return (write (1, "(nil)", 5));
		write(1, "0x", 2);
		return (print_pointer(mandatory,
					va_arg(arguments, unsigned long long)) + 2);
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

int	main(void)
{
	char		*str;
	unsigned int	*ptr;
	unsigned int	x;
	unsigned int	X;
	x = 1800; 
	X = 17;
	ptr = 0;
	char    c;
	c = 'A';

    	str = "string";
   	printf("%d\n", ft_printf("%s", str));
   	printf("%s\n", str);
    	printf("%d\n", ft_printf("un int %d", 42));
    	printf("un int %d\n", 42);
    	printf("%d\n", ft_printf("un char %c", c));
	printf("un char %c\n", c);
    	printf("%d\n", ft_printf("un pointer %p.", ptr));
	printf("un pointer %p.\n", ptr);
	printf("%d\n", ft_printf("%x.", x));
    	printf("un hexa %x.\n", x);
    	printf("%d\n", ft_printf("%X.", X));
    	printf("un hexa caps %X.\n", X);
    	printf("%d\n", ft_printf("%%"));
    	printf("%%");
    	return (0);
}

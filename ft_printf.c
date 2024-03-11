/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aubertra <aubertra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:17:26 by aubertra          #+#    #+#             */
/*   Updated: 2024/03/08 14:21:32 by aubertra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_type(va_list arguments, const char mandatory)
{
	int	len;
	
	len = 0;
	if (mandatory == 'd' || mandatory == 'i' || mandatory == 'u')
                len += print_nb(va_arg(arguments, int));
	else if (mandatory == 'x' || mandatory == 'X')
		len += print_hexa(mandatory, va_arg(arguments, unsigned int));
	else if (mandatory == 's')
		len += print_str(va_arg(arguments, char *)); 
	else if (mandatory == 'c' || mandatory == '%')
	{
		len ++;
		if (mandatory == 'c')
	       		ft_putchar_fd(va_arg(arguments, int), 1);
		else
			ft_putchar_fd('%', 1);	
	}
	else if (mandatory == 'p')
		len += print_pointer(mandatory, va_arg(arguments, int));
	return (len);
}

int ft_printf(const char *mandatory, ...)
{
	va_list   arguments;
	va_start(arguments, mandatory);
	int	len;
	int	count;

	count = 0;
	len = 0;
	
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
	char    *str;
	unsigned int     *ptr;
	unsigned int     x;
	unsigned int     X;
	x = 1800; 
	X = 17;
	ptr = &x;
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

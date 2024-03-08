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

#include "ft_printf.h"


int ft_printf(const char *mandatory, ...)
{
    va_list   arguments;
    va_start(arguments, mandatory);
    int count;
    int len;
    int integer;
    char    *str;
    int hex;
    int *pointer;

    pointer = malloc(sizeof(int) * 14);
    hex = 0;
    count = 0;
    len = 0;
    while (mandatory[count] != '\0')
    {
        len++;
        if (mandatory[count] != '%')
            ft_putchar_fd(mandatory[count], 1);
        else
        {
           if (mandatory[count + 1] == 'd' || mandatory[count + 1] == 'i'
                 || mandatory[count +1] == 'u')
            {
                integer = va_arg(arguments, int);
                len += ft_len(integer);
                ft_putnbr_fd(integer, 1);
            }
            if (mandatory[count + 1] == 'x' || mandatory[count + 1] == 'X')
            {
                hex = va_arg(arguments, int);
                len += ft_len(hex);
                if (mandatory[count + 1] == 'X')
                    print_hexa_caps(hex);
                else
                    print_hexa(hex);
            }
            if (mandatory[count + 1] == 's')
            {
                str = va_arg(arguments, char *);
                len += ft_strlen(str) -1;
                ft_putstr_fd(str, 1);
            }
            if (mandatory[count + 1] == 'c' || mandatory[count + 1] == '%')
            {
                if (mandatory[count + 1] == '%')
                    ft_putchar_fd('%', 1);
                else
                    ft_putchar_fd(va_arg(arguments, int), 1);
            }
            count++;
        }
        count++;
    }
    va_end(arguments);
    return (len);
}

int main(void)
{
    char    *str;
    int     *ptr;
    int     nb;
    int     x;
    int     X;

    nb = 10;
    x = 13;
    X = 15;
    ptr = &nb;

    char    c;

    c = 'A';
    str = "string";
    printf("%d\n", ft_printf("1 %s 2 %s", str, str));
    printf("une %s 1\n", str);
    printf("%d\n", ft_printf("un int %d", 42));
    printf("un int %d\n", 42);
    printf("%d\n", ft_printf("un char %c\n", c));
    printf("un char %c\n", c);
    printf("%d\n", ft_printf("un pointer %p.", ptr));
    printf("un pointer %p.\n", ptr);
    printf("%d\n", ft_printf("un hexa %x.", x));
    printf("un hexa %x.\n", x);
    printf("%d\n", ft_printf("un phexa caps %X.", X));
    printf("un hexa caps %X.\n", X);
    printf("%d\n", ft_printf("%%"));
    printf("%%");

    return (0);
}

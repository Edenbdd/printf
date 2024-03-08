/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aubertra <aubertra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:17:26 by aubertra          #+#    #+#             */
/*   Updated: 2024/02/14 17:47:02 by aubertra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int ft_len(int nbr)
{
    int len;

    len = 0;
    while (nbr > 0)
    {
        nbr /= 10;
        len++;
    }
    return (len);
}

void print_hexa(int nb)
{
    char    *list;

    list = "0123456789abcdef";
    if (nb >= 0 && nb < 10)
        ft_putchar_fd(nb, 1);
    else if (nb >= 10 && nb <= 15)
        ft_putchar_fd(list[nb], 1);
    else
    {
        print_hexa(nb / 16);
        print_hexa(nb % 16);
    }
}

void print_hexa_caps(int nb)
{
    char    *list;

    list = "0123456789ABCDEF";
    if (nb >= 0 && nb <= 10)
        ft_putchar_fd(nb, 1);
    else if (nb > 10 && nb <= 16)
        ft_putchar_fd(list[nb], 1);
    else
    {
        print_hexa(nb / 16);
        print_hexa(nb % 16);
    }
}

void print_pointer(int *pointer)
{
    int count;

    count = 0;
    while (count < 14)
    {
        if (pointer[count] >= 0 && pointer[count] <= 9)
        {
            ft_putnbr_fd(pointer[count], 1);
        }
        else
            ft_putchar_fd(pointer[count], 1);
    }
}

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
            if (mandatory[count + 1] == 'p')
            {
                pointer = (int *)va_arg(arguments, int);
                len += 14;
                print_pointer(pointer);
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
//    char    *str;
    int     *ptr;
    int     nb;
    int     x;
    int     X;

    nb = 10;
    x = 13;
    X = 15;
    ptr = &nb;

//    char    c;
/*    
    c = 'A';
    str = "string";
    printf("%d\n", ft_printf("1 %s 2 %s", str, str));
    printf("une %s 1\n", str);
    printf("%d\n", ft_printf("un int %d", 42));
    printf("un int %d\n", 42);
    printf("%d\n", ft_printf("un char %c\n", c));
    printf("un char %c\n", c);
*/
    printf("%d\n", ft_printf("un pointer %p.", ptr));
    printf("un pointer %p.\n", ptr);
    printf("%d\n", ft_printf("un hexa %x.", x));
    printf("un hexa %x.\n", x);
    printf("%d\n", ft_printf("un phexa caps %X.", X));
    printf("un hexa caps %X.\n", X);
/*
    printf("%d\n", ft_printf("%%"));
    printf("%%");
*/
    return (0);
}
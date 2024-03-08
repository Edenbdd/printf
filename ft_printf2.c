/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aubertra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:17:21 by aubertra          #+#    #+#             */
/*   Updated: 2024/03/08 14:26:08 by aubertra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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


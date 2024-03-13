/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aubertra <aubertra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:32:36 by aubertra          #+#    #+#             */
/*   Updated: 2024/03/13 10:56:59 by aubertra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <bsd/string.h>

void	ft_putnbr_fd(int arguments, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char * arguments, int fd);

int     print_nb (int arguments);
int     hexa_len(unsigned int arguments);
int     print_hexa(const char mandatory, unsigned int arguments);
int     print_str(char *arguments);
int		print_pointer(const char mandatory, unsigned long long pointer);
int		print_unsigned_nb(unsigned int arguments);
int		print_char(const char mandatory, va_list arguments);

#endif

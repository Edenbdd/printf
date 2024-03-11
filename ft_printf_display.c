
#include <stdarg.h>
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar_fd(n + 48, fd);
	}
	if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_len(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
                len++;
        if (nb < 0)
                nb = -nb;
	while (nb > 0)
        {
                nb /= 10;
                len++;
        }
        return (len);
}

int	print_nb (int arguments)
{
	int	len;

	len = 0;
	ft_putnbr_fd(arguments, 1);
	len += ft_len(arguments);
	return (len);
}

int	hexa_len(unsigned int arguments)
{
	int	len;

	len = 0;
	while (arguments > 0)
	{
		arguments /= 16;
		len ++;
	}
	return (len);
}

int	print_hexa(const char mandatory, unsigned int arguments)
{
	char    *list;
	int	len;

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
	ft_putstr_fd(arguments, 1);
	while (arguments[len])
		len++;
	return (len);
}

int print_pointer(int *pointer)
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
		count++;
    	}
	return (14);
}

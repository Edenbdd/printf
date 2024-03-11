
#include "libft.h"

#include "ft_putchar_fd.c"
#include "ft_putnbr_fd.c"
#include "ft_putstr_fd.c"

int	print_nb (int arguments)
{
	int	len;

	len = 0;
	ft_putnbr_fd(arguments, 1);
        if (arguments == 0)
                len++;
        if (arguments < 0)
                arguments = -arguments;
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

int print_pointer(const char mandatory, int pointer)
{
	print_hexa(mandatory, pointer);
	return (14);
}

NAME = libftprintf.a

HEADER = ft_printf.h

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3

SRCS =  ft_printf.c\
		ft_printf_display2.c\
		ft_printf_display.c\
		ft_putchar_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re so

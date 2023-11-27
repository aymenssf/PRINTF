NAME	= libftprintf.a
CFLAGS  = -Wall -Werror -Wextra
CC	= cc
SRC	= ft_print_pp.c ft_print_u.c ft_print_x.c ft_printf.c\
		       ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c

OBJ 	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar -rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

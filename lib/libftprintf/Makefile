FLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SRCS = ft_printf.c ft_putchar_count.c ft_putnbr_d_count.c ft_putnbr_u_count.c ft_putnbr_ux_count.c ft_putnbr_x_count.c ft_putstr_count.c ft_pointer_count.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%o:%c
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
NAME	=	push_swap

SRCS	=	main.c \
			push_swap_utils.c \
			operations/operations_utils.c \
			sort/sort_utils.c \
			error/error_handler.c \
			parser/args_parsing.c \
			sort/sort.c \
			sort/sort_lst_under_5.c \
			sort/sort_lst_under_5_utils.c \
			sort/sort_big_list.c \
			operations/push_swap.c \
			operations/rotate.c \
			operations/reverse_rotate.c \
			lib/ft_atoi.c \
			lib/ft_int_overflow.c \
			lib/ft_isdigit.c \
			lib/ft_isdigitstr.c \
			lib/ft_printf.c \
			lib/ft_put.c \
			lib/ft_putnb.c \
			lib/ft_split.c \
			lib/ft_strcmp.c \
			lib/ft_strlen.c \
			lib/ft_itoa.c \
			lib/ft_calloc.c \
			lib/ft_bzero.c

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g3 #-fsanitize=address -g3

%.o: %.c include/push_swap.h lib/lib.h Makefile
	$(CC) $(CFLAGS) -I. -c $< -o $@

all: $(NAME)

$(NAME):	$(SRCS:.c=.o) include/push_swap.h lib/lib.h Makefile
			$(CC) $(CFLAGS) -I. $(SRCS) -o $(NAME)

clean:
			rm -drf $(SRCS:.c=.o)

fclean:	clean
		rm -drf $(NAME)

re:		fclean all

.PHONY:	all libft fclean re

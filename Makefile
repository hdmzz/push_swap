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
			operations/reverse_rotate.c

CC		= gcc -g3
CFLAGS	= -Wall -Wextra -Werror

%.o: %.c include/push_swap.h libft/libft.a libft/libft.h Makefile
	$(CC) $(CFLAGS) -I. -c $< -o $@

all: libft $(NAME)

$(NAME):	$(SRCS:.c=.o)
		$(CC) $(CFLAGS) -I. $(SRCS) libft/libft.a -o $(NAME)

libft:
		@make -C libft

clean:
		rm -drf $(SRCS:.c=.o)
		@make clean -C libft

fclean:	clean
		rm -drf $(NAME)
		@make fclean -C libft

re:		fclean all

.PHONY:	all libft fclean re

NAME	=	push_swap
SRCS	=	main.c \
			push_swap_utils.c \
			operations_utils.c \
			sort_utils.c \
			error_handler.c \
			parser/args_parsing.c \
			sort/sort.c \
			sort/sort_lst_under_5.c \
			operations/push_swap.c \
			operations/rotate.c

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

%.o: %.c push_swap.h libft/libft.a Makefile
	$(CC) -I. $< -c -o $@

all:	libft $(NAME)

libft:
		@make -C libft

$(NAME):	$(SRCS:.c=.o) push_swap.h
			$(CC) -g -I. $(CFLAGS) $(SRCS) -L. libft/libft.a -o $(NAME)

clean:
			rm -drf $(SRCS:.c=.o)
			@make clean -C libft

fclean:	clean
		rm -drf $(NAME)
		@make fclean -C libft

re:		fclean all

.PHONY:	all libft fclean re

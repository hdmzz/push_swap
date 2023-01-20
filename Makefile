NAME	= push_swap
SRCS	= main.c

CC		= clang
CFLAGS	= -Wall -Wextra -Werror

%.o: %.c libft/libft.a Makefile
	$(CC) $< -c -o $@

all:	libft $(NAME)

libft:
		@make -C libft

$(NAME):	$(SRCS:.c=.o)
			$(CC) $(CFLAGS) $(SRCS) -L. libft/libft.a -o $(NAME)

clean:
			rm -drf $(SRCS:.c=.o)
			@make clean -C libft

fclean:	clean
		rm -drf $(NAME)
		@make fclean -C libft

re:		fclean all

.PHONY:	all libft fclean re

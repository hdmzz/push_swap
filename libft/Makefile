S = src/
O = obj/
LIBFT = libft.a

include settings.mk

OBJ = $(SRCLIBFT:%=$O%.o)

RM = /bin/rm -rf
RMDIR = /bin/rmdir

.PHONY: all clean fclean re

all: $(NAME)

$O:
	@mkdir $@

$(OBJ): | $O

$(OBJ): $O%.o: % libft.h Makefile settings.mk
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar -rcs $@ $^

cleanobj:
	$(RM) $(SRCLIBFT:%=$O%.o)

cleanobjdir: cleanobj
	$(RM) $O

clean: cleanobjdir

fclean: clean
	$(RM) $(NAME)
	$(RM) $D

re: fclean all

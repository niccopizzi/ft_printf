CFLAGS = -Wall -Wextra -Werror 

NAME = libftprintf.a 

LIBFT_LIB = libft/libft.a

MY_SOURCES = ft_printf.c \
		tools_one.c \
		tools_two.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

all: $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C libft

$(NAME): $(LIBFT_LIB) $(MY_OBJECTS)
	@cp $(LIBFT_LIB) $(NAME)
	@ar rc $(NAME) $(MY_OBJECTS)
	@ranlib $(NAME)
	@echo "$(NAME) compiled."

%.o :%.c
	@cc $(CFLAGS) -c $< -o $@ 
	@echo "$< compiled."

clean:
	@$(RM) $(MY_OBJECTS) $(MY_OBJECTS_BONUS)
	@$(MAKE) -C libft clean
	@echo "Objects files removed."

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C libft fclean
	@echo "$(NAME) removed."

re: fclean all

.PHONY: all clean fclean re 
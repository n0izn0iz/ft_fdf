NAME=fdf
SRCS=$(wildcard srcs/*.c)
OBJS=$(patsubst srcs/%.c, objs/%.o, $(SRCS))
LIBFT=libft/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) re -C libft

$(NAME): $(OBJS) $(LIBFT)
	gcc -o $@ $^ -L/usr/X11/lib -lmlx -lXext -lX11

objs/%.o: srcs/%.c
	gcc -c $^ -o $@ -Wall -Wextra -Werror -Ilibft/includes -Iincludes

clean:
	rm -f $(OBJS) $(LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean

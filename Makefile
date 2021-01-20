GCC = gcc -Wall -Wextra -Werror -g -MMD
NAME = cub3D
SRCS = $(shell find ./files -name "*.c")
OBJS = $(SRCS:.c=.o)
HEAD = -I ./libs/minilibx_macos/

MAKE_LIBS = ./libs/libft/libft.a ./libs/minilibx_macos/libmlx.a
LIB := -L libs/libft -lft -L libs/minilibx_macos -lmlx -framework OpenGL -framework Appkit
DLIBMLX = libmlx.dylib

.PHONY: clean fclean re
all: $(NAME)

files/%.o: %.c
	$(GCC) $(HEAD) $< 

$(MAKE_LIBS):
	make -s -C ./libs/libft
	make -s -C ./libs/minilibx_macos
	cp ./libs/minilibx_macos/libmlx.dylib .

$(NAME): $(MAKE_LIBS) $(TEMPS) $(OBJS)
	$(GCC) $(OBJS) $(LIB) $(HEAD) -o $(NAME)

lldb:
	gcc -g3 $(SRCS) $(LIB) $(HEAD) -o $(NAME)

clean:
	$(shell find ./files/ -name "*.o" -delete)
	make -C ./libs/libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libs/libft fclean
	make -C ./libs/minilibx_macos clean
	rm -rf libmlx.dylib

re: fclean all
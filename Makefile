GCC = gcc -Wall -Wextra -Werror -g -MMD
NAME = cub3D
SRCS = $(shell find ./files -name "*.c")
OBJS = $(SRCS:.c=.o)
DEPENDS = ${OBJS:.o=.d}
HEAD = -I .

ifeq ($(OS),Windows_NT)
	detected_OS := Windows
else
	detected_OS := $(shell uname)
endif
ifeq ($(detected_OS),Linux)
	MAKES := ./libs/libft/libft.a ./libs/minilibx/libmlx.a
	LIBMAKE := libs/minilibx
	LIB := -L libs/libft -lft -L libs/minilibx -lmlx_Linux -lXext -lX11 -lm
	HEAD += -I./libs/minilibx/
endif
ifeq ($(detected_OS),Darwin)
	MAKES = ./libs/libft/libft.a ./libs/minilibx_macos/libmlx.a
	LIBMAKE := ./libs/minilibx_macos
	LIB := -L libs/libft -lft -L libs/minilibx_macos -lmlx -framework OpenGL -framework Appkit
	HEAD += -I./libs/minilibx_macos/
	DLIBMLX = libmlx.dylib
endif


.PHONY: clean fclean re
all: $(NAME)

files/%.o: %.c
	$(GCC) -c $(HEAD) $< 

$(MAKES):
	make -C ./libs/libft
	make -sC $(LIBMAKE)
	cp ./libs/minilibx_macos/$(DLIBMLX) .

-include ${DEPENDS}

$(NAME): $(MAKES) $(TEMPS) $(OBJS)
	$(GCC) $(OBJS) $(LIB) $(HEAD) -o $(NAME)

lldb:
	gcc -g3 $(SRCS) $(LIB) $(HEAD) -o $(NAME)

clean:
	$(shell find . -name "*.o" -delete)
	rm -f *.d
	make -C ./libs/libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libs/libft fclean
	make -C $(LIBMAKE) clean

re: fclean all
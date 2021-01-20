GCC = gcc -Wall -Wextra -Werror -w
NAME = cub3D
SRCS = $(shell find ./files -name "*.c")
OBJS = $(SRCS:.c=.o)
HEAD = -I ./libs/minilibx_macos/ -s
MAKE_LIBS = ./libs/libft/libft.a ./libs/minilibx_macos/libmlx.a
LIB := -L libs/libft -lft -L libs/minilibx_macos -lmlx -framework OpenGL -framework Appkit -lz
DLIBMLX = libmlx.dylib


CLS = clear
Yellow = \033[0;33m
Green = \033[32;1m
End = \033[0m

.PHONY: clean fclean re

all:
	make -s $(NAME)

files/%.o: %.c
	$(GCC) $(HEAD) $< 

$(MAKE_LIBS):
	$(CLS)
	@echo "${Yellow}Compiling LIBFT...${End}"
	make -s -C ./libs/libft
	$(CLS)
	@echo "${Yellow}Compiling LIBFT...${End}"
	@echo "${Green}LIBFT Compiled!\n${End}"
	@echo "${Yellow}Compiling MINILIBX...${End}"
	make -s -C ./libs/minilibx_macos
	@echo "${Green}MINILIBX Compiled!\n${End}"
	@echo "${Yellow}Compiling CUB3D files...${End}"
	cp ./libs/minilibx_macos/libmlx.dylib .


$(NAME): $(MAKE_LIBS) $(TEMPS) $(OBJS)
	$(GCC) $(OBJS) $(LIB) $(HEAD) -o $(NAME)
	@echo "${Green}\nCUB3D WAS COMPILED SUCCESSFULLY!\n${End}"

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
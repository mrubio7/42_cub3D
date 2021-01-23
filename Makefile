GCC = gcc -Wall -Wextra -Werror
NAME = cub3D
SRCS = $(shell find ./files -name "*.c")
OBJS = $(SRCS:.c=.o)
HEAD = -I ./libs/minilibx_macos/
MAKE_LIBS = ./libs/libft/libft.a ./libs/minilibx_macos/libmlx.a
LIB := -L libs/libft -lft -L libs/minilibx_macos -lmlx -framework OpenGL -framework Appkit -lz
DLIBMLX = libmlx.dylib

################## COLORS & UTILS
CLS = clear
YB = \033[33;1m
Y = \033[0;33m
GB= \033[32;1m
G = \033[0;32m
RB = \033[31;1m
R = \033[0;31m
PB = \033[35;1m
P = \033[0;35m
BKB = \033[30;1m
BK = \033[0;30m
End = \033[0m
##################

.PHONY: clean fclean re

all:
	make -s $(NAME)

start:
	make -s $(NAME)
	$(CLS)
	@echo "${GB}STARTING THE GAME!!\n${End}"
	@echo "${YB}  W ${Y} Move Forward${End}"
	@echo "${YB}  S ${Y} Move Backward${End}"
	@echo "${YB}  A ${Y} Turn Left${End}"
	@echo "${YB}  D ${Y} Turn Right\n${End}"
	@echo "${YB}ESC ${Y} Close game${End}"
	./cub3D

files/%.o: %.c
	$(GCC) --silent $(HEAD) $< 

$(MAKE_LIBS):
	$(CLS)
	@echo "${Y}Compiling LIBFT...${End}"
	make -s -C ./libs/libft
	@echo "${G}LIBFT Compiled!\n${End}"
	@echo "${Y}Compiling MINILIBX...${End}"
	make -s -C ./libs/minilibx_macos
	@echo "${G}MINILIBX Compiled!\n${End}"
	@echo "${Y}Compiling CUB3D files...${End}"
	cp ./libs/minilibx_macos/libmlx.dylib .

$(NAME): $(MAKE_LIBS) $(OBJS)
	$(GCC) $(OBJS) $(LIB) $(HEAD) -o $(NAME)
	@echo "${G}CUB3D WAS COMPILED SUCCESSFULLY!\n${End}"

debug: $(MAKE_LIBS) $(OBJS)
	$(GCC) $(OBJS) $(LIB) -fsanitize=address $(HEAD) -o $(NAME)
	$(CLS)
	@echo "${B}Sanitize activated!\n${End}"

lldb:
	gcc -g3 $(SRCS) $(LIB) $(HEAD) -o $(NAME)

clean:
	$(shell find ./files/ -name "*.o" -delete)
	make -C ./libs/libft clean
	$(CLS)
	@echo "${PB}CLEAN!${End}"

fclean: clean
	rm -f $(NAME)
	make -C ./libs/libft fclean
	make -C ./libs/minilibx_macos clean
	rm -rf libmlx.dylib
	rm -rf cub3D.dSYM
	$(CLS)
	@echo "${PB}TOTALY CLEAN!${End}"

re: fclean all
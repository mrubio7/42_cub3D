GCC = gcc -Wall -Wextra -Werror
NAME = cub3D
HEAD = -I ./libs/minilibx_macos/
MAKE_LIBS = ./libs/libft/libft.a ./libs/minilibx_macos/libmlx.a
LIB := -L libs/libft -lft -L libs/minilibx_macos -lmlx -framework OpenGL -framework Appkit -lz
DLIBMLX = libmlx.dylib

SRCS =	./files/GNL/get_next_line.c \
		./files/printf/ft_printf.c \
		./files/printf/src/ft_info_flags.c \
		./files/printf/src/ft_put_flag_hex.c \
		./files/printf/src/ft_printf_utils.c \
		./files/printf/src/ft_putnbr.c \
		./files/printf/src/ft_put_flag_str.c \
		./files/printf/src/ft_put_flag_mem.c \
		./files/printf/src/ft_putnbr_abs.c \
		./files/printf/src/ft_putchar.c \
		./files/printf/src/ft_puthex.c \
		./files/printf/src/ft_check_arg.c \
		./files/printf/src/ft_put_flag_nbr.c \
		./files/printf/src/ft_putstr.c \
		./files/printf/src/ft_put_flag_char.c \
		./files/printf/src/ft_putmem.c \
		./files/ManageMap/management_dotcub_path.c \
		./files/ManageMap/management_dotcub.c \
		./files/ManageMap/read_dotcub.c \
		./files/ManageMap/management_dotcub_errors.c \
		./files/ManageMap/management_dotcub_map.c \
		./files/ManageMap/management_dotcub_color.c \
		./files/ManageMap/management_dotcub_closedmap.c \
		./files/ManageMap/management_dotcub_res.c \
		./files/Game/init_game.c \
		./files/Game/texture_read.c \
		./files/Game/sprites.c \
		./files/Game/init_sprites.c \
		./files/Game/pj_position.c \
		./files/Game/game_loop_frame.c \
		./files/Game/pj_movement.c \
		./files/Game/game_vert_line.c \
		./files/Game/print_pixels.c \
		./files/Game/texture_wall.c \
		./files/main.c
OBJS = $(SRCS:.c=.o)

SRCS_BONUS =	./files/Bonus/pj_movement_bonus.c \
				
OBJS_BONUS = $(SRCS_BONUS:.c=.o)


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
	./cub3D map.cub

files/%.o: %.c
	$(GCC) $(HEAD) $< 

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

bonus: $(NAME)
	@echo "${Y}Loading BONUS files...${End}"
	rm -rf ./files/game/pj_movement.o
	$(OBJS_BONUS)
	@echo "${G}BONUS FILES WAS LOADED SUCCESSFULLY!\n${End}"


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
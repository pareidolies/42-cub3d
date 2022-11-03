SRCS		=	main.c \
				parsing/check_file.c \
				utils/get_next_line.c \
				utils/get_next_line_utils.c \
				parsing/struct_utils.c \
				parsing/check_file_utils.c \
				parsing/check_file_utils_bis.c \
				parsing/check_rgb.c \
				parsing/check_rgb_bis.c \
				parsing/struct_map_utils.c \
				parsing/parsing_map.c \
				parsing/parsing_map_utils.c \
				parsing/map_file_to_array.c \
				parsing/check_map.c \
				parsing/check_map_utils.c \
				utils/mlx_utils.c \
				raycasting/raycasting.c \
				raycasting/computation.c \
				raycasting/data.c \
				raycasting/initialize.c \
				raycasting/printer.c \
				raycasting/start.c \
				raycasting/textures.c \
				hooks/exit.c \
				hooks/keys.c \
				hooks/keys_bis.c \
				hooks/move.c \
				hooks/rotate.c \

SRCS_BONUS		=	main.c \
				parsing/check_file.c \
				utils/get_next_line.c \
				utils/get_next_line_utils.c \
				parsing/struct_utils.c \
				parsing/check_doors.c \
				parsing/check_file_utils.c \
				parsing/check_file_utils_bis.c \
				parsing/check_rgb.c \
				parsing/check_rgb_bis.c \
				parsing/struct_map_utils.c \
				parsing/parsing_map.c \
				parsing/parsing_map_utils.c \
				parsing/map_file_to_array.c \
				parsing/check_map.c \
				parsing/check_map_utils.c \
				utils/mlx_utils.c \
				raycasting/raycasting.c \
				raycasting/computation.c \
				raycasting/lists.c \
				features/minimap.c \
				features/minimap_utils.c \
				raycasting/data.c \
				raycasting/initialize.c \
				raycasting/printer.c \
				raycasting/start.c \
				raycasting/sprites.c \
				features/menu.c \
				features/menu_utils.c \
				features/init_menu.c \
				raycasting/textures.c \
				raycasting/doors.c \
				raycasting/floor.c \
				raycasting/sort.c \
				hooks/exit.c \
				hooks/keys.c \
				hooks/keys_bis.c \
				hooks/move.c \
				hooks/move_bis.c \
				hooks/rotate.c \
				hooks/free_imgs.c \

SRCS_DIR	= srcs

BONUS_DIR	= srcs_bonus

OBJS_DIR	= objs

OBJS_B_DIR	= objs_bonus

INC_DIR		= includes

SRCS_PATH 	= ${addprefix ${SRCS_DIR}/, ${SRCS}}

SRCS_B_PATH = ${addprefix ${BONUS_DIR}/, ${SRCS_BONUS}}

OBJS		= ${SRCS_PATH:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}

OBJS_BONUS	= ${SRCS_B_PATH:${BONUS_DIR}/%.c=${OBJS_B_DIR}/%.o}

DEPS		= ${SRCS_PATH:${SRCS_DIR}/%.c=${OBJS_DIR}/%.d}

DEPS_B		= ${SRCS_B_PATH:${BONUS_DIR}/%.c=${OBJS_B_DIR}/%.d}

PATH_LIBFT	= -C libft -s --no-print-directory

PATH_MLX	= -C mlx_linux -s --no-print-directory

LIBRARY		= ./libft/libft.a ./mlx_linux/libmlx.a

NAME		= cub3D

NAME_BONUS	= cub3D_bonus

RM		= rm -Rf

CC		= cc -I $(INC_DIR) -MMD

CFLAGS	= -Wall -Wextra -Werror

LIBFLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

${OBJS_DIR}/%.o : ${SRCS_DIR}/%.c
		@[ ! -d ${OBJS_DIR} ] && mkdir -p  ${OBJS_DIR} || true
		@[ ! -d ${OBJS_DIR}/hooks/ ] && mkdir -p  ${OBJS_DIR}/hooks/ || true
		@[ ! -d ${OBJS_DIR}/raycasting/ ] && mkdir -p  ${OBJS_DIR}/raycasting/ || true
		@[ ! -d ${OBJS_DIR}/parsing/ ] && mkdir -p  ${OBJS_DIR}/parsing/ || true
		@[ ! -d ${OBJS_DIR}/utils/ ] && mkdir -p  ${OBJS_DIR}/utils/ || true
		@$(CC) ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

${OBJS_B_DIR}/%.o : ${BONUS_DIR}/%.c
		@[ ! -d ${OBJS_B_DIR} ] && mkdir -p  ${OBJS_B_DIR} || true
		@[ ! -d ${OBJS_B_DIR}/hooks/ ] && mkdir -p  ${OBJS_B_DIR}/hooks/ || true
		@[ ! -d ${OBJS_B_DIR}/raycasting/ ] && mkdir -p  ${OBJS_B_DIR}/raycasting/ || true
		@[ ! -d ${OBJS_B_DIR}/parsing/ ] && mkdir -p  ${OBJS_B_DIR}/parsing/ || true
		@[ ! -d ${OBJS_B_DIR}/utils/ ] && mkdir -p  ${OBJS_B_DIR}/utils/ || true
		@[ ! -d ${OBJS_B_DIR}/features/ ] && mkdir -p  ${OBJS_B_DIR}/features/ || true
		@$(CC) ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

all:		$(NAME)

./libft/libft.a :
	@echo " [..] | compiling libft..."
	make -C ./libft
	@echo "\033[93m [OK] | libft\033[0m"

./mlx_linux/libmlx.a :
	@echo " [..] | compiling mlx..."
	make -C ./mlx_linux 
	@echo "\033[93m [OK] | mlx\033[0m"

$(NAME): $(LIBRARY) $(OBJS)
		@echo " [..] | created object files."
		${CC} ${CFLAGS} ${OBJS} ${LIBRARY} -o ${NAME} ${LIBFLAGS}
		@echo "\033[92m cub3D is ready\033[0m"

$(NAME_BONUS): $(LIBRARY) $(OBJS_BONUS)
		@echo " [..] | created object files."
		${CC} ${CFLAGS} ${OBJS_BONUS} ${LIBRARY} -o ${NAME_BONUS} ${LIBFLAGS}
		@echo "\033[92m cub3D is ready\033[0m"

clean:
		$(MAKE) clean $(PATH_LIBFT)
		$(MAKE) clean $(PATH_MLX)
		${RM} ${OBJS} ${OBJS_DIR} ${DEPS} ${OBJS_BONUS} ${OBJS_B_DIR} ${DEPS_B}
		@echo "\033[93m [OK] | clean.\033[0m"

fclean:		clean
		$(MAKE) fclean $(PATH_LIBFT)
		${RM} ${NAME} ${NAME_BONUS}
		@echo "\033[93m [OK] | fclean.\033[0m"

re:		fclean ${NAME}

bonus:	$(NAME_BONUS)

norm:		
		norminette ./libft ./srcs ./srcs_bonus ./includes

-include $(DEPS) $(DEPS_B)

.PHONY:		all clean fclean re

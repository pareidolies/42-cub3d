SRCS		=	main.c check_file.c get_next_line.c get_next_line_utils.c \
				struct_utils.c check_file_utils.c check_file_utils_bis.c \
				check_rgb.c check_rgb_bis.c struct_map_utils.c parsing_map.c \
				map_file_to_array.c check_map.c check_map_utils.c raycasting.c mlx_utils.c \
				move_and_rotate.c

SRCS_DIR	= ./srcs/

BONUS_DIR	= ./srcs_bonus/

INC_DIR		= includes

SRCS_PATH	= $(SRCS:%=$(SRCS_DIR)%)

SRCS_B_PATH = $(SRCS:%=$(BONUS_DIR)%)

OBJS		= $(SRCS_PATH:%.c=%.o)

OBJS_BONUS	= $(SRCS_B_PATH:%.c=%.o)

DEPS		= $(SRCS_PATH:%.c=%.d)

PATH_LIBFT	= -C libft -s --no-print-directory

PATH_MLX	= -C mlx_linux -s --no-print-directory

LIBRARY		= ./libft/libft.a ./mlx_linux/libmlx.a

NAME		= cub3D

NAME_BONUS	= cub3D

RM		= rm -f

CC		= cc -I $(INC_DIR) -MMD

CFLAGS	= -Wall -Wextra -Werror -g

LIBFLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

%.o: %.c
	@$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

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

clean:
		$(MAKE) clean $(PATH_LIBFT)
		$(MAKE) clean $(PATH_MLX)
		${RM} ${OBJS} ${DEPS} ${OBJS_BONUS}
		@echo "\033[93m [OK] | clean.\033[0m"

fclean:		clean
		$(MAKE) fclean $(PATH_LIBFT)
		${RM} ${NAME} ${NAME_BONUS}
		@echo "\033[93m [OK] | fclean.\033[0m"

re:		fclean ${NAME}

bonus:		$(LIBRARY) $(OBJS_BONUS)
		$(CC) $(OBJS_BONUS) $(LIBRARY) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz  -o $(NAME_BONUS)

norm:		
		norminette ./libft ./srcs ./srcs_bonus ./includes

-include $(DEPS)

.PHONY:		all clean fclean re

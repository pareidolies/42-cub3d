SRCS		= main.c check_map.c get_next_line.c get_next_line_utils.c

SRCS_DIR	= ./srcs/

BONUS_DIR	= ./srcs_bonus/

SRCS_PATH	= $(SRCS:%=$(SRCS_DIR)%)

SRCS_B_PATH = $(SRCS:%=$(BONUS_DIR)%)

OBJS		= $(SRCS_PATH:%.c=%.o)

OBJS_BONUS	= $(SRCS_B_PATH:%.c=%.o)

PATH_LIBFT	= -C libft --no-print-directory

PATH_MLX	= -C mlx_linux --no-print-directory

LIBRARY		= ./libft/libft.a ./mlx_linux/libmlx.a

NAME		= cub3D

NAME_BONUS	= cub3D

RM		= rm -f

CC		= cc -Wall -Wextra -Werror

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all:		$(NAME)

./libft/libft.a :
	make -C ./libft

./mlx_linux/libmlx.a :
	make -C ./mlx_linux

$(NAME): $(LIBRARY) $(OBJS)
		$(CC) $(OBJS) $(LIBRARY) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz  -o $(NAME)

clean:
		$(MAKE) clean $(PATH_LIBFT)
		$(MAKE) clean $(PATH_MLX)
		${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
		$(MAKE) fclean $(PATH_LIBFT)
		${RM} ${NAME} ${NAME_BONUS}

re:		fclean ${NAME}

bonus:		$(LIBRARY) $(OBJS_BONUS)
		$(CC) $(OBJS_BONUS) $(LIBRARY) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz  -o $(NAME_BONUS)

norm:		
		norminette ./libft ./srcs ./srcs_bonus ./includes

.PHONY:		all clean fclean re

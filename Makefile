
NAME =			Cub3D
CC =			gcc
CFLAGS =		-Wall -Wextra -Werror
LIBFT_DIR =		libft
LIBFT_LIB =		$(LIBFT_DIR)/libft.a
MLX_DIR =		minilibx/mlx_linux
MLX_LIB =		$(MLX_DIR)/libmlx.a
MLX_LINKMAC =		-framework OpenGL -framework AppKit
MLX_LINKLNX =		-lX11 -lXext -lm -lbsd
SRCS =			srcs/main.c \
					srcs/utils/get_next_line.c \
					srcs/utils/ft_iswall.c \
					srcs/utils/ft_issprite.c \
					srcs/utils/ft_iswalkable.c \
					srcs/utils/ft_wallisvalid.c \
					srcs/utils/ft_spriteisvalid.c \
					srcs/utils/ft_lvlinit.c \
					srcs/varinit/varinit.c \
					srcs/varinit/varinit_pars.c \
					srcs/varinit/varinit_maps.c \
					srcs/varinit/varinit_mlx.c \
					srcs/varinit/varinit_tex.c \
					srcs/varinit/varinit_sprt.c \
					srcs/varinit/varinit_win.c \
					srcs/varinit/varinit_coor.c \
					srcs/varinit/varinit_spd.c \
					srcs/varinit/varinit_rayc.c \
					srcs/varinit/varinit_wall.c \
					srcs/varinit/varinit_draw.c \
					srcs/varinit/varinit_keys.c \
					srcs/parsearg/parsearg.c \
					srcs/parsearg/parsearg_fileread.c \
					srcs/parsearg/parsearg_resol.c \
					srcs/parsearg/parsearg_tex.c \
					srcs/parsearg/parsearg_sprt.c \
					srcs/parsearg/parsearg_floor.c \
					srcs/parsearg/parsearg_ceiling.c \
					srcs/parsearg/parsearg_getpath.c \
					srcs/parsearg/parsearg_mapread.c \
					srcs/parsearg/parsearg_mapinit.c \
					srcs/parsearg/parsearg_mapvalinit.c \
					srcs/parsearg/parsearg_mapvalid.c \
					srcs/tabinit/tabinit.c \
					srcs/tabinit/tabinit_gettex.c \
					srcs/tabinit/tabinit_getsprt.c \
					srcs/tabinit/tabinit_distandorder.c \
					srcs/tabinit/tabinit_sprtval.c \
					srcs/tabinit/tabinit_getsprtval.c \
					srcs/rayc/rayc.c \
					srcs/rayc/rayc_ceiling.c \
					srcs/rayc/rayc_floor.c \
					srcs/rayc/rayc_walls.c \
					srcs/rayc/rayc_drawwalls.c \
					srcs/rayc/rayc_sprt.c \
					srcs/keys/keys.c \
					srcs/keys/keys_keypress.c \
					srcs/keys/keys_keyrelease.c \
					srcs/keys/keys_move.c \
					srcs/keys/keys_rotation.c \
					srcs/keys/keys_lvl.c \
					srcs/save/save.c \
					srcs/save/save_writebmp.c \
					srcs/error/error.c \
					srcs/exit/exit.c \
					srcs/exit/free.c \
					srcs/exit/free_pars.c \
					srcs/exit/free_maps.c \
					srcs/exit/free_tex.c \
					srcs/exit/free_sprt.c
OBJS =			$(SRCS:.c=.o)


all:			$(NAME)

$(NAME):		 $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
					$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) $(MLX_LINKLNX) -o $@ 

%.o:			%.c
					$(CC) $(CFLAGS)  -I. -o $@ -c $? 

$(LIBFT_LIB):
					make -C $(LIBFT_DIR)

$(MLX_LIB):
					make -C $(MLX_DIR)

clean:
					rm -f $(OBJS)
					make clean -C $(LIBFT_DIR)
					make clean -C $(MLX_DIR)

fclean:			clean
					rm -f $(NAME)
					make fclean -C $(LIBFT_DIR)
					make fclean -C $(MLX_DIR)

re:				fclean all

.PHONY: all, $(NAME), clean, fclean, re

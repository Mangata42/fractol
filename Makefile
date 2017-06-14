# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/04 17:19:03 by nghaddar          #+#    #+#              #
#    Updated: 2017/06/14 23:14:24 by nghaddar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = fractol.c \
		errors.c \
		env.c \
		draw.c \
		mandelbrot.c \
		julia.c \
		burningship.c \
		hooks.c
SRCS_D = $(addprefix ./srcs/, $(SRCS))
FLAGS = no
COMPIL_LIBS = no
NAME = fractol
LIBFT_DIR = ./libs/libft/
MLX_DIR = ./libs/mlx
LIBS = -framework OpenGL -framework AppKit -L $(LIBFT_DIR) -l ft -L $(MLX_DIR) -l mlx

$(NAME):
ifeq ($(COMPIL_LIBS), yes)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
endif
ifeq ($(FLAGS), yes)
	gcc -Wall -Wextra -Werror $(LIBS) $(SRCS_D) -o $(NAME)
else
	gcc $(LIBS) $(SRCS_D) -o $(NAME)
endif

clean:
	make -C $(LIBFT_DIR) clean

fclean:
ifeq ($(COMPIL_LIBS), yes)
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean
endif
	rm -rf $(NAME)

re: fclean all

all: $(NAME)

.PHONY: clean fclean re

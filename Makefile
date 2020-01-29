# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 14:02:55 by jpoulvel          #+#    #+#              #
#    Updated: 2020/01/29 17:46:06 by aruiz-ba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = srcs/main.c \
		srcs/fdf/parsing.c \
		srcs/fdf/additional_functions.c \
		srcs/fdf/center_map.c \
		srcs/fdf/graphic_init.c \
		srcs/fdf/free_functions.c \
		srcs/fdf/colorize.c \
		srcs/fdf/list_mgmt.c \
		srcs/draw/print_map.c \
		srcs/draw/print_text.c \
		srcs/draw/render.c \
		srcs/event/menu_controls.c \
		srcs/event/mouse_controls.c \
		srcs/event/keys_controls.c \
		srcs/event/change_appearance.c \
		srcs/mapsaving/tools.c \
		srcs/mapsaving/new_wlist.c \
		srcs/mapsaving/wallfunct.c \
		srcs/mapsaving/save_map.c \
		srcs/mapsaving/objfunct.c 

OBJ = $(SRCS:.c=.o)

LIB_DIR = libft

INCL = fdf.h \
	   $(LIB_DIR)/libft.a \
	#   -I./frameworks/SDL2.framework/Versions/A/Headers \
	   -I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
	   -I./frameworks/SDL2_image.framework/Versions/A/Headers \
	   -I./frameworks/SDL2_mixer.framework/Headers \
	   -I./frameworks/SDL2_net.framework/Headers \
	   -F./frameworks

FLAGS = -Wall -Wextra -Werror -I $(INCL)

SDLFLAGS = -lSDL2-2.0.0  -lSDL2_ttf-2.0.0 `sdl2-config --cflags --libs`

FRAMEWORKS = -F./frameworks \
			 -rpath ./frameworks \
			 -framework OpenGL -framework AppKit -framework OpenCl \
			 -framework SDL2 -framework SDL2_ttf -framework SDL2_image \
			 -framework SDL2_mixer -framework SDL2_net

CC = gcc -g

all: Makefile $(NAME)

$(NAME): FORCE LIB $(OBJ)
	@gcc -o $(NAME) $(FLAGS) $(OBJ) $(SDLFLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS) $(SDLFLAGS)
	@echo $<

LIB:
	@$(MAKE) -C $(LIB_DIR)

clean:
	@rm -f $(OBJ)
	@$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C $(LIB_DIR)

re: fclean $(NAME)

san : FORCE LIB $(OBJ)
	@gcc -o $(NAME) -fsanitize=address $(FLAGS) $(OBJ) $(SDLFLAGS)

FORCE:

.PHONY: all clean fclean re FORCE

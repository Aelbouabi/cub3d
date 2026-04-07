NAME = cub3D

B_NAME = cub3D_bonus

CC = cc 

FLAGS = -Wall -Wextra -Werror -Imlx 

SRC = ./utils/get_next_line.c ./utils/get_next_line_utils.c ./utils/ft_atoi.c\
		./utils/ft_strncmp.c ./utils/ft_strcmp.c ./utils/ft_strtrim.c ./utils/ft_split.c\
		./mandatory/draw.c ./mandatory/cub3D.c ./mandatory/map_parc.c \
		./mandatory/main.c ./mandatory/utils1.c ./mandatory/utils2.c\
		./mandatory/utils3.c ./mandatory/utils4.c ./mandatory/utils5.c\
		./mandatory/utils6.c ./mandatory/parsing1.c 

B_SRC = ./utils/get_next_line.c ./utils/get_next_line_utils.c ./utils/ft_strtrim.c\
		./utils/ft_strncmp.c ./utils/ft_strcmp.c ./utils/ft_atoi.c ./utils/ft_split.c\
		./bonus/draw_bonus.c  ./bonus/map_parc_bonus.c ./bonus/cub3D_bonus.c\
		./bonus/main_bonus.c ./bonus/utils1_bonus.c ./bonus/utils2_bonus.c\
		./bonus/utils3_bonus.c ./bonus/utils4_bonus.c ./bonus/utils5_bonus.c\
		./bonus/utils6_bonus.c ./bonus/parsing1_bonus.c  ./bonus/mini_map_bonus.c \
		./bonus/texture_bonus.c

OBJ = $(SRC:.c=.o)

B_OBJ = $(B_SRC:.c=.o)

INCLUDE1 = cub3D.h

INCLUDE2 = ./MLX42/MLX42.h

MLX42 = ./MLX42/libmlx42.a

all: $(NAME)

bonus: $(B_NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(MLX42)  -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit -o $@

$(B_NAME): $(B_OBJ)
	$(CC) $(FLAGS) $(B_OBJ) $(MLX42)  -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit -o $@

%.o: %.c $(INCLUDE1) 
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(B_OBJ)

fclean: clean
	rm -rf $(NAME) $(B_NAME)

re: fclean all

.PHONY: clean
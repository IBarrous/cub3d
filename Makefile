MAIN =main.c set_direction.c utils.c ft_split.c ft_itoa.c \
		Libft.c keys.c raycasting.c _3d_drawing.c movements_2.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		parsing/check_colors.c parsing/check_textures.c parsing/errors.c parsing/parse_map.c \
		parsing/parse_map2.c parsing/parse_map3.c parsing/parsing_utils.c parsing/parsing_utils2.c \
		parsing/utils_functions.c parsing/utils_functions2.c  parsing/for_textures.c utils2.c \
		parsing/check_colors2.c parsing/parse_map4.c
OBJS = ${MAIN:.c=.o}
FLAGS= -Wall -Wextra -Werror -fsanitize=address
NAME=cub3d


all: ${NAME}

$(NAME): ${OBJS}
	cc ${FLAGS} $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
.c.o:
	cc ${FLAGS} -c $< -o ${<:.c=.o}

clean:
	rm -f ${OBJS} ${COMMON_OBJS}

fclean: clean
	rm -f ${NAME} ${NAME_BONUS}

re: fclean all
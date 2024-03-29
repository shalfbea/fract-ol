NAME := fractol

HEADER := include/fractol.h

CC := clang

TestingFlags := -fsanitize=address -g3

FLAGS := -Wall -Wextra -Werror -Imlx -I./include -g3

SRC_FILES = src/main.c src/fractals.c src/controls.c \
			src/render.c src/inputs.c src/ft_strings.c

OBJ = $(patsubst %.c, %.o, $(SRC_FILES))

RM := rm -rf

all: $(HEADER) $(NAME) $(OBJ) $(LIBMLX)

$(NAME): $(OBJ) $(HEADER) libmlx.a
	$(CC) $(OBJ) -framework OpenGL -framework AppKit libmlx.a -o $(NAME)
#$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit libftprintf.a libmlx.a -o $(NAME)

bonus : $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

testing : test

libmlx.a :
	make -C $(LIBMLX)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm: $(SRC_FILES)
	norminette $<

.PHONY: all clean fclean re norm bonus

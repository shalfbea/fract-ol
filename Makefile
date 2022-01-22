NAME := fractol

HEADER := include/fractol.h

CC := clang

TestingFlags := -fsanitize=address -g3

FLAGS := -Wall -Wextra -Werror -Imlx -I./include -g3

SRC_FILES = src/main.c src/mandelbrot.c src/controls.c \

OBJ = $(patsubst %.c, %.o, $(SRC_FILES))

RM := rm -rf

all: $(HEADER) $(NAME) $(OBJ)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit libftprintf.a -o $(NAME)

bonus : $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

testing : test

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm: $(SRC_FILES)
	norminette $<

.PHONY: all clean fclean re norm bonus
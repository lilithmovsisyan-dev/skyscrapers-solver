NAME = rush-01
CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Iinclude
SRC = src/main.c src/board.c src/input.c src/solve.c \
      src/visibility.c src/check_sides.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

src/%.o: src/%.c include/rush01.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

test: $(NAME)
	python3 tests/test_solver.py ./$(NAME)

.PHONY: all clean fclean re test

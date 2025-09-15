SRC = main.c utils.c views.c game.c utils_print.c views_check.c

all:
	cc -Wall -Wextra -Werror -o skyscraper $(SRC)

fclean:
	rm -f skyscraper

run: all
	./skyscraper "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"

val: all
	valgrind --leak-check=full --track-origins=yes ./skyscraper "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
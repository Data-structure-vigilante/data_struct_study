SRC = main.c \
		selection_sort.c \
		bubble_sort.c \
		insertion_sort.c \
		shell_sort.c

all: ${SRC}
	gcc -g3 -fsanitize=address ${SRC} -o main
	./main

debug: ${SRC}
	gcc -g3 -fsanitize=address ${SRC} -o main

leak:
	gcc *.c
	leaks -atExit -- ./a.out
	rm -rf a.out.dSYM
	rm a.out

.PHONY: test debug
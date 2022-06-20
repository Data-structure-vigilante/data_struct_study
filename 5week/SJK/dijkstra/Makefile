SRC = main.c \
 			../arrayGraph/arraygraph.c \
			 dijkstra.c \

all: ${SRC}
	gcc -g3 -fsanitize=address ${SRC} -o main
	./main

debug: ${SRC}
	gcc -g3 -fsanitize=address ${SRC} -o main

leak:
	gcc ${SRC} -o main
	leaks -atExit -- ./main
	rm -rf main.dSYM
	rm main

.PHONY: test debug
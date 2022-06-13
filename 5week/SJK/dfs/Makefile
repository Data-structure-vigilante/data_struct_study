SRC = main.c \
			dfs.c \
			../../../2week/SH/arrayStack/arraystack.c \
 			../linkedGraph/linkedlistgraph.c \
			../linkedGraph/graphlinkedlist.c

all: ${SRC}
	gcc -g3 -fsanitize=address ${SRC} -o main
	./main

leak:
	gcc *.c
	leaks -atExit -- ./a.out
	rm -rf a.out.dSYM
	rm a.out

.PHONY: test
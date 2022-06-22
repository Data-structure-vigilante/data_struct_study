SRC = main.c \
			bfs.c \
			../../../3week/HJ/Queue/arrayqueue.c \
 			../linkedGraph/linkedlistgraph.c \
			../linkedGraph/graphlinkedlist.c

all: ${SRC}
	gcc -g3 -fsanitize=address ${SRC} -o main
	./main
  
clear :
	rm main
	rm -r main.dSYM
  
leak:
	gcc *.c
	leaks -atExit -- ./a.out
	rm -rf a.out.dSYM
	rm a.out

.PHONY: test
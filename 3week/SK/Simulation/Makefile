SRC= main.c \
	linkeddeque.c \
	simlinkedqueue.c \
	simutils.c

all : ${SRC}
	gcc ${SRC} -o main

run : all
	./main
	rm main

PHONEY: all run
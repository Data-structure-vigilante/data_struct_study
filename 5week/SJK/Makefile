test:
	gcc -g3 -fsanitize=address *.c
	./a.out
	rm -rf a.out.dSYM
	rm a.out
.PHONY: test
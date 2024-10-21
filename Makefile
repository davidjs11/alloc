all:
	@gcc -g -o main main.c alloc.c -I. -ansi -Wall

.PHONY: clean
clean:
	@rm -rf main

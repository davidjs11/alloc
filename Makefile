all:
	@mkdir -p bin
	@gcc -g -o bin/main main.c alloc.c -I. -ansi -Wall

.PHONY: clean
clean:
	@rm -rf bin

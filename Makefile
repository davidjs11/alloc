all:
	@mkdir -p bin
	@gcc -g -o bin/main main.c alloc.c -I. -Wall

.PHONY: clean
clean:
	@rm -rf bin

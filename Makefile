all:learn

learn: learn.c
	gcc -Wall -Werror -fsanitize=address -std=c99 -o learn learn.c 
 
clean:
	rm -f learn

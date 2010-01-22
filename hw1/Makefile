# Makefile for Count

# Standard compiler options
CFLAGS = -g3 -std=c99 -pedantic -Wall

# Rule to create Count from Count.o
Count:  count.c
	${CC} ${CFLAGS} $^ -o $@

# Rule to create count.c (implicit, and thus omitted)

# Rule to remove executable and object files
# clean:  Count Count.o
#	/bin/rm -f $^


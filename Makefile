CFLAGS = -Wall -Wextra -Werror -g 
ASAN = -fsanitize=address,undefined
EXEC = lab1 debug
SRCS = $(shell find . -type f -name '*.c' -print)
HEADERS = $(shell find . -type f -name '*.h' -print)
STATIC = --analyze -Xanalyzer -analyzer-output=html
 
CC = clang

lab1: matrix.o main.o
	${CC} ${ASAN} *.o -o $@

matrix.o: matrix.c matrix.h 
	${CC} ${CFLAGS} ${ASAN} -c matrix.c -o $@

main.o : main.c 
	${CC} ${CFLAGS} ${ASAN} -c main.c -o $@

debug: $(SRCS) $(HEADERS) 
	${CC} ${CFLAGS} -c matrix.c -o matrix.o
	${CC} ${CFLAGS} -c main.c -o main.o
	${CC} *.o -o $@

.PHONY : lab1 clean static debug

static:
	${CC} lib/lists.c ${STATIC} -o lists
	${CC} main.c ${STATIC} -o main

clean: 
	rm -rf ${EXEC}
	rm -rf *.o

# FILE: Makefile
# LICENSE: GPL 2.0 JKK Consulting 2019
#
#
CFLAGS= -Wall -pedantic -std=c11
CC= gcc
LIBS= -lm
SRC = Makefile CHANGELOG README cunit.h ex_cunit.c cunit.txt

run: ex_cunit
	./ex_cunit
	
ex_cunit: ex_cunit.c cunit.h 
	${CC} -o ex_cunit ex_cunit.c

cunit.tar: ${SRC}
	tar cvf cunit.tar ${SRC}

clean:
	-rm -f  ex_cunit cunit.tar

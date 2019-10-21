# FILE: Makefile
# LICENSE: GPL 2.0 JKK Consulting 2019
#
# demonstration unit testing for a quadratic equation solver
#   qsolve_roots.h     - The prototypes for qsolve_roots 
#   qsolve_roots.c     - solver function qsolve_roots()
# See README for details on these and planned unit tests for qsolve_roots()`
# t1     == simple exact tests
# t2                - unit tests for qsolve(), monkey tests
# Add these too
# t3                - unit tests for qsolve(), boundry tests
# t4                - unit tests for qsolve(), illconditionsd system tests
# t5                - unit tests for qsolve(), \IE non-numneric testsj
# 
# rstat             - target for getting the size (test and static) for qsolve
# rtest             - target for getting a time on 100000 calls to qsolve.
# 
# Could also add:
#            test for run time space (memory leaks etc...)
#            logging of successful runs, space, and time
#            profiling and coverage testing using gprof (
#            over all error report.

CFLAGS= -Wall -pedantic -std=c11
CC= gcc
LIBS= -lm
# Path to cunit.h
IDIR= ../cunit
SRC = Makefile CHANGELOG README qsolve_roots.c qsolve_roots.h \
  t0.c t1.c t2.c tmonkey.c test_discriminant.c

utest: t1 t2 tmonkey
	./t1
	./t2
	./tmonkey

dtest: test_discriminant 
	./test_discriminant 

t1: t1.o qsolve_roots.o 
	${CC} -o t1 t1.o qsolve_roots.o ${LIBS}

t2: t2.o qsolve_roots.o 
	${CC} -o t2 t2.o qsolve_roots.o ${LIBS}

tmonkey: tmonkey.o qsolve_roots.o 
	${CC} -o tmonkey tmonkey.o qsolve_roots.o ${LIBS}

test_discriminant: test_discriminant.o qsolve_roots.o
	${CC} -o test_discriminant test_discriminant.o qsolve_roots.o ${LIBS}

# Dependencies based on included header files. 
# These could all be automatically generated
# Note the make builtin suffix rules provide a rule 
#     for .o files from .c files
#   ${CC} ${CFLAGS} -c <name>.c

# t1.o: cunit.h qsolve_roots.h 
t1.o: t1.c  qsolve_roots.h 
	${CC} -I${IDIR} ${CFLAGS} -c t1.c

t2.o: t2.c  qsolve_roots.h 
	${CC} -I${IDIR} ${CFLAGS} -c t2.c

tmonkey.o: tmonkey.c  qsolve_roots.h 
	${CC} -I${IDIR} ${CFLAGS} -c tmonkey.c

test_discriminant.o: test_discriminant.c  qsolve_roots.h 
	${CC} -I${IDIR} ${CFLAGS} -c test_discriminant.c

# qsolve_roots.o: qsolve_roots.h
qsolve_roots.o: qsolve_roots.c qsolve_roots.h
	${CC} ${CFLAGS} -c qsolve_roots.c

cuqsolve_roots.tar: ${SRC}
	tar cvf cuqsolve_roots.tar ${SRC}

clean:
	-rm -f ${EXES} core *.log *.o t1  *.tar

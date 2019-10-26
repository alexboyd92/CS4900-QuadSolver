# makefile 
# John Kapenga, Fa 2018
# demonstration unit testing for a quadratic equation solver
#   qsolve_roots.h     - The prototypes for qsolve_roots 
#   qsolve_roots.c     - solver function qsolve_roots()
# t1                - unit tests for qsolve(), uses math library sqrt() 
# Add these too
# t3                - unit tests for qsolve(), monkey tests
# t4                - unit tests for qsolve(), boundry tests
# t5                - unit tests for qsolve(), illconditionsd system tests
# t5                - unit tests for qsolve(), \IE non-numneric testsj
# 
# rstat             - target for getting the size (test and static) for qsolve
# rtest             - target for getting a time on 100000 calls to qsolve.
#
# Could also add:
#            test for run time space (memory leaks etc...)
#            logging of sucessful runs, space, and time
#            profiling and coverage testing using gprof (
#            over all error report.

CFLAGS= -Wall -pedantic -std=c11
CC= gcc
LIBS= -lm
SRC = Makefile cunit.h qsolve_roots.c qsolve_roots.h \
  t1.c 

utest: t1
	./t1

t1: t1.o qsolve_roots.o 
	${CC} -o t1 t1.o qsolve_roots.o ${LIBS}

# Dependencies based on included header files. 
# These could all be automatically generated
# Note the make builtin suffix rules provide a rule 
#     for .o files from .c files
#   ${CC} ${CFLAGS} -c <name>.c

# t1.o: cunit.h qsolve_roots.h 
t1.o: t1.c cunit.h qsolve_roots.h 
	${CC} ${CFLAGS} -c t1.c

# qsolve_roots.o: qsolve_roots.h
qsolve_roots.o: qsolve_roots.c qsolve_roots.h
	${CC} ${CFLAGS} -c qsolve_roots.c

cunit.tar: ${SRC}
	tar cvf cunit.tar ${SRC}

clean:
	-rm -f ${EXES} core *.log *.o t1  *.tar

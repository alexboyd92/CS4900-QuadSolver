CC =gcc
CFLAGS = -ggdb -Wall -pedantic -std=gnu11 -lm
setIt: setIt.o
setIt.o: setIt.h
test: setItTest
	./setItTest
setItTest: setIt.o
clean:
	rm -f *.o setItTest setIt core

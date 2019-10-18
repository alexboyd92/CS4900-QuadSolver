CC =gcc
CFLAGS = -ggdb -Wall -pedantic -std=gnu11
testAll: setItTest
	./setItTest
setItTest: ../setIt/setIt.o
testSetit: setItTest
	./setItTest
clean:
	rm -f *.o setItTest

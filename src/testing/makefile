CC =gcc
CFLAGS = -ggdb -Wall -pedantic -std=gnu11
testAll: setItTest
	./setItTest
setItTest: ../setIt/setIt.o
testSetit: setItTest
	./setItTest

buffersizecheck: ../getIt/getit.h

bufferTest: buffersizecheck
	./buffersizecheck


clean:
	rm -f *.o setItTest

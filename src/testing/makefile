CC =gcc
CFLAGS = -ggdb -Wall -pedantic -std=gnu11
testAll: setItTest buffersizecheck
	./setItTest ./buffersizecheck
setItTest: ../setIt/setIt.o
testSetit: setItTest
	./setItTest
buffersizecheck: ../getIt/getit.h

bufferTest: buffersizecheck
	./buffersizecheck



validateTest:../validate/validate.o


testValidate: validateTest
	./validateTest


clean:
	rm -f *.o setItTest

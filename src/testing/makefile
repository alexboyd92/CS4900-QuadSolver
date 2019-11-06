CC =gcc
CFLAGS = -ggdb -Wall -pedantic -std=gnu11
testAll: setItTest buffersizecheck bufferTest solveTest validateTest
	./setItTest ./buffersizecheck ./bufferTest ./solveTest ./validateTest
setItTest: ../setIt/setIt.o
testSetit: setItTest
	./setItTest
buffersizecheck: ../getIt/getit.h

bufferTest: buffersizecheck
	./buffersizecheck



validateTest:../validate/validate.o


testValidate: validateTest
	./validateTest




solveTest: ../solveIt/solveIt.o -lm

testSolve: solveTest
	./solveTest

clean:
	rm -f *.o setItTest validateTest bufferTest buffersizecheck solveTest 

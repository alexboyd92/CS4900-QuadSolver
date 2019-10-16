CC =gcc
CFLAGS = -ggdb -Wall -pedantic -std=gnu11
setIt: setIt.o
setIt.o: setIt.h
setItTest: setIt.o
test: ./setItTest

clean:
	rm -f *.0 setIt core

	CC = gcc
	CFLAGS = -O -Wall -pedantic

	test: tqsResults.o qsResults.o
		$(CC) $(CFLAGS) tqsResults.o qsResults.o -o test

	qsResults.o: qsResults.h

	tqsResults.o: qsResults.h

	run-test: test
		./test < tqsResultsIn.txt > tqsResultsOut.txt
		diff tqsResultsOut.txt tqsResultsOutReal.txt

	clean:
		rm -f *.o core test

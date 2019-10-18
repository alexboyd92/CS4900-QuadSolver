CC =gcc
CFLAGS = -ggdb -Wall -pedantic -std=gnu11

main: main.o ../setIt/setIt.o ../getIt/getit.o ../solveIt/solveIt.o
	$(CC) $(CFLAGS) main.o  ../setIt/setIt.o  ../getIt/getit.o  ../solveIt/solveIt.o -o qsolve
main.o: main.h

test: main
	./qsolve

clean:
	rm -f *.o qsolve
	$(MAKE) -C ../setIt/ clean
	$(MAKE) -C  ../getIt clean
	$(MAKE) -C ../testing clean
	$(MAKE) -C ../solveIt clean

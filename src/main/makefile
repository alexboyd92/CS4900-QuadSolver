CC =gcc
CFLAGS = -ggdb -Wall -pedantic -std=gnu11

main: main.o ../setIt/setIt.o ../getIt/getit.o
	$(CC) $(CFLAGS) main.o  ../setIt/setIt.o  ../getIt/getit.o -o qsolve
main.o: main.h

test: main
	./qsolve

clean:
	rm -f *.o qsolve
	$(MAKE) -C ../setIt/ clean
	$(MAKE) -C  ../getIt clean

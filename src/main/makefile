CC =gcc
CFLAGS = -ggdb -Wall -pedantic -std=gnu11 -lm

main: main.h ../setIt/setIt.o
	$(CC) $(CFLAGS) main.o  ../setIt/setIt.o -o qsolve
main.o: main.h
test: main
	./qsolve

clean:
	rm -f *.o qsolve
	cd ../setIt && $(MAKE) clean

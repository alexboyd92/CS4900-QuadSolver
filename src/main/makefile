CC =gcc
CFLAGS = -ggdb -Wall -pedantic -std=c11

main: main.o ../setIt/setIt.o ../getIt/getit.o ../solveIt/solveIt.o ../help/help.o ../validate/validate.o
	$(CC) $(CFLAGS) main.o  ../setIt/setIt.o  ../getIt/getit.o ../help/help.o ../solveIt/solveIt.o  ../validate/validate.o -o qsolve -lm
main.o: main.h

test: main
	./qsolve 20 20 20
	./qsolve 10 1 1
	./qsolve -1 20 20

clean:
	rm -f *.o qsolve
	$(MAKE) -C ../setIt/ clean
	$(MAKE) -C  ../getIt clean
	$(MAKE) -C ../testing clean
	$(MAKE) -C ../solveIt clean
	$(MAKE) -C ../help clean
	$(MAKE) -C ../validate clean
clear_logs:
	rm -f ../../logs/log_*

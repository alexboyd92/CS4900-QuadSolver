install:
	$(MAKE) -C src/main/ main
	mv src/main/qsolve .

clean:
	$(MAKE) -C src/main/ clean
	rm ./qsolve
uninstall:

	rm -rf ../CS4900-QuadSolver
unit-test:
	$(MAKE) -C src/testing testAll
system-test:
	$(MAKE) -C src/main/ test

tar:
	tar -zcvf ../CS4900-QuadSolver.tgz ../CS4900-QuadSolver/

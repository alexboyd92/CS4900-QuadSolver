install:
	$(MAKE) -C src/main/ main
	mv src/main/qsolve .

clean:
	rm ./qsolve
	$(MAKE) -C src/main/ clean
uninstall:

	rm -rf ../CS4900-QuadSolver
unit-test:
	$(MAKE) -C src/testing testAll
system-test:
	$(MAKE) -C src/main/ test  

tar:
	tar -zcvf ../CS4900-QuadSolver.tgz ../CS4900-QuadSolver/

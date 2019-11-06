install:
	$(MAKE) -C src/main/ main
	mv src/main/qsolve .


uninstall:
	rm ./qsolve 
	$(MAKE) -C src/main/ clean


tar:
	tar -zcvf ../CS4900-QuadSolver.tgz ../CS4900-QuadSolver/

install:
	$(MAKE) -C src/main/ main
	mv src/main/qsolve .

clean:
	rm ./qsolve
	$(MAKE) -C src/main/ clean
uninstall:

	rm -rf ../CS4900-QuadSolver


tar:
	tar -zcvf ../CS4900-QuadSolver.tgz ../CS4900-QuadSolver/

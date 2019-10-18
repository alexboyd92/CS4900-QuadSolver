#include "main.h"
// Main //
int main(int argc, char const *argv[]) {
	int quit=1;
	int validateFailed=0;
	double a,b,c;
	int flag;
	flag= solve(&a,&b,&c);
	printResults( flag,a,b);
	// if argc == 4 call validate input
	if(argc==4) {
		//validateInput()
		if(validateFailed)
			//help();
			;
		else
		{
			flag= solve(&a,&b,&c);
			printResults( flag,a,b);
		}

	}
	//call solve
	// call print results
	// do while if no arguments are specified
	// if argc is 1
	do {
		// call get input
		// then validate input
		// if validate fails call help
		// else if input = q quit =1
		//else
		//call solve
		// call printResults


	} while(!quit);


	// if argc > 4 call  help
	//exit




	return 0;
}// End main//

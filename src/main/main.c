#include "main.h"
// Main //
int main(int argc, char const *argv[]) {
	int quit=1;
	int validateFailed=0;
	double a,b,c;
	int flag;

	// if argc == 4 call validate input
	if(argc==4) {
		//validateInput()
		if(validateFailed)
			//help();
			;
		else
		{       //call solve
			flag= solve(&a,&b,&c);
			// call print results
			printResults( flag,a,b);
		}

	}
	// do while if no arguments are specified
	// if argc is 1
	else if(argc==1) {
		do {
			// call get input
			//getit();
			// then validate input
			//validate();
			// if validate fails call help
			if(validateFailed)
				//help();
				;
			else{
				//  if input = q quit =1
				if(validateFailed)
					quit=1;

				else{
					//call solve
					flag= solve(&a,&b,&c);
					// call print results
					printResults( flag,a,b);
				}
			}
		} while(!quit);

	}
	else{
		//help();
	}










	return 0;
}// End main//

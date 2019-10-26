#include "main.h"
// Main //
int main(int argc, char const *argv[]) {
	int quit=1;
	int validateFlag=0;
	double a,b,c;
	int flag;
	int logging;
	// if argc == 4 call validate input


	if(argc==4) {
		//validateInput()
		if(validateFlag==3)
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
		printHeader();
		do {
			// call get input
			//getit();
			// then validate input
			//validate();
			// if validate fails call help
			if(validateFlag==3)
				//help();
				;
			else{
				//  if input = q quit =1
				if(validateFlag=5)
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

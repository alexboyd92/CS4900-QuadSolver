#include "../setIt/setIt.h"
#include "../testing/cunit.h"
int main(int argc, char const *argv[]) {
	// check if no real roots
	printResults(2,20,21);
	// check if two real roots
	printResults(1,20,21);
	//check if one real root
	printResults(0,20,20);
	// check if error
	printResults(3,20,20);
	// check for negative results
	printResults(1,-120,20);
	// check for higher than a double
	printResults(1,DBL_MAX+2,1);
	return 0;
}

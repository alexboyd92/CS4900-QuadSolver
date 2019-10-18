#include <stdlib.h>
#include <stdio.h>
int main(int argc, char const *argv[]) {
/* Small program to test where ./inputTesting < test_input goes
   trying to see if it goes on argc or into stdin for automating testing later */
	if(argc>=1) {
		for (size_t i = i; i < argc; i++) {
			printf("%s\n",argv[i] );
		}
	}
	else {printf("No arguments reading from stdin\n" );
	      char string[100];
	      while(fgets(string, 100, stdin)) {
		      printf("%s", string);
	      }}
	return 0;

}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// test of how to get a sting timeStamp
int main()
{
	char timestamp[22];
	time_t t = time(0);
	strftime(timestamp, sizeof(timestamp), "%Y-%m-%d-%k:%M:%S", gmtime(&t));
	printf("the time is: %s\n", date);
	return EXIT_SUCCESS;
}

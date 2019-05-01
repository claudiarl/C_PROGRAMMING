#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char**argv)
{
	srand(time(NULL));
	double rnd=(double)rand()/(RAND_MAX+1.0);	
	
	printf("%g\n",rnd);

return 0;
}

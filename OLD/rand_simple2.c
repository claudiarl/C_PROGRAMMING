#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char**argv)
{
	int i;
	double rnd;
	
	srand(time(NULL));
	
	
	for(i=0;i<10;i++)
	{
	   rnd=(double)rand()/(RAND_MAX+1.0);
	   printf("%d\t%g\n",i,rnd);
    }
	return 0;
}

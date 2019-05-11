#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char**argv)
{
	int n,L;
	double rnd;
	
	L=atoi(argv[1]);
	if(L<1)
	{
		L=1;
	}
	
	srand(time(NULL));
	
	for(n=0;n<2*L;n++)
	{
		rnd=(double)rand()/(RAND_MAX+1.0);
	}	
	for(n=0;n<L;n++)		
	{
		rnd=(double)rand()/(RAND_MAX+1.0);
		printf("%d\t%g\n",n,rnd);
	}
	return 0;
}

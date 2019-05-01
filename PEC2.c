#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char**argv)
{
	int L,n,result;
	int semilla=(int) time(NULL);
	double r,p;
	double rnd=(double)rand()/(RAND_MAX+1.0);	
	if(argc<2)
	{
		printf("Uso del programa:\n %s<no.puntos>\n",argv[0]);
		exit(0);
	}
	
	L=atoi(argv[1]);
	r=atoi(argv[2]);
	srand(time(NULL));

	
	if(L<1)
	{
		L=1;
	}
	p=1/(1+r);

	for(n=0;n<L;n++)
	{
		if(rnd<0.5)
		{
			result=1;
		} else {
			result=0;
		}
		
		printf("%d\t%d\n",n,result);
	}
	
	return result;
}

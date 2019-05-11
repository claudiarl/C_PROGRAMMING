#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char**argv)
{
	int n,L,result;
	double rnd,r,p;
	
	if(argc<2)
	{
		printf("Uso del programa:\n %s<no.puntos>\n",argv[0]);
		exit(0);
	}
	
	FILE*fout;
	fout=fopen("poroso.dat","w");
	L=atoi(argv[1]);
	r=atof(argv[2]);
	if(L<1)
	{
		L=1;
	}
	
	srand(time(NULL));
	
	for(n=0;n<2*L;n++)
	{
		rnd=(double)rand()/(RAND_MAX+1.0);
	}
	
	p=1/(1+r);	
	for(n=0;n<L;n++)		
	{
		rnd=(double)rand()/(RAND_MAX+1.0);
		if(rnd<=p)
		{
			result=1;
		} 
		else 
		{
			result=0;
		}

		printf("%d\t%d\n",n,result);
		fprintf(fout,"%d\t%d\n",n,result);
	}

	return 0;
}

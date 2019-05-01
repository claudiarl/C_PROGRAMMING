#include <stdio.h>
#include <stdlib.h>
#include "libprobabilidad.h"

int main(int argc, char**argv)
{
	int L,n,result;
	double r,p;
	
	if(argc<2)
	{
		printf("Uso del programa:\n %s<no.puntos>\n",argv[0]);
		exit(0);
	}
	
	L=atoi(argv[1]);
	r=atoi(argv[2]);
	if(L<1)
	{
		L=1;
	}
	p=1/(1+r);
	for(n=0;n<L;n++)
	{
		(void)uniforme();
	}
	for(n=0;n<L;n++)
	{
		if(uniforme()>=0.5)
		{
			result=1;
		} else {
			result=0;
		}
		
		printf("%d\t%d\n",n,result);
	}
	
	return result;
}

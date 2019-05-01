#include <stdio.h>
#include <stdlib.h>
#include "libprobabilidad.h"

int main(int argc, char**argv)
{
	int npts,n;
	int xp;
	
	if(argc<2)
	{
		printf("Uso del programa:\n %s<no.puntos>\n",argv[0]);
		exit(0);
	}
	
	npts=atoi(argv[1]);
	if(npts<1)
	{
		npts=1;
	}
	xp=0;
	for(n=0;n<npts;n++)
	{
		(void)uniforme();
	}
	for(n=0;n<npts;n++)
	{
		if(uniforme()>=0.5)
		{
			xp++;
		} else {
			xp--;
		}
		
		printf("%d\t%d\n",n,xp);
	}
	
	return 0;
}

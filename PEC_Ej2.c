#include <stdio.h>
#include <math.h>
#include "libprobabilidad.h"


int leeNumeros(char*arch, double x[])
{
	int n, npts,NMAXPTS;
	double xa;
	
	FILE*fin;
	fin=fopen("poroso.dat","r");
	
	npts=0;
	do
	{
		n=fscanf(fin, "%lf", &xa);
		if(n==1 && npts<NMAXPTS)
		{
			x[npts]=xa;
		}
		npts++;
	}
	while(n==1 && npts<=NMAXPTS);
	
	fclose(fin);
	
	if(npts==NMAXPTS+1 && n==1)
	{
		npts=-1;
	}
	return npts;
}


int main(int argc, char**argv)
{
	int NMAXPTS,naleatorios,i;
	double aleatorios[NMAXPTS],dx,x,f,X_MIN,X_MAX;
	int histo[NHISTOGRAMA];
	
	naleatorios=leeNumeros("poroso.dat",aleatorios);
	
	histograma(naleatorios,aleatorios,NHISTOGRAMA,histo,X_MIN,X_MAX);
	dx=(double)(X_MAX-X_MIN)/NHISTOGRAMA;
	
	for(i=0;i<NHISTOGRAMA;i++)
	{
		x=X_MIN+(double)i*dx;
		f=(double)histo[i]/(naleatorios*dx);
		
		printf("%g\t%d\t%g\n",x,histo[i],f);
	}
	return 0;
}

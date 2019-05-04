#include <stdio.h>
#include <math.h>

#define X_MIN 0.0
#define X_MAX 10.0
#define NMAXPTS 10000

int leeNumeros(char*arch, double x[])
{
	int n, npts;
	double xa;
	
	FILE*fin;
	fin=fopen(arch,"r");
	
	npts=0;
	do
	{
		n=fscanf(fin, "%lf", &xa);
		if(n==1 && npts<NMAXPTS)
		{
			x[npts]=xa;
		npts++;
		}
		
	}
	while(n==1 && npts<=NMAXPTS);
	
	fclose(fin);
	
	if(npts==NMAXPTS+1 && n==1)
	{
		npts=-1;
	}
	
	return npts;
}

//nhist tamaño histo
//x es nuestros tamaños de huecos
//npts es el tamaño de la x
void histograma(int npts, double x[], int nhist, int histo[], double x_min, double x_max)
{
	int i,n, NHISTOGRAMA;

	
	for(i=0;i<nhist;i++)
	{
		histo[i]=0;
	}

	for(n=0;n<npts;n++)
	{
		double floorArgument = (nhist*(x[n]-x_min))/(x_max-x_min);
		i=(int)floor(floorArgument);

		if(0<=i && i<NHISTOGRAMA)
		{
			histo[i]++;
		}
	
	}
	
	return;
}

int main(int argc, char**argv)
{
	int naleatorios,i;
	int NHISTOGRAMA=atoi(argv[1]);
	double aleatorios[NMAXPTS],dx,x,f;
	int histo[NHISTOGRAMA];
	
	naleatorios=leeNumeros("prueba.dat",aleatorios);
	
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

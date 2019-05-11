#include <stdio.h>
#include <math.h>

#define X_MIN 0.0
#define X_MAX 1.0
#define NHISTOGRAMA 4
#define NMAXPTS 10000

//nhist tamaño histo
//x es nuestros tamaños de huecos
//npts es el tamaño de la x
//histo[i] es número de valores en cajas
//f es frecuencia relativa de valores en cajas
void histograma(int npts, double x[], int nhist, int histo[], double x_min, double x_max)
{
	int i,n;
	
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
	double aleatorios[NMAXPTS] = {5,3,1,1};
	double dx,x,f;
	int histo[NHISTOGRAMA];
	
	naleatorios=4;
	
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

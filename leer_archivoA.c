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

int hallarMinimo(int array[], int largoArray){
  int minimo = array[0];
  int j;
  for (j = 0; j < largoArray; j++)
  {
	  if(array[j]<minimo){
		minimo = array[j];
	  }
  }
  return minimo;
}

int hallarMaximo(int array[], int largoArray){
  int maximo = array[0];
  int j;
  for (j = 0; j < largoArray; j++)
  {
	  if(array[j]>maximo){
		maximo = array[j];
	  }
  }
  return maximo;
}


int main(int argc, char**argv)
{
	int naleatorios,i;
	
	int numeros [NMAXPTS];
	numeros = leeNumeros("prueba.dat",aleatorios);
	
  //Hallo el mínimo y el máximo dentro del array ya filtrado
  int minimo = hallarMinimo(arrayLimpio, largoArrayLimpio);
  printf("El mínimo es %d\n",minimo);
  int maximo = hallarMaximo(arrayLimpio, largoArrayLimpio);
  printf("El máximo es %d\n",maximo);
	
	
	int NHISTOGRAMA=atoi(argv[1]);
	
	double aleatorios[NMAXPTS],dx,x,f;
	int histo[NHISTOGRAMA];
	
	//naleatorios=leeNumeros("prueba.dat",aleatorios);
	
	histograma(numeros,aleatorios,NHISTOGRAMA,histo,X_MIN,X_MAX);
	dx=(double)(X_MAX-X_MIN)/NHISTOGRAMA;
	
	for(i=0;i<NHISTOGRAMA;i++)
	{
		x=X_MIN+(double)i*dx;
		f=(double)histo[i]/(numeros*dx);
		
		printf("%g\t%d\t%g\n",x,histo[i],f);
	}
	return 0;
}

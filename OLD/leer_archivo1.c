#include <stdio.h>
#include <math.h>

#define X_MIN 0.0
#define X_MAX 1.0
#define NHISTOGRAMA 100
#define NMAXPTS 10000

int leeNumeros(char*arch, double x[])
{
	int n,l,npts;
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
			printf("Los valores leídos son %g\n",xa);
		}
		npts++;
	}
	while(n==1 && npts<=NMAXPTS);
	
	fclose(fin);
	
	if(npts==NMAXPTS+1 && n==1)
	{
		npts=-1;
	}
	printf("El número total de datos del archivo es %d\n",npts);
	return npts;
	
}

int main(int argc,char**argv)
 {
	int xp;
	double xa;
	double arrayDeLeeNumeros[NMAXPTS];
	leeNumeros("prueba.dat",arrayDeLeeNumeros);
	
	while(xa=0){
	xp++;
	printf("de nuevo%d\n",xa);
	}
/*	

 FILE * fout = fopen("huecos.dat", "w"); 
	for(npts=0;npts<NMAXPTS;npts++)
{
	do
	{
		xp++;
	
	}
	while(clander=0);
}	


for(l=1;l<(L/2);l++)
{
	int numerohuecosmismalong= */
	//fprintf(fout, "%d\n", xp);
//fprintf(fout, "%d\n", l);
//}

	return 0;
	}
/*void histograma(int npts, double x[], int nhist, int histo[], double x_min, double x_max)
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
*/

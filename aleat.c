#include <stdio.h>
#include <stdlib.h>

#define SEMILLA 1234567891LL
#define LINEAL_A 1664525LL
#define LINEAL_B 1013904223LL
#define CONGRUENCIA 4294967296LL

int main(int argc,char**argv)
{
	int nnums,n;
	long long int r;
	double f;
	
	if(argc!=2)
	{
		printf("Uso del programa:\n %s<num aleatorios>\n",argv[0]);
		exit(0);
	}
	nnums=atoi(argv[1]);
	if(nnums<1)
	{
		nnums=1;
	}
	r=SEMILLA;
	for(n=0;n<2*nnums;n++)
	{
		r=(LINEAL_A*r+LINEAL_B)%CONGRUENCIA;
	}
	for(n=0;n<nnums;n++)
	{
		r=(LINEAL_A*r+LINEAL_B)%CONGRUENCIA;
		f=(double)r/CONGRUENCIA;
		
		printf("%g\n",f);
	}
	return 0;
}

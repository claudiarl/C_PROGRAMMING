#include <stdio.h>
#include <stdlib.h>

#define SEMILLA 12345678L
#define LINEAL_A 16807L
#define LINEAL_B 0L
#define CONGRUENCIA 2
#define NUNIFORMES 100

long long semilla_normal=SEMILLA;

double normal()
{
	int n;
	double f,s,g;
	
	s=0.0;
	for(n=0;n<NUNIFORMES;n++)
	{
		semilla_normal=(LINEAL_A*semilla_normal+LINEAL_B)%CONGRUENCIA;
		f=(double)semilla_normal/CONGRUENCIA;
		s=s+f;
	}
	g=(s-0.5*NUNIFORMES)/sqrt((1.0/12)*NUNIFORMES);
	return g;
}

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
	
	for(n=0;n<2*nnums;n++)
	{
		(void)normal();
	}
	for(n=0;n<nnums;n++)
	{
		f=normal();
		
		printf("%g\n",f);
	}
	return 0;
}

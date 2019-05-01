#include <stdio.h>
#include <stdlib.h>

#define SEMILLA 1234567891LL
#define LINEAL_A 1664525LL
#define LINEAL_B 1013904223LL
#define CONGRUENCIA 4294967296LL


double ultimoGenerado;

double uniforme()
{
	int n, nnums;
	long long semilla_uniforme=SEMILLA;
	for(n=0;n<2;n++)
	{
		semilla_uniforme=(LINEAL_A*semilla_uniforme+LINEAL_B)%CONGRUENCIA;
	}
	semilla_uniforme=(LINEAL_A*semilla_uniforme+LINEAL_B)%CONGRUENCIA;
	ultimoGenerado=(double)semilla_uniforme/CONGRUENCIA;
	printf("Se ha generado el número %g\n",ultimoGenerado);
	return ultimoGenerado;
}


int main(int argc,char**argv)
{
	uniforme();
	printf("El último generado es el %g\n",ultimoGenerado);
	return 0;
}

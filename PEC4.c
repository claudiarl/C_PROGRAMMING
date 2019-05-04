#include <stdio.h>
#include <math.h>
#include "libprobabilidad.h"


int leeNumeros(double x[])
{
	int lectura,n,L;
	double xa;
	FILE*fin;
	fin=fopen("prueba.dat","r");
	
	n=0;
	do
	{
		lectura=fscanf(fin, "%lf", &xa);
		if(lectura==1 && n<L)
		{
			x[n]=xa;
		}
		n++;
	}
	while(lectura==1 && n<=L);
	
	fclose(fin);
	
	if(n==L+1 && lectura==1)
	{
		n=-1;
	}
	return n;
}

 int main(int argc,char**argv)
 {
	 int i,n,result,xp;
	 int L = atoi(argv[1]);
	 double x[L];
	 int leeNumeros(double x[]);
	 for(i = 0; i<L; i++){
       printf("%d\n",x[i]);
	 }
	 
	 /*while (result=0)
	 {
		xp++;
		 printf("l=posicion+desplazamiento derecha=%d\n",n);n+=1;
	 }*/
	 return 0;
 }

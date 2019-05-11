#include <stdio.h>

int main(int argc, char**argv)
{
	int npts,n;
	double x,y;
	FILE*fout;
	
	fout=fopen("datos.dat","w");
	
	printf("Número de puntos:");
	scanf("%d",&npts);
	
	for(n=0;n<npts;n++)
	{
		printf("X_%d=",n);
		scanf("%lf",&x);
		printf("Y_%d=",n);
		scanf("%lf",&y);
		
		fprintf(fout,"%g\t%g\n",x,y);
	}
	fclose(fout);
	return 0;
}

#include <stdio.h>

#define ANCHURA 512
#define ALTURA 512

void guardarPGM(char* nombre, int anchura, int altura, double *pixels, double pixel_min, double pixel_max)

{
	int i,j,ij,p;
	FILE*imagen;
	
	imagen=fopen(nombre,"wb");
	fprintf(imagen, "P2");
	fprintf(imagen,"#guardarPGM %s\n", nombre);
	fprintf(imagen,"%d %d\n", anchura, altura);
	fprintf(imagen,"255\n");
	
	ij=0;
	for(i=0;i<altura;i++)
	{
		for(j=0;j<anchura;j++)
		{
			p=(int)(255*(pixels[ij]-pixel_min))/(pixel_max-pixel_min);
			
			if(p<0) p=0;
			if(p>255) p=255;
		
			fprintf(imagen," %d",p);
		
			ij++;
		}
		fprintf(imagen,"\n");
	}
fclose(imagen);
return;
}

int main(int argc,char**argv)
{
	int i,j;
	double x,y,z;
	double f[ANCHURA][ALTURA];
	
	for(i=0;i<ALTURA;i++)
	{
		for(j=0;j<ANCHURA;j++)
		{
			x=2*(double)j/(ANCHURA-1)-1.0;
			y=2*(double)i/(ALTURA-1)-1.0;
			z=1.0/(1+(2*x+x+3+y+y));
			
			f[i][j]=z;
		}
	}
	guardarPGM("prueba.pgm",ANCHURA, ALTURA,(double*)f,0,1.0);
	return 0;
}

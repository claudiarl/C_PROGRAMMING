#include <stdio.h>

int main(int argc, char**argv)
{
	int i;
	float x[]={1.0,2.0,3.0};
	float y[3];
	float z[3];
	
	y[0]=3.0;
	y[1]=2.0;
	y[2]=1.0;
	
	for(i=0;i<3;i++)
	{
		z[i]=x[i]+y[i];
	}
	printf("La suma de vectores da:");
	printf("[%g",z[0]);
	for(i=1;i<3;i++)
		printf(",%g",z[i]);
		printf("]\n");
	return 0;
}

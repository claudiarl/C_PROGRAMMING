#include <stdio.h>

int main(int argc, char**argv)
{
	int i;
	float x[]={1.0,2.0,3.0};
	float y[]={3.0,2.0,1.0};
	float z[3];

	for(i=0;i<3;i++)
	{
		z[i]=x[i]+y[i];
	}
		printf("[%g",z[0]);
		for(i=1;i<3;i++)
		printf(",%g",z[i]);
		printf("]\n");
	return 0;
}

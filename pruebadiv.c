#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	double r,p;
	
	r=atoi(argv[1]);
	p=1/(1+r);
	printf("%g\t%g\n",r,p);
	
	return 0;
}

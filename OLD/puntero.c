#include <stdio.h>

int main(int argc, char**argv)
{
	double a=43.4;
	double*q;
	q=&a;
	*q=0.3;
	printf("El puntero que apunta a %g\n",*q);
	printf("La nueva a es %g\n",a);
	
	return 0;
}

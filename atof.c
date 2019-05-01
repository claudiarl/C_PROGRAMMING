#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	int val
	char **argv[1]
	double atof(const char **argv)
	val=atof(argv[1]);
	
	printf("String value = %s, Int value = %d\n", argv[1], val);
	return 0;
}

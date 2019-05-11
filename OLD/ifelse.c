#include <stdio.h>

int main(int argc, char**argv)
{
	float a,b,c;
	a=1.5;
	b=3.2;
	
	if(a<b)
	{
		c=b-a;
	}
	else
	{
		c=a-b;
	}
	printf("|%g-%g|=%g\n",a,b,c);
	
	return 0;
}

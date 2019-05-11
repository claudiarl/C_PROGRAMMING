#include <stdio.h>
 int main(int argc,char**argv)
 {
	 int n;
	 long int factor=(1,4);
	 for(n=1;n<4;n++)
		factor=factor*n;
	 {
		 printf("%li\n",factor);
	 }
	 return 0;
 }

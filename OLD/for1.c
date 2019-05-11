#include <stdio.h>
 int main(int argc,char**argv)
 {
	 int n;
	 long int factor=(1,10);
	 for(n=1;n<=10;n++)
		factor=factor*n;
	 {
		 printf("%li\n",factor);
	 }
	 return 0;
 }

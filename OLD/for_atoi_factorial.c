#include <stdio.h>
#include <stdlib.h>
 int main(int argc,char**argv)
 {
	 int i,n;
	 long int f;
	 
	 n=atoi(argv[1]);
	 
	 f=1;
	 
	 for(i=2;i<=n;i++)
		f*=i;
		
		 printf("%d ! =%ld\n",n,f);
	 
	 return 0;
 }

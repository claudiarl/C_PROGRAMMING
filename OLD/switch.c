#include <stdio.h>
int main(int argc, char**argv)
{
	int sel;
	printf("1.Opción A\n");
	printf("2.Opción B\n");
	printf("3.Opción C\n");
	printf("O.Salir\n");
	do{
		printf("Opción:");
		scanf("%d", &sel);
	switch(sel)
	{
		case 0:
			break;
		case 1: 
			printf("Buena la 1\n");
		break;
		case 2: 
			printf("No tan buena la 2\n");
		break;
		case 3:
			printf("La 3 definitivamente no me gusta\n");
			break;
		default:
			printf("Esta opción no se ha ofrecido\n""Pruebe de nuevo");
	}

} while(sel!=0);
return 0;
}

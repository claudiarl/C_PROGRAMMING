#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generarPoroso(int L, double r, int poroso[]){
  double p = 1 / (1 + r); //Probabilidad de opacos en el poroso
  int n; //Índice de los bucles
  double rnd; //Números aleatorios generados
  char result; //Variable auxiliar que almacenará los valores del medio poroso
  
  /* Si la longitud del poroso provista 
   * es menor que 1, la ajusto a 1*/
  if (L < 1) 
  {
    L = 1;
  }
  
  //Inicialización del random
  int semilla = (int)time(NULL);
  srand(semilla);
  
   //Calentamiento
  for (n = 0; n < 2 * L; n++) 
  {
    rnd = (double) rand() / (RAND_MAX + 1.0);
  }
  
  //Generación y guardado del poroso
  for (n = 0; n < L; n++) 
  {
    rnd = (double) rand() / (RAND_MAX + 1.0);
    if (rnd <= p) 
    {
      result = 1;
    } 
    else 
    {
      result = 0;
    }
    poroso[n]=result;
  }
}

int main(int argc, char ** argv) {
  //Salida del programa si los argumentos no son los esperados
  if (argc < 2) 
  {
    printf("Uso del programa:\n %s <no.puntos>\n", argv[0]);
    exit(0);
  }

  int L = atoi(argv[1]); //Longitud del poroso
  double r = atof(argv[2]); //Porosidad del medio
  
  //Índices de los bucles
  int n, m, j;

  //Genero poroso y lo guardo en un array
  int poroso[L];
  generarPoroso(L, r, poroso);
  
  for(int j=0;j<L;j++){
	printf("%d, ",poroso[j]);
  }
    printf("\n");
  
  
  //Creo un array de -1s tan largo como el poroso
  int grupoCeros [L];
  for(j=0;j<=L;j++){
	grupoCeros[j]=-1;
  }
  
  for(n = 0; n < L; n++)
  {
	if(poroso[n]==0){
		int numeroCeros = 0;
		for(m = n; m <=L; m++)
		{
			if(m==L || poroso[m]==1) {
				n = m;
				grupoCeros[m] = numeroCeros;
				break;
			} else if (poroso[m]==0)
			{
				numeroCeros++;
			}
		}
    }

  }
  
  for(j=0;j<=L;j++){
	if(grupoCeros[j]!=-1){
		printf("%d\n",grupoCeros[j]);
	}
  }
  
  return 0;
}

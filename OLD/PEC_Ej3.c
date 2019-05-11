#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include <math.h>

#include <unistd.h>


void generarPoroso(int L, double r, int poroso[]) {
  double p = 1 / (1 + r); //Probabilidad de opacos en el poroso
  int n; //Índice de los bucles
  double rnd; //Números aleatorios generados
  char result; //Variable auxiliar que almacenará los valores del medio poroso

  /* Si la longitud del poroso provista 
   * es menor que 1, la ajusto a 1*/
  if (L < 1) {
    L = 1;
  }

  //Inicialización del random
  int semilla = (int) time(NULL);
  srand(semilla);

  //Calentamiento
  for (n = 0; n < 2 * L; n++) {
    rnd = (double) rand() / (RAND_MAX + 1.0);
  }

  //Generación y guardado del poroso
  for (n = 0; n < L; n++) {
    rnd = (double) rand() / (RAND_MAX + 1.0);
    if (rnd <= p) {
      result = 1;
    } else {
      result = 0;
    }
    poroso[n] = result;
  }
}

int cuantosNumero(int largoArray, int array[], int numero) {
  int i;
  int contadorNumero = 0;
  for (i = 0; i < largoArray; i++) {
    if (array[i] == numero) {
      contadorNumero++;
    }
  }
  return contadorNumero;
}

void histograma(int maximo, int array[], int largoArray, int N, int L) {
  int i;
  int segundaColumna[maximo];
  for (i = 0; i < maximo; i++) {
    segundaColumna[i] = cuantosNumero(largoArray, array, i + 1);
  }
  int linea = 1;
  for (i = 0; i < maximo; i++) {
    double terceraColumna = (double)(segundaColumna[i]) / (double)(N * L);
    printf("%d\t%d\t%g\n", linea++, segundaColumna[i], terceraColumna);
  }
}

int hallarLargoArrayLimpio(int tamanoSucio, int arraySucio[]) {
  //Hallo el tamaño del arrayLimpio
  int contador = 0;
  int j;
  for (j = 0; j <= tamanoSucio; j++) {
    if (arraySucio[j] != -1 && arraySucio[j] != 0) {
      contador++;
    }
  }
  return contador;
}

void filtrarArray(int tamanoSucio, int arraySucio[], int arrayLimpio[]) {
  //Relleno un nuevo array quitando -1s y 0s del arraySucio
  int vueltas = 0;
  int j;
  for (j = 0; j <= tamanoSucio; j++) {
    if (arraySucio[j] != -1 && arraySucio[j] != 0) {
      arrayLimpio[vueltas++] = arraySucio[j];
    }
  }
}

int main(int argc, char ** argv) {
  //Salida del programa si los argumentos no son los esperados
  if (argc < 3) {
    printf("Uso del programa:\n %s <no.puntos, porosidad, número de cadenas>\n", argv[0]);
    exit(0);
  }

  int L = atoi(argv[1]); //Longitud del poroso
  double r = atof(argv[2]); //Porosidad del medio
  int N = atoi(argv[3]); //Número de cadenas

  //Índices de los bucles
  int n, m, j, t, ultimaPosicionRellenaTodosHuecosfinal;
  int ultimaPosicionRellenaTodosHuecos = 0;
  int TodosHuecos[ultimaPosicionRellenaTodosHuecos];

  for (t = 0; t < N; t++) {
    printf("Genero cadenas %d\n", t + 1);

    //Genero poroso, lo guardo en un array y lo imprimo por pantalla
    int poroso[L];
    generarPoroso(L, r, poroso);

    // Pinto el poroso (cadenas de 0 y 1)
    for (int j = 0; j < L; j++) {
      printf("%d, ", poroso[j]);
    }
    printf("\n");

    //Creo un array de -1s de longitud L/2
    int distanciaCeros[L];
    for (j = 0; j <= L; j++) {
      distanciaCeros[j] = -1;
    }
    //Hacia la derecha
    for (n = 0; n < L; n++) {
      int m = n;
      int numeroCeros = 0;
      if (poroso[m] == 0 && m < L) {
        numeroCeros++;
        m++;
        distanciaCeros[m] = numeroCeros - 1;
      }
      n = m;
    }

    //Pinto el array de distancias sin filtrar
    for (n = 0; n < L; n++) {
      printf("%d, ", distanciaCeros[m]);
    }
    printf("\n");

    //Filtrar el array que he obtenido
    int largoArrayLimpio = hallarLargoArrayLimpio(L, distanciaCeros);
    int arrayLimpio[largoArrayLimpio];
    filtrarArray(L, distanciaCeros, arrayLimpio);

    //Pinto el array de distancias
    for (n = 0; n < largoArrayLimpio; n++) {
      printf("%d, ", arrayLimpio[n]);
    }
    printf("\n");

    sleep(1);
    
    
    
    /*    //Creo un array con todos los valores anteriores de huecos de las N cadenas
    int i,j;  
    int k = 0;
	  for (j=ultimaPosicionRellenaTodosHuecos;j<ultimaPosicionRellenaTodosHuecos+largoArrayLimpio;j++)
	  {
			TodosHuecos[j] = arrayLimpio[k++];
	  }
    
    //printf("ultima posicion era %d\n",ultimaPosicionRellenaTodosHuecos);
    ultimaPosicionRellenaTodosHuecos+=largoArrayLimpio;
    
    //Pinto el array todos huecos
    for(n = 0;n<ultimaPosicionRellenaTodosHuecos+largoArrayLimpio;n++){
	  printf("%d, ",TodosHuecos[n]);
    }
    printf("\n");
    printf("ultima posicion rellena es %d\n",ultimaPosicionRellenaTodosHuecos);
  }
*/
  }
  return 0;
}

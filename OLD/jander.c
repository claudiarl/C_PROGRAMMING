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
  double normalizador = (double) N * L;
  for (i = 0; i < maximo; i++) {
	double sinNormalizar = (double)(segundaColumna[i]) / (double)(largoArray);
    double terceraColumna = sinNormalizar * normalizador;
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

int hallarMinimo(int array[], int largoArray) {
  int minimo = array[0];
  int j;
  for (j = 0; j < largoArray; j++) {
    if (array[j] < minimo) {
      minimo = array[j];
    }
  }
  return minimo;
}

int hallarMaximo(int array[], int largoArray) {
  int maximo = array[0];
  int j;
  for (j = 0; j < largoArray; j++) {
    if (array[j] > maximo) {
      maximo = array[j];
    }
  }
  return maximo;
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
  int n, m, j, t;
  
  for (t = 0; t < N; t++) {
	//printf("Genero histograma %d\n",t+1);
	
    //Genero poroso, lo guardo en un array y lo imprimo por pantalla
    int poroso[L];
    generarPoroso(L, r, poroso);
    
    // Pinto el poroso (cadenas de 0 y 1)
    for (int j = 0; j < L; j++) {
      printf("%d, ", poroso[j]);
    }
    printf("\n");
    
	//Creo un array de -1s tan largo como el poroso
    int grupoCeros[L];
    for (j = 0; j <= L; j++) {
      grupoCeros[j] = -1;
    }

    //Recorro el poroso y guardo el número de grupos de ceros y su tamaño HE CAMBIADO A L/2
    for (n = 0; n <= L; n++) {
      int m = n;
      int numeroCeros = 0;
      while (poroso[m] == 0 && m <= L) {
        numeroCeros++;
        m++;
      }
      n = m;
      grupoCeros[m] = numeroCeros;
    }
 printf("\n");
    printf("Grupo ceros");
    for (int j = 0; j <= L; j++) {
      printf("%d, ", grupoCeros[j]);
    }
    //Filtrar el array que he obtenido
    int largoArrayLimpio = hallarLargoArrayLimpio(L, grupoCeros);
    int arrayLimpio[largoArrayLimpio];
    filtrarArray(L, grupoCeros, arrayLimpio);
 printf("\n");
    //Pinto los huecos
    for(n = 0;n<largoArrayLimpio;n++){
	  printf("%d, ",arrayLimpio[n]);
    }
    printf("\n");
    
  /*  
    //Hallo el mínimo y el máximo dentro del array ya filtrado
    int minimo = hallarMinimo(arrayLimpio, largoArrayLimpio);
    int maximo = hallarMaximo(arrayLimpio, largoArrayLimpio);

    //Genero el histograma
    histograma(maximo, arrayLimpio, largoArrayLimpio,N, L);*/
    sleep(1);
  }
  return 0;
}

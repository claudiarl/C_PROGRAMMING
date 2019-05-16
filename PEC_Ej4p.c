#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define LENGTH 1000000

void imprimirArray(int longitud, int array[], char * nombreArray) {
  printf("Inicio %s\n", nombreArray);
  for (int j = 0; j < longitud; j++) {
    printf("%d, ", array[j]);
  }
  printf("\nFin %s\n", nombreArray);
}

//Función para generar el poroso, importada del Ejercicio 1
void generarPoroso(int L, double r, int poroso[]) {
  double p = 1 / (1 + r); //Probabilidad de opacos en el poroso
  int n; //Índice de los bucles
  double rnd; //Números aleatorios generados
  char result; //Variable auxiliar que almacenará los valores del medio poroso

  /* Si la longitud del poroso provista es menor que 1, se ajusta a 1*/
  if (L < 1) {
    L = 1;
  }
  //Inicialización del proceso de aleatorización definiendo la semilla
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

int main(int argc, char ** argv) {
  //Salida del programa si los argumentos no son los esperados
  if (argc < 3) {
    printf("Uso del programa:\n %s <no.puntos, porosidad, número de cadenas>\n", argv[0]);
    exit(0);
  }

  int L = atoi(argv[1]); //Longitud del poroso
  double r = atof(argv[2]); //Porosidad del medio
  int N = atoi(argv[3]); //Número de cadenas

  //Número de ceros a tomar aleatoriamente de cada cadena generada
  int M = N / 16;
  //Declaración de los arrays y variables que se emplearán más adelante
  int indicesCeros[LENGTH];
  int cerosLados[N * M];
  char * lados[2] = {"I","D"};
  int indiceCerosLados = 0;

  for (int i = 0; i < N; i++) {
    //Generación del poroso
    int poroso[L];
    generarPoroso(L, r, poroso);
    //Impresión de los porosos generados
    for (int i = 0; i < L; i++) {
      printf("%d, ", poroso[i]);
    }
    printf("\n");

    //Generación del array con las posiciones (índices) que ocupan los ceros en el poroso
    int a = 0;
    int contaje = 0;
    for (int i = 0; i < L; i++) {
      if (poroso[i] == 0) {
        indicesCeros[a++] = i;
        contaje++;
      }
    }
    imprimirArray(contaje, indicesCeros, "Indices Ceros");
    printf("contaje es %d\n", contaje);

    //Recorrido del poroso M veces para seleccionar ceros aleatorios
    for (int k = 0; k < M; k++) {

      //Definición de la semilla para la generación de números aleatorios	
      int semilla = (int) time(NULL);
      srand(semilla);
      //Calentamiento
      for (int n = 0; n < 2 * L; n++) {
        rand();
      }
      //Aleatorización del índice del array donde hay un cero
      int randomIndice = rand() % contaje;
      printf("el randomindice de indicesCeros es indicesCeros[%d]\n", indicesCeros[randomIndice]);
      printf("El poroso[%d] es %d\n", indicesCeros[randomIndice], poroso[indicesCeros[randomIndice]]);

      //Aleatorización del lado hacia el que se recorrerá el poroso
      int randomLadoIndice = rand() % 2;
      printf("El lado elegido es %s\n", lados[randomLadoIndice]);

      int cerosAlLado = 0;
      if (strncmp("I", lados[randomLadoIndice], 1) == 0) {
        for (int j = indicesCeros[randomIndice] - 1; j >= 0; j--) {
          if (poroso[j] == 0) {
            cerosAlLado++;
          } else {
            break;
          }
        }
      } else {
        for (int j = indicesCeros[randomIndice] + 1; j < L; j++) {
          if (poroso[j] == 0) {
            cerosAlLado++;
          } else {
            break;
          }
        }
      }
      //int contarCerosAlLado(char *lado, int primeraPosicion, int longitud, int *array)
      // int cerosAlLado = contarCerosAlLado(lados[randomLadoIndice], randomIndice, L, poroso);

      printf("El número de ceros a la %s de poroso[%d] es %d\n", lados[randomLadoIndice], indicesCeros[randomIndice], cerosAlLado);

      cerosLados[indiceCerosLados++] = cerosAlLado;
      sleep(1);
    }
  }

  imprimirArray(N * M, cerosLados, "Ceros Lados");

  int suma = 0;
  for (int i = 0; i < N * M; i++) {
    suma += cerosLados[i];
  }
  double long_correl = (double) suma / (double)(N * M);

  printf("La longitud de correlación es %g\n", long_correl);

  return 0;
}

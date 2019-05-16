#include <stdio.h>

#include <time.h>

#include <stdlib.h>

#include <unistd.h>

#include <string.h>

#define LENGTH 1000000

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

  //Para cada una de las N cadenas se realizan los pasos contenidos en el siguiente bucle for
  for (int i = 0; i < N; i++) {
    
    //Generación del poroso
    int poroso[L];
    generarPoroso(L, r, poroso);
    //Impresión del poroso
    printf("Poroso\n");
    for (int i = 0; i < L; i++) {
      printf("%d, ", poroso[i]);
    }
    printf("\n");

    /*Generación del array "indicesCeros" con las posiciones (índices) que ocupan los ceros en el poroso
    *La longitud de indicesCeros es "contaje"*/
    int a = 0;
    int contaje = 0;
    for (int i = 0; i < L; i++) {
      if (poroso[i] == 0) {
        indicesCeros[a++] = i;
        contaje++;
      }
    }
//Definición de la semilla para la generación de números aleatorios	
      int semilla = (int) time(NULL);
      srand(semilla);
      //Calentamiento
      for (int n = 0; n < 2 * L; n++) {
        rand();
      }
    //Recorrido del poroso M veces para seleccionar ceros aleatorios
    for (int k = 0; k < M; k++) {
     
      int nuevocontaje = 0;
      
      /*Impresión del array indicesCeros, que se actualiza en cada vuelta k
       * de forma que su longitud es "nuevocontaje" y se reduce en 1 unidad en cada vuelta*/
      printf("Array indicesCeros en la vuelta %d\n", k);
      for (int i = 0; i < contaje - k; i++) {
        nuevocontaje++;
        printf("%d, ", indicesCeros[i]);
      }
      printf("\n");

      
      /*Se selecciona aleatoriamente un índice del array indicesCeros entre 
      su longitud total (nuevocontaje), obteniendo "randomIndice"*/
      int randomIndice = rand() % nuevocontaje;
      //Se verifica que en la posición determinada por el índice elegido hay un cero en el poroso
      printf("El poroso[%d] es %d\n", indicesCeros[randomIndice], poroso[indicesCeros[randomIndice]]);

      /*Se selecciona aleatoriamente el lado hacia el que se recorrerá el poroso 
       entre las dos posibilidades definidas en char*lados, obteniendo "randomLado"*/
      int randomLado = rand() % 2;
      printf("El lado elegido es %s\n", lados[randomLado]);

	  //Contaje del número de ceros a la izquierda o a la derecha del cero cuyo índice se ha seleccionado aleatoriamente
      int cerosAlLado = 0;
      if (strncmp("I", lados[randomLado], 1) == 0) {
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

      printf("El número de ceros a la %s de poroso[%d] es %d\n", lados[randomLado], indicesCeros[randomIndice], cerosAlLado);

      //Generación del array "cerosLados" que almacena todos los cálculos anteriores
      cerosLados[indiceCerosLados++] = cerosAlLado;

      /*Para evitar que se repita la elección aleatoria del mismo cero en las sucesivas simulaciones        
      se salta el índice elegido en cada vuelta para generar un nuevo array de índiceCeros al volver a iniciar el bucle*/

      for (int i = 0; i < randomIndice; i++) {
        indicesCeros[i] = indicesCeros[i];
      }
      for (int i = randomIndice; i < contaje; i++) {
        indicesCeros[i] = indicesCeros[i + 1];
      }
	  /*Para evitar que tanto las cadenas como la aleatorización de los índices de ceros y de lado sean iguales, 
	  se genera una espera de 1 segundo de forma que cambie la semilla*/
      
    }sleep(1);
  }

  for (int i = 0; i < M * N; i++) {
    printf("%d, ", cerosLados[i]);
  }
  printf("\n");

  int suma = 0;
  for (int i = 0; i < N * M; i++) {
    suma += cerosLados[i];
  }
  double long_correl = (double) suma / (double)(N * M);

  printf("La longitud de correlación es %g\n", long_correl);

  return 0;
}

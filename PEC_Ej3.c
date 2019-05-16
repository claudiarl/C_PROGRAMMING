#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

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

//Función para hallar el valor máximo de un array
int hallarMaximo(int longitud, int array[]) {
  int j;
  int maximo = array[0];
  for (j = 0; j < longitud; j++) {
    if (array[j] > maximo) {
      maximo = array[j];
    }
  }
  return maximo;
}

//Función para calcular la frecuencia de un número dado en un array
int frecuencia(int longitudArray, int array[], int num) {
  int i;
  int contador = 0;
  for (i = 0; i < longitudArray; i++) {
    if (array[i] == num) {
      contador++;
    }
  }
  return contador;
}

//Función para generar el histograma de frecuencias
void histograma(int maximo, int array[], int longitudArray, int N, int L) {
  int i;
  //Se declaran las 5 columnas del histograma
  int long_hueco;
  int frec_hueco[maximo];
  double frec_normalizada;
  int frec_absoluta[maximo];
  int total_ceros[maximo];
  //Se calculan las 5 columnas del histograma
  for (i = 1; i <= maximo; i++) {
    long_hueco = i;
    frec_hueco[i - 1] = frecuencia(longitudArray, array, i);
    frec_normalizada = (double)(frec_hueco[i - 1]) / (double)(N * L);
    frec_absoluta[i - 1] = long_hueco * (long_hueco - 1) * (double)(frec_hueco[i - 1]);
    total_ceros[i - 1] = long_hueco * (double)(frec_hueco[i - 1]);
    printf("%d\t%d\t%g\t%d\t%d\t\n", long_hueco, frec_hueco[i - 1], frec_normalizada, frec_absoluta[i - 1], total_ceros[i - 1]);
  }
  //Cálculo de la longitud de correlación
  int suma_frec_absoluta = 0;
  for (int i = 0; i < long_hueco; i++) {
    suma_frec_absoluta += frec_absoluta[i];
  }
  int suma_total_ceros = 0;
  for (int i = 0; i < long_hueco; i++) {
    suma_total_ceros += total_ceros[i];
  }
  double long_correl = (double) suma_frec_absoluta / (2*(double) suma_total_ceros);
  printf("La longitud de correlación es %g\n", long_correl);
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
  int n, t, j, i;
  //Se definen variables que se emplearán dentro del bucle for
  int contaje;
  int extremo = 0;
  //Se crean arrays con longitud máxima definida mediante LENGTH
  int Huecos[LENGTH];
  int Array[LENGTH];

  //Se inicializa un bucle for con las instrucciones para cada una de las N cadenas
  for (t = 0; t < N; t++) {
    //Generación y guardado del poroso en el array "poroso"
    int poroso[L];
    generarPoroso(L, r, poroso);

    //Impresión de los porosos generados
    for (i = 0; i < L; i++) {
      printf("%d, ", poroso[i]);
    }
    printf("\n");

    //Contaje de los ceros consecutivos dentro de un poroso para obtener las longitudes de hueco
    int a = 0;
    int contaje = 0;
    for (n = 0; n <= L; n++) {
      int numeroCeros = 0;
      //Se cuentan los ceros consecutivos y se almacenan en numeroCeros
      while (poroso[n] == 0 && n < L) {
        numeroCeros++;
        n++;
      }
      /*Se rellena un array con las longitudes de hueco omitiendo las que valgan cero
       * Se actualiza el número de elementos que se van incluyendo en el array para obtener su longitud final mediante "contaje"*/
      if (numeroCeros != 0) {
        contaje++;
        Array[a++] = numeroCeros;
      }
    }
    //Se elimina la cola de ceros del array, conociendo ahora su longitud gracias a "contaje"
    int flag = 1;
    for (n = 0; n < contaje; n++) {
      if (flag == 1 && Array[n] != 0)
        flag = 0;
    }
    //Para evitar que todas las cadenas sean iguales, se genera una espera de 1 segundo de forma que cambie la semilla
    sleep(1);

    /*Se genera el array "Huecos" con todas las longitudes de hueco de las N cadenas
     * Para ello, se define la variable "extremo", que representa la longitud del array Huecos y
     * se va actualizando tras cada paso del bucle al sumar contaje
     * (es decir, la longitud de cada cadena de longitudes de hueco)*/
    int k = 0;
    for (n = extremo; n < extremo + contaje; n++) {
      Huecos[n] = Array[k++];
    }
    extremo += contaje;

  }
  //Impresión del array Huecos
  for (i = 0; i < extremo; i++) {
    printf("%d, ", Huecos[i]);
  }
  printf("\n");
  //Cálculo del valor máximo del array Huecos para determinar la última fila del histograma
  int maximo = hallarMaximo(extremo, Huecos);

  //Generación del histograma
  histograma(maximo, Huecos, extremo, N, L);

  return 0;
}

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include <math.h>

#include <unistd.h>

#define LENGTH 1000000

void imprimirArray(int longitud, int array[], char * nombreArray) {
  printf("Inicio %s\n", nombreArray);
  for (int j = 0; j < longitud; j++) {
    printf("%d, ", array[j]);
  }
  printf("\nFin %s\n", nombreArray);
}
//Se escribe la función para generar el poroso, traída del Ejercicio 1
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

int frecuencia(int largoArray, int array[], int numero) {
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
  int primeraColumna;
  int segundaColumna[maximo];
  double terceraColumna;
  // FILE * fout = fopen("histograma.dat", "w");
  for (i = 1; i <= maximo; i++) {
    primeraColumna = i;
    segundaColumna[i - 1] = frecuencia(largoArray, array, i);
    terceraColumna = (double)(segundaColumna[i - 1]) / (double)(N * L);
    printf("%d\t%d\t%g\n", primeraColumna, segundaColumna[i - 1], terceraColumna);
    //printf("%d\t%g\t%g\n", primeraColumna, segundaColumna[i], terceraColumna);
  }
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
  int n, t;
  int extremo = 0;
  //Se crean arrays con longitud máxima definida mediante LENGTH
  int Huecos[LENGTH];
  int Array[LENGTH];
  
  //Se inicializa un bucle for con las instrucciones para cada una de las N cadenas
  for (t = 0; t < N; t++) {

    //Generación y guardado del poroso en el array "poroso"
    int poroso[L];
    generarPoroso(L, r, poroso);

	//Contaje de los ceros
    int a = 0;
    int contaje = 0;
    for (n = 0; n <= L; n++) {
      int numeroCeros = 0;
	  //Se cuentan los ceros consecutivos (de aquí en adelante, longitudes de hueco) y se almacenan en numeroCeros
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
    for (n = 0; n < contaje; n++) 
    {
      if (flag == 1 && Array[n] != 0)
        flag = 0;
      if (flag != 1) {
        //printf("%d,", Array[n]);
      }
    }
	//Para evitar que todas las cadenas sean iguales, se genera una espera de 1 segundo de forma que cambie la semilla
    sleep(1);

    /*Se genera el array "Huecos" con todas las longitudes de hueco de las N cadenas
     * Para ello, se define la variable "extremo", que representa la longitud del array Huecos y
     * se va actualizando tras cada paso del bucle al sumar contaje
     * (es decir, la longitud de cada cadena de longitudes de hueco)*/
    int k = 0;
    for (n = extremo; n < extremo + contaje; n++) 
    {
      Huecos[n] = Array[k++];
    }
    extremo += contaje;
  }

  //Cálculo el valor máximo del array para determinar la última fila del histograma
  int maximo = hallarMaximo(Huecos, extremo);

  //Generación del histograma
  histograma(maximo, Huecos, extremo, N, L);

  return 0;
}

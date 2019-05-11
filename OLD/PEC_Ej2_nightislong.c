#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include <math.h>

#include <unistd.h>

#define LENGTH 10000

void aleatorios(int L, double r, int poroso[]) {
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

//Se halla el tamaño del arrayLimpio
int hallarLargoArrayLimpio(int tamanoSucio, int arraySucio[]) {
  int contador = 0;
  int j;
  for (j = 0; j <= tamanoSucio; j++) {
    if (arraySucio[j] != -1 && arraySucio[j] != 0) {
      contador++;
    }
  }
  return contador;
}

//Se rellena un nuevo array quitando -1s y 0s del arraySucio
void filtrarArray(int tamanoSucio, int arraySucio[], int arrayLimpio[]) {
  int vueltas = 0;
  int j;
  for (j = 0; j <= tamanoSucio; j++) {
    if (arraySucio[j] != -1 && arraySucio[j] != 0) {
      arrayLimpio[vueltas++] = arraySucio[j];
    }
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
//Generación del histograma de frecuencias
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
  //Salida del programa si no se introducen los tres argumentos esperados
  if (argc < 3) {
    printf("Uso del programa:\n %s <no.puntos, porosidad, número de cadenas>\n", argv[0]);
    exit(0);
  }
  //Longitud del poroso introducida por parametro
  int L = atoi(argv[1]); 
  //Porosidad del medio introducida por parametro
  double r = atof(argv[2]);
  //Número de cadenas introducido por parametro
  int N = atoi(argv[3]); 

  //Índices de los bucles
  int n, m, j, t;
  
  /*Array de la longitud de los huecos del poroso, cuya longitud es desconocida al inicio 
  por lo que se #define una longitud LENGTH suficientemente grande*/
  int huecos[LENGTH];
  
  //Variable que guarda la última posición que se rellena en cada bucle al generar el array huecos
  int place = 0;
 
 //Para las N cadenas se realizan los siguientes pasos
  for (t = 0; t < N; t++) {

    //Invocación de la función aleatorios para generar y guardar el poroso en el array poroso[L]
    int poroso[L];
    aleatorios(L, r, poroso);
    
    // Pinto el poroso (cadenas de 0 y 1)
    for (int j = 0; j < L; j++) {
      printf("%d, ", poroso[j]);
    }
    printf("\n");

   /* //Creación de un array auxiliar vacío de longitud L/2
    int grupoCeros[L];
    for (j = 0; j <= L; j++) {
      grupoCeros[j] = -1;
    }*/

   /* //Recorro el poroso y guardo el número de grupos de ceros y su tamaño HE CAMBIADO A L/2
    int grupoCeros [LENGTH];
    for (n = 0; n <= L; n++) {
      int m = n;
      int numeroCeros = 0;
      while (poroso[m] == 0) {
        numeroCeros++;
        m++;
      //printf("NUMERO ceros %d, ",numeroCeros);
      }
      n = m;
      grupoCeros[m] = numeroCeros;
   
    }
    */
    int numeroCeros, microarray[LENGTH],miniarray[LENGTH];
    for(n=0;n<L;n++){
		int numeroCeros = 0;
		int m = n;
		if(poroso[m]==0&& m < L){
			numeroCeros++;
			m++;
			microarray[m]=numeroCeros;
		}
		if(poroso[m]==1){break;}
	printf("numero ceros es %d\n",numeroCeros);
		
	}
	int suma=0;
	for(int i=0;i<L;i++){
		suma += microarray[i]; 
	}
	printf("suma %d\n",suma);
	
    
    
    /*printf("\n");
    printf("Grupo ceros");
    for (int j = 0; j <= L; j++) {
      printf("%d, ", grupoCeros[j]);
    }
    printf("\n");
    printf("\n"); 
   //Filtrar el array que he obtenido
    int largoArrayLimpio = hallarLargoArrayLimpio(L, grupoCeros);
    int arrayLimpio[largoArrayLimpio];
    filtrarArray(L, grupoCeros, arrayLimpio);

    //Pinto los huecos
    /*for (n = 0; n < largoArrayLimpio; n++) {
      printf("%d, ", arrayLimpio[n]);
    }
    printf("\n");*/
    
    /*Para conseguir N cadenas distintas, se espera 1 segundo antes de 
    generar la siguiente cadena para evitar que la semilla coincida*/
    sleep(1);
    /*
    //Creo un array con todos los valores anteriores de huecos de las N cadenas
    int i, j;
    int k = 0;
    for (j = place; j < place + largoArrayLimpio; j++) {
      huecos[j] = arrayLimpio[k++];
    }

    //printf("ultima posicion era %d\n",place);
    place += largoArrayLimpio;

    //Pinto el array todos huecos
    /*for (n = 0; n < place; n++) {
      printf("%d, ", huecos[n]);
    }
    printf("\n");*/
  }
 /* 
  //Hallo el mínimo y el máximo dentro del array ya filtrado
  int maximo = hallarMaximo(huecos, place);
  //printf("El valor maximo del array huecos es %d\n", maximo);

  //Genero el histograma
  histograma(maximo, huecos, place, N, L);
*/
  return 0;
}

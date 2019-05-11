#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void imprimirArray(int longitud, int array[], char *nombreArray) {
    printf("Inicio %s\n", nombreArray);
    for (int j = 0; j < longitud; j++) {
        printf("%d, ", array[j]);
    }
    printf("\nFin %s\n", nombreArray);
}

void inicializarRandom(int numeroCalentamientos) {
    int semilla = (int) time(NULL);
    srand(semilla);

    for (int n = 0; n < 2 * numeroCalentamientos; n++) {
        rand();
    }
}

void generarPoroso(double porosidadDelMedio, int longitudPoroso, int poroso[]) {
    double p = 1 / (1 + porosidadDelMedio); //Probabilidad de opacos en el poroso
    int n; //Índice de los bucles
    double rnd; //Números aleatorios generados
    char result; //Variable auxiliar que almacenará los valores del medio poroso

    /* Si la longitud del poroso provista
     * es menor que 1, la ajusto a 1*/
    if (longitudPoroso < 1) {
        longitudPoroso = 1;
    }

    inicializarRandom(longitudPoroso);

    //Generación y guardado del poroso
    for (n = 0; n < longitudPoroso; n++) {
        rnd = (double) rand() / (RAND_MAX + 1.0);
        if (rnd <= p) {
            result = 1;
        } else {
            result = 0;
        }
        poroso[n] = result;
    }

    imprimirArray(longitudPoroso, poroso, "Poroso");
}


void comprobarArgumentos(int argc, char **argv) {
    if (argc < 3) {
        printf("Uso del programa:\n %s <no.puntos, porosidad, número de cadenas>\n", argv[0]);
        exit(0);
    }
}

void guardarPosicionesCeros(int longitudPoroso, int poroso[], int indicesCeros[]) {
    int indiceAux = 0;
    for (int i = 0; i < longitudPoroso; i++) {
        if (poroso[i] == 0) {
            indicesCeros[indiceAux++] = i;
        }
    }
    imprimirArray(indiceAux, indicesCeros, "Indices Ceros");
}

int hallarLargoSaltandoNumeros(int numeroQueMeSalto, int longitudMaxima, int *array) {
    int contador = 0;
    int j;
    for (j = 0; j <= longitudMaxima; j++) {
        if (array[j] != numeroQueMeSalto) {
            contador++;
        }
    }
    return contador;
}

void rellenarDeMenosUnos(int longitud, int *array) {
    for (int j = 0; j <= longitud; j++) {
        array[j] = -1;
    }
}

int posicionAleatoriaDeCero(int longitud, int *array) {
    int indicesCeros[longitud];
    rellenarDeMenosUnos(longitud, indicesCeros);
    guardarPosicionesCeros(longitud, array, indicesCeros);
    int longitudArrayIndices = hallarLargoSaltandoNumeros(-1, longitud, indicesCeros);

    inicializarRandom(longitud);
    int randomIndice = rand() % longitudArrayIndices;
    return indicesCeros[randomIndice];
}


int contarCerosAlLado(char *lado, int primeraPosicion, int longitud, int *array) {
    int cerosAlLado = 0;
    if (strncmp("I", lado, 1) == 0) {
        for (int j = primeraPosicion - 1; j >= 0; j--) {
            if (array[j] == 0) {
                cerosAlLado++;
            } else {
                break;
            }
        }
    } else {
        for (int j = primeraPosicion + 1; j < longitud; j++) {
            if (array[j] == 0) {
                cerosAlLado++;
            } else {
                break;
            }
        }
    }
    return cerosAlLado;
}

double mediaArray(int longitud, int *array) {
    double suma = 0;
    for(int j = 0; j<longitud;j++){
        suma +=array[j];
    }
    return suma/(double)hallarLargoSaltandoNumeros(0, longitud, array);
}

int main(int argc, char **argv) {
    comprobarArgumentos(argc, argv);

    int L = atoi(argv[1]); //Longitud del poroso
    double r = atof(argv[2]); //Porosidad del medio
    int N = atoi(argv[3]); //Número de cadenas

    int numeroCerosACoger = N / 16;

    char *lados[2] = {"I", "D"};

    int cerosLados[N * numeroCerosACoger];
    int indiceCerosLados = 0;

    for (int i = 0; i < N; i++) {

        printf("POROSO %d\n", i + 1);

        int poroso[L];
        generarPoroso(r, L, poroso);

        for (int k = 0; k < numeroCerosACoger; k++) {

            int randomPosicionDeCero = posicionAleatoriaDeCero(L, poroso);
            printf("El poroso[%d] es %d\n", randomPosicionDeCero, poroso[randomPosicionDeCero]);

            int randomLadoIndice = rand() % 2;
            char *lado = lados[randomLadoIndice];
            printf("El lado elegido es %s\n", lado);

            int cerosAlLado = contarCerosAlLado(lado, randomPosicionDeCero, L, poroso);

            printf("El número de ceros a la %s de poroso[%d] es %d\n", lado, randomPosicionDeCero, cerosAlLado);

            cerosLados[indiceCerosLados++] = cerosAlLado;
            sleep(1);
        }
    }

    imprimirArray(N*numeroCerosACoger, cerosLados, "Ceros Lados");


    double media = mediaArray(N*numeroCerosACoger, cerosLados);

    printf("La media es %g\n", media);

    return 0;
}
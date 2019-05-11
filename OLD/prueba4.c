#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define L 40

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

int main(int argc, char **argv) {
    int m, j, n;
    int poroso[20] = {0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0};
    int semilla = (int) time(NULL);
    srand(semilla);

    int grupoCeros[L];
    for (j = 0; j <= L; j++) {
        grupoCeros[j] = -1;


        int randomIndex = rand() % 20;
        int randomValue = poroso[randomIndex];
        printf("Reference: %d\n", randomValue);

        if (randomValue == 0) {

            printf("Reference1: %d\n", randomValue);
            printf("Ceros derecha\n");
            int numeroCeros = 0;
            int m;
            for (n = 0; n < L; n++) {
                m = n;
                if (poroso[m] == 0) {
                    numeroCeros++;
                    m++;
                }
                n = m;
                grupoCeros[m] = numeroCeros;
                printf("%d\n", numeroCeros);
            }
            //Filtrar el array que he obtenido
            int largoArrayLimpio = hallarLargoArrayLimpio(L, grupoCeros);
            int arrayLimpio[largoArrayLimpio];
            filtrarArray(L, grupoCeros, arrayLimpio);


            for (int a = 0; a < largoArrayLimpio; a++) {
                printf("%d, ", arrayLimpio[a]);
            }
            printf("\n");
            if (poroso[m] == 1) {
                printf("terminar");
            }


        } else {
            printf("nada\n");
        }
    }
    return 0;
}

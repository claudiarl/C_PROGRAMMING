#ifndef _LIBPROBABILIDAD_H_
#define _LIBPROBABILIDAD_H_

#define SEMILLA 123L
#define LINEAL_A 65L
#define LINEAL_B 0L
#define CONGRUENCIA 509L

#define SEMILLA 12345L
#define LINEAL_A 1944L
#define LINEAL_B 0L
#define CONGRUENCIA 32749L

#define SEMILLA 12345678L
#define LINEAL_A 16807L
#define LINEAL_B 0L
#define CONGRUENCIA 2147483647L

#define SEMILLA 1234567891LL
#define LINEAL_A 1664525LL
#define LINEAL_B 1013904223LL
#define CONGRUENCIA 4294967296LL

#define NUNIFORMES 100
#define NHISTOGRAMA 1000

double normal();
double uniforme();
void histograma(int npts,double x[],int nhis, int histo[], double x_min, double x_max);

#endif

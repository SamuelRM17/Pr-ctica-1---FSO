#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>

int main()
{
    long long start_ts;
    long long stop_ts;
    long long elapsed_time;
    struct timeval ts; 
				   
    gettimeofday(&ts, NULL);
    start_ts = ts.tv_sec; //Tiempo inicial

    //Inicio del cálculo de pi
    long long n_intervalos = 1000000000;
    long double suma = 0.0; //Cambiado a double para mayor precisión
    long double calc = 0.0; 
    long double valor_min = (1.0 / n_intervalos); // Ancho del intervalo

    //1/4 del círculo
    for (int i = 0; i < n_intervalos; i++) {
        long double x_medio = (i + 0.5) * valor_min; 
        calc = sqrt(1 - x_medio * x_medio); 
        suma += calc; 
    }

    //Como es 1/4 del círculo, lo multiplicamos por 4 y por el ancho del intervalo
    suma *= valor_min * 4; 

    //Imprimir el resultado
    printf("suma = %.15Lf\n", suma); // Cambiado a %f para imprimir en float
	
    gettimeofday(&ts, NULL);
    stop_ts = ts.tv_sec; //Tiempo final

    elapsed_time = stop_ts - start_ts;
    printf("------------------------------\n");
    printf("TIEMPO TOTAL, %lld segundos\n", elapsed_time);

    return 0; // Asegurarse de retornar 0
}

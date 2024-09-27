#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

#define SIZE 2000
int nthreads;
int a[SIZE][SIZE],b[SIZE][SIZE],c[SIZE][SIZE]; 

void *tfunc(void *args)
{
	int nthread=*((int *) args);
	int inicio=nthread*(SIZE/nthreads);
	int fin=(nthread+1)*(SIZE/nthreads);
	
	int i,j,k;

	printf("Hilo %d va desde %d hasta %d\n",nthread,inicio,fin);

	for(i=inicio;i<fin;i++)
		for(k=0;k<SIZE;k++)
			for(j=0;j<SIZE;j++)
				c[i][j]=c[i][j]+a[i][k]*b[k][j];

}

int main()
{
	long long start_ts;
	long long stop_ts;
	long long elapsed_time;
	struct timeval ts;
	int i;
	pthread_t *tid;
	int *args;

	// Use sysconf to get the number of processors
	nthreads = sysconf(_SC_NPROCESSORS_ONLN);
	
	tid = malloc(nthreads * sizeof(pthread_t));
	args = malloc(nthreads * sizeof(int));		   
				   
	gettimeofday(&ts, NULL);
	start_ts = ts.tv_sec; // Tiempo inicial

	// Crear los hilos
	for(i=0;i<nthreads;i++)
	{
		args[i]=i;
		pthread_create(&tid[i],NULL,tfunc,(void *) &args[i]);
	}

	// Esperar a que terminen los hilos
	for(i=0;i<nthreads;i++)
		pthread_join(tid[i],NULL);
	
	gettimeofday(&ts, NULL);
	stop_ts = ts.tv_sec; // Tiempo final
	elapsed_time = stop_ts - start_ts;
	printf("------------------------------\n");
	printf("TIEMPO TOTAL, %lld segundos\n",elapsed_time);
}

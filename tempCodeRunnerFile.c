int n_intervalos = 100000;
    float suma = 0;
    float calc = 0;
    long double valor_min = (1.0/n_intervalos);

    printf("valor min: %Lf\n", valor_min);

    //1/4 del círculo
    for (float i = 0.0; i < n_intervalos; i++){
        calc = sqrt(1 - i/n_intervalos * i/n_intervalos);
        suma += calc;
    }
    //Como es 1/4 del círculo, lo multiplicamos por 4
    suma = suma * 4;
    printf("suma = %f", suma);
	
	gettimeofday(&ts, NULL);
	stop_ts = ts.tv_sec; // Tiempo final

	elapsed_time = stop_ts - start_ts;
	printf("------------------------------\n");
	printf("TIEMPO TOTAL, %lld segundos\n",elapsed_time);
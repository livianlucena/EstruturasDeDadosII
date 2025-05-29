#include <stdio.h>
#include <time.h>
#include <locale.h>

int x(int);

int main(){
    int n = 40;  
    int N_Max = 1000;
    double tempo_total = 0;
    
    for(int i = 0; i < N_Max; i++){
        clock_t start = clock();
        x(n);
        clock_t end = clock();
        tempo_total += (double)(end - start) / CLOCKS_PER_SEC;
    }
    printf("Tempo médio: %f segundos. \n", tempo_total / N_Max);
    return 0;
}

int x(int n){
    if(n <= 1){
        return 1;
    } else{
        return x(n-1) + x(n-2);
    }
}
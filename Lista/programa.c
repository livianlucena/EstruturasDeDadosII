#include <stdio.h>
#include <locale.h>

int x(int);

int main(){
    int n = 10;
    printf("%d\n", x(10));
    return 0;
}

int x (int n){
    if(n <= 1){
        return 1;
    } else{
        return x(n-1) + x(n-2);
    }
}
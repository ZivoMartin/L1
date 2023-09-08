#include <stdio.h>

void isocele(int n){
    int i;
    int j;
    int N;
    if (n%2 == 0){
            N = 2*n-1;
        }
    else{
        N = 2*n;
    }
    int k = N/2;
    for (i = 1; i <= N; i = i + 2){
        for (int j = 1; j<=k; j = j + 1){
            printf(" ");
        }
        for (int h = 1; h <= i; h = h + 1){
            printf("*");
        }
        k = k - 1;
        printf("\n");
        }
}

int main(){
    isocele(5);
    return 0;
}
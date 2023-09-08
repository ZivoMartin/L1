#include <stdio.h>
#include <stdlib.h>  

void mult_table(int n){
    int i;
    int j;
    for (i = 1; i<=n; i = i +1){
        for (j = 1; j<=n; j = j + 1){
        printf("%d ", i*j);
        }
    printf("\n");
    }
}

int main(){
    mult_table(6);
    return 0;
}
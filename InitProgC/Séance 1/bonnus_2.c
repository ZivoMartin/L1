#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void binaire(int num){
    int n = 0;
    while(pow(2, n) < num){
        n = n + 1;
    }
    n = n - 1;
    while(n >= 0){
        if(num >= pow(2, n)){
            printf("1");
            num = num - pow(2, n);
        }
        else{
            printf("0");
        }
        n = n - 1;
    }

}

int main(){
    int num = 15;
    binaire(num);
    return EXIT_SUCCESS;
}
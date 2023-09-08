#include <stdio.h>
#include <stdlib.h> 

long int sum_multiple_3(unsigned int n){
    int result = 0;
    if(n <= 1){
        return -1;
    }
    if(n== 2){
        return 0;
    }
    for(int i = 3; i<=n; i = i + 3){
        result = result + i;
    }
    return result;
}

int main(){
    printf("%ld\n", sum_multiple_3(1));
    return EXIT_SUCCESS;
}
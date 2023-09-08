#include <stdio.h>
#include <stdlib.h>

float perimeter(unsigned r){
    float PI = 3.14159;
    float result = PI*2*r;
    return result;
}

int main(){
    printf("%f\n", perimeter(-100));
    return EXIT_SUCCESS;
}
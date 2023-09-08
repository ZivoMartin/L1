#include <stdio.h>
#include <stdlib.h>

long int poow(int x, int y){
    long int result = 1;
    for(int i = 0; i<y; i++){
        result = result*x;
    }
    return result;
}

unsigned int integer_convert(short int t[], unsigned int size){
    int result = 0;
    for(int i = size - 1; i >= 0; i = i - 1){
        if(t[i]<0 || t[i]>9){
            fprintf(stderr, "vous devez composer votre tableau de chiffres uniquement\n");
            exit(EXIT_FAILURE);
        }
        result = result + t[i]* poow(10, (size - 1) - i);
    }
    return result;
}

int main(void) {
    short int t[] =  { 6, 4, 4, 4, 7, 9, 1, 3, 0 };
    printf("%u", integer_convert(t, 9));
    return EXIT_SUCCESS;
}
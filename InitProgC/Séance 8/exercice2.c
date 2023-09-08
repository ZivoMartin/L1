#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *maxLength(char *t[], int size, int i, int j){
    if(size==1){
        fprintf(stderr, "Bad arguments");
        exit(EXIT_FAILURE);
        }
    if(i == size){
        return t[j];
    }
    if(strlen(t[i]) > strlen(t[j])){
        maxLength(t, size, i+1, i);
    }else{
        maxLength(t, size, i+1, j);
    }
}

int main(int arg_count, char* arg_values[]) {
    printf("%s\n", maxLength(arg_values, arg_count, 1, 1));
    return EXIT_SUCCESS;
}
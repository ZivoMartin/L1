#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count(int t[], int size){
    if(size == 0){
        return 0;
    }
    long int result = t[0];
    for(int i = 1; i<size; i = i + 1){
        result = result + t[i];
    }
}

int main(int arg_count, char* arg_values[]){
    int t[arg_count-1];
    for(int i = 0; i+1<arg_count; i = i + 1){
        t[i] = atoi(arg_values[i+1]);
    }
    printf("%d", count(t, (arg_count-1)));
}
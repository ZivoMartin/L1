#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool existDuplicateString(char *t[], int size){
    if(size==0) return false;
    for(int i = 0; i<(size-1); i = i + 1){
        for(int j = i+1; j<size; j = j + 1){
            if(strcmp(t[i], t[j]) == 0){
                return true;
            }
        }
    }
    return false;
}
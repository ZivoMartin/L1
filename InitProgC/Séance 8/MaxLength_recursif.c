#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *maxLength(char *t[], int size, int i, int j){
    if(size==0){
        exit(EXIT_SUCCESS);
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

int main(){
    char *word1 = "Bonjour";
    char *word2 = "ornn";
    char *t[2] = {word1, word2};
    printf("%s\n", maxLength(t, 2, 0, 0));
}
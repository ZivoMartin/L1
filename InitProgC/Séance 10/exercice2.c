#include <stdlib.h>
#include <stdio.h>




long last_duplicate(char *s){
    if(s == NULL){
        return NULL;
    }
    int *p = s;
    char *result = NULL;
    while(*p != '\0'){
        while(*(p+1) == *p){
            result = p;
            p += 1;
        }
        p += 1;
    }
    return result;
}

int main(int arg_count, char *arg_value[]){
    return(EXIT_SUCCESS);
}
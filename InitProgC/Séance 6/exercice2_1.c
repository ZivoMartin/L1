#include <stdio.h>
#include <stdlib.h>

int string_len(char *s){
    int i;
    for( i=0; *(s+i) != '\0'; i=i+1)
        ;
    return i;
}

int nb_occurrences(char *s, char c){
    if(s==NULL){
        exit(EXIT_FAILURE);
    }
    int nb = 0;
    for (char *p = s; *(p) != '\0'; p=p+1){
        if (*(p) == c){
            nb=nb+1;
        }
    }
    return nb;
}


void replace_occurrences(char *s, char remplace, char remplacant){
    if(s == NULL){
        exit(EXIT_FAILURE);
    }
    for (char *p = s; *(p) != '\0'; p=p+1){
        if (*(p) == remplace){
            *p = remplacant;
        }
    }  
}

int main(void) {
    /*TO BE COMPLETED*/
    return EXIT_SUCCESS;
}




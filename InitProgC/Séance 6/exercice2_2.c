#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int string_len(char *s){
    char *p;
    for(p=s; *(p) != '\0'; p=p+1);
    return p-s;
}

int nb_occurrences(char *s, char c) {
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

void string_to_uppercase(char *s){
    if(s == NULL){
        exit(EXIT_FAILURE);
    }
    for (char *p = s; *(p) != '\0'; p=p+1){
        *p = toupper(*p);
    }  
}

int main(void) {
    /*TO BE COMPLETED*/
    return EXIT_SUCCESS;
}




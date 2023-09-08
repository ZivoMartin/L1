#include <stdio.h>
#include <stdlib.h>

#ifndef NONE
#define NONE -1
#endif

int index_last_occurrence(char t[], char c){
    int result = NONE;
    int i = 0;
    while(t[i] != '\0'){
        if(t[i] == c){
            result = i;
        }
        i = i + 1;
    }
    return result;
}

int main(void) {
    char s[] = {'b','o','n','j','o','u','r','\0'};
    printf("%d\n%d\n", index_last_occurrence(s, 'o'), index_last_occurrence(s, 'x'));
    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    
    char s[]= {'H','e','l','l','o','\0'};
    
    
    for (int i= strlen(s); i>0; i=i-1){
        s[i]= '\0';
        printf("i=%d, s=%s\n",i, s);
    }
    
    printf("%s\n",s);
    return EXIT_SUCCESS;
}
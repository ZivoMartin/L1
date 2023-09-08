#include <stdio.h>
#include <stdlib.h>

void multiply_tab_v2(int *t, int size, int coef){
    
    for(int *p = t; p< t+size && p != NULL; p = p + 1){
        *p = *p * coef;
    }
}

int main(void) {
return EXIT_SUCCESS;
}




#include <stdio.h>
#include <stdlib.h>

void display_full_tab(unsigned int tab[], int tab_size){
    printf("[ ");
    for(int i = 0; i < tab_size; i++){
        printf("%u ", tab[i]);
    }
    printf("]\n");
}
int main(void) {
    unsigned int t[]={1,2,3};
    display_full_tab(t,3);
    return EXIT_SUCCESS;
}




#include <stdio.h>
#include <stdlib.h>

void display_tab(unsigned int tab[], unsigned int tab_size, unsigned int n ){
    if (n>tab_size){
        n = tab_size;
    }
    printf("[ ");
    for(int i = 0; i < n; i++){
        printf("%u ", tab[i]);
    }
    printf("]\n");
}
    
int main(void) {
    int t[4] = {0, 1, 2, 3};
    display_tab(t, 4, 2);
    return EXIT_SUCCESS;
}
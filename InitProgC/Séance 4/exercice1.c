#include <stdio.h>
#include <stdlib.h>

int tab_size = 5;
int tab[10]= {2,-3, 4, 8, 1};//Can contain up to 10 elements

int main(void) {
printf("[ ");
    for(int i = 0; i < tab_size; i++){
        printf("%d ", tab[i]);
        tab[i] = tab[i] = tab[i] * 2;
    }
    printf("]\n");
    printf("[ ");
    for(int i = 0; i < tab_size; i++){
        printf("%d ", tab[i]);
    }
    printf("]\n");

  return EXIT_SUCCESS;
}
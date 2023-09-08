#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int nb1 = -10;
    unsigned int nb2 = 10;
    float nb3 = 64.2;
    double nb4 = 0.001;
    long int nb5 = 10;
    unsigned long nb6 = 10;
    long int nb7 = -10;
    unsigned long nb8 = -10;
    char nb9 = 'A';
    printf("%d <-> %lu\n", nb1, sizeof(nb1));
    printf("%u <-> %lu\n", nb2, sizeof(nb2)); 
    printf("%f <-> %lud\n", nb3, sizeof(nb3)); 
    printf("%lf <-> %lu\n", nb4, sizeof(nb4)); 
    printf("%ld <-> %lu\n", nb5, sizeof(nb5)); 
    printf("%lu <-> %lu\n", nb6, sizeof(nb6)); 
    printf("%ld <-> %lu\n", nb7, sizeof(nb7)); 
    printf("%lu <-> %lu\n", nb8, sizeof(nb8)); 
    printf("%c <-> %lu\n", nb9, sizeof(nb9)); 
    return EXIT_SUCCESS;
}

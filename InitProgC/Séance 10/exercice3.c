#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef unsigned int uint;

typedef struct{
    int logi;
    int prog;
    int web;
    int algebre;
} gradebook_t;


double mean(gradebook_t g){
    return((g.logi + g.prog + g.web + g.algebre)/4.0);
}

bool best_mean(gradebook_t tab[], uint size, double *best){
    if(size == 0){
        return false;
    }
    *best = mean(tab[0]);
    for(int i=1; i<size; i++){
        double m = mean(tab[i]);
        if(*best < m){
            *best = m;
        }
    }
    return true;
}

void afficher(gradebook_t g){
    printf("developpement logiciel: %d\n", g.logi);
    printf("programation C: %d\n", g.prog);
    printf("Programation web: %d\n", g.web);
    printf("Algèbre linéaire: %d\n", g.algebre);
}

int main(int arg_count, char *arg_value[]){
    return(EXIT_SUCCESS);
}
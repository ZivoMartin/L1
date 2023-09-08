#include <stdio.h>
#include <stdlib.h>
struct res_min_max{
    int min;
    int max;
};
typedef struct res_min_max res_min_max_t;

int get_min(res_min_max_t nbr){
    return(nbr.min);
}
int get_max(res_min_max_t nbr){
    return(nbr.max);
}

void tab_min_max(int t[], int size, res_min_max_t * minmax){
    if(minmax==NULL || size == 0) return;
    minmax->min = t[0];
    minmax->max = t[0];
    for(int *p = t; (p-t)<size; p = p + 1){
        if(*p >minmax->max) minmax->max = *p;
        else if(*p <minmax->min) minmax->min = *p;
    }
}

int main(void) {
  return EXIT_SUCCESS;
}




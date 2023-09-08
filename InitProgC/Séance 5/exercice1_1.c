#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool minmax1(int t[], unsigned int size, int* max, int* min){
    if(size==0 || max == NULL || min == NULL){
        return(false);
    }
    *min  = t[0];
    *max  = *min;
    for(int i = 1; i<size; i++){
        if(t[i] > *max){
            *max = t[i];
        }
        else if(t[i] < *min){
            *min = t[i];
        }
    }
    return true;
}
int main(void) {
    int min = 0;
    int max = 0;
    int t1[] = {69, -31, -95, 78, -28, -23, 61, 10, 80, 10};
    int t2[] = {};
    int t3[] = {6};
    printf("%d ", minmax1(t1, 5, &max, &min));
    printf("max : %d, min : %d\n", max, min);
    printf("%d\n", minmax1(t2, 0, &max, &min));
    printf("%d ", minmax1(t3, 1, &max, &min));
    printf("max : %d, min : %d\n", max, min);
    return EXIT_SUCCESS;
}
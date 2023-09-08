#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool max1(int t[], unsigned int size, int mm[]){
    if(size==0){
        return(false);
    }
    mm[0]  = t[0];
    mm[0]  = mm[0];
    for(int i = 1; i<size; i++){
        if(t[i] > mm[1]){
            mm[1] = t[i];
        }
        else if(t[i] < mm[0]){
            mm[0] = t[i];
        }
    }
    return true;
}
int main(void) {
    int mm[] = {0, 0};
    int t1[] = {0, 5, 9, -2, 6};
    int t2[] = {};
    int t3[] = {6};
    printf("%d ", max1(t1, 5, mm));
    printf("max : %d, min : %d\n", mm[1], mm[0]);
    printf("%d\n", max1(t2, 0, mm));
    printf("%d ", max1(t3, 1, mm));
    printf("max : %d, min : %d\n", mm[1], mm[0]);
    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    
    int minInt = INT_MIN;
    int maxInt = INT_MAX;
    
    printf("%d - %d\n",minInt, maxInt);
    minInt=minInt-1;
    maxInt=maxInt+1;
    printf("%d - %d\n",maxInt, minInt);

    return EXIT_SUCCESS;
}
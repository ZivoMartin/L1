#include <stdio.h>
#include <stdlib.h>

int pits_count(int t[], int size){
    int result = 0;
    for(int i = 1; i < size-1; i++){
        if(t[i] < t[i-1] && t[i] < t[i+1]){
            result += 1;
        }
    }
    return result;
}
int main(void) {
    int t[] = {1, 0, 1, -6, 9, 1};
    printf("%d", pits_count(t, 6));
    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>

unsigned int longest_eq_sequence(int t[], int size){
    if(size == 0){
        return 0;
    }
    int max = 1;
    int repet = 1;
    for(int i = 1; i < size; i++){
        if(t[i] == t[i-1]){
            repet = repet + 1;
            if(repet>max){
                max = repet;
            }
        }
        else{
            repet = 1;
        }
    }
    return max;
}
int main(void) {
    int t1[] = {0, 5, 5, 8, 6, 6, 6};
    int t2[] = {0, 5, 2, 8, 2, 9, 6};
    printf("%d\n%d", longest_eq_sequence(t1, 7), longest_eq_sequence(t2, 7));
    return EXIT_SUCCESS;
}
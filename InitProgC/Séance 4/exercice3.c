#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_square_array(unsigned int t[], unsigned int size, unsigned int n){
    if(n==0){
        return true;
    }
    if(n%2==1){
        return false;
    }
    for(int i = 0; i < n/2; i ++){
        if(t[i] != t[i + n/2]){
            return false;
        }
    }
    return true;
}

int main(void) {
    unsigned int t1[] = {0, 1, 2, 0, 1, 2};
    unsigned int t2[] = {};
    unsigned int t3[] = {0, 1, 2, 0, 1};
    unsigned int t4[] = {0, 1, 2, 0, 0};
    printf("%d, %d, %d, %d", is_square_array(t1, 6, 6), is_square_array(t2, 0, 0), is_square_array(t3, 5, 5), is_square_array(t4, 6, 6));
    return EXIT_SUCCESS;
}
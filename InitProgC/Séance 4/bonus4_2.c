#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_sub_array(int t1[], int size1, int t2[], int size2){
    if(size2 == 0){
        return true;
    }
    int stack = 0;
    for(int i = 0; i < size1; i++){
        if(t1[i] == t2[stack]){
            stack = stack + 1;
            if(stack == size2){
                return true;
            }
        }
    }
    return false;
}

int main(void) {
    int t1[] = {1, 2, 1, 3, 4, 5};
    int t2[] = {1, 4};
    int t3[] = {9};
    printf("%d\n%d", is_sub_array(t1, 6, t2, 2), is_sub_array(t1, 6, t3, 1));
    return EXIT_SUCCESS;
}
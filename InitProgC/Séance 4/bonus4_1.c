#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_factor(int t1[], int size1, int t2[], int size2){
    if(size2 == 0){
        return true;
    }
    int stack = 0;
    int i = 0;
    while(i < size1){
        if(t1[i] == t2[stack]){
            stack = stack + 1;
            if(stack == size2){
                return true;
            }
            i = i + 1;
        }
        else{
            if(stack!=0){
                stack = 0;
            }
            else{
                i = i + 1;
            }
        }
    }
    return false;
}

int main(void) {
    int t1[] = {4, -3, 2};
    int t2[] = {2};
    int t3[] = {9};
    printf("%d\n%d", is_factor(t1, 3, t2, 1), is_factor(t1, 6, t3, 1));
    return EXIT_SUCCESS;
}
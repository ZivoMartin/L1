#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool exist_double_occurrence(int t[], unsigned int size){
    if(size == 0){
        return true;
    }
    for(int i = 0; i < size-1; i++){
        for(int j = i+1; j < size; j++){
            if(t[i] == t[j]){
                return true;
            }
        }
    }
    return false; 
}

int main(void) {
    int t1[] = {0, 8, 9, 0};
    int t2[] = {0, 8, 9, 2};
    int t3[] = {0, 8, 9, 9};
    printf("%d\n%d\n%d\n", exist_double_occurrence(t1, 4), exist_double_occurrence(t2, 4), exist_double_occurrence(t3, 4));
}
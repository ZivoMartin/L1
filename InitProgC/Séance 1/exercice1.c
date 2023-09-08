#include <stdio.h>
#include <stdlib.h>

int compare_to_interval(int a, int b, int x){
   if (x < a){
        return -1;
   } if (b < x) {
        return 1;
    } else {
        return 0;
    } 
}

int main(){
    printf("%d\n", compare_to_interval(2, 3, 0));
    return EXIT_SUCCESS;
}
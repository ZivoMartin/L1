#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fermat(){
    int y;
    for(y = 0; y<=100; y = y + 1){
        int x = sqrt(2*y*y + 1);
        if (x*x-2*y*y == 1){
            printf("x = %d, y = %d`\n", x, y);
        }
    }
    return 0;
}

int main(){
    fermat();
    return 0;
}
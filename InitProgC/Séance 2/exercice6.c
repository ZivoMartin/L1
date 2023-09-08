

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    float a = 7.95;
    a = a * 3.0;
    float b = 7.95 * 3.0;
    float c = 7.95f * 3.0;
    printf("%f = %f = %f !!!\n",a, b, c);
    printf("%d\n%d", sizeof(7.95f), sizeof(7.95));

    return EXIT_SUCCESS;
}
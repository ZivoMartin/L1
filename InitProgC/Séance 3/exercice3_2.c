#include <stdio.h>
#include <stdlib.h>

void f (void){
    int a = 10;
    a = a+1;
    printf("In f(): a = %d\n", a);
}

void display (int a) {
    printf("In display(): a = %d\n", a);
}

int main(void) {
    int a = 5, b = 12;
    f();
    display(a);
    printf("In main(): a = %d\n", a);
    display(b);
    return EXIT_SUCCESS;
}

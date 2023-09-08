#include <stdio.h>
#include <stdlib.h>  

#ifndef N
    #define N 10
#endif
#ifndef J 
    #define J 4
#endif

int main(void){
  double n = N;
  int j = J;
  double r = n;
  if (n<0 || j<=1 || j>=50){
    printf("At least one of the parameters is wrong!\n");
  }
  else{
    printf("Approximation 1 of square root of %lf is %lf\n", n, r);
    for(int i = 2; i<=j; i = i + 1){
        r = (r + n/r)/2;
        printf("Approximation %d of square root of %lf is %lf\n", i, n, r);
    }
  }
  
  return EXIT_SUCCESS;
}


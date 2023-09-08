#include <stdio.h>
#include <stdlib.h>  
#ifndef N
#define N 10
#endif

int main(){
  int p2 = 1;
  int i = 1;
  do {
    i = i + 1;
    p2 = p2*2;
  } while (i <= N);
  printf("%d\n",p2);
  return EXIT_SUCCESS;
}
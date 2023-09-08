#include <stdio.h>
#include <stdlib.h>  
#ifndef N
#define N 10
#endif

int main(void){
  int p2 = 1;
  int i = 0;
  while(i < N){
    p2 = p2*2;
    i = i + 1;
  }
  printf("%d\n",p2);
  return EXIT_SUCCESS;
}
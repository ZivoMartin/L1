#include <stdio.h>
#include <stdlib.h>  
#ifndef N
#define N 10
#endif

int main(void){
  int p2 = 1;
  int i;
  for (i = 1; i<=N; i = i + 1) {
    p2 = p2*2;
  }
  printf("%d\n",p2);
  return EXIT_SUCCESS;
}
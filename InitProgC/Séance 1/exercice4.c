#include <stdio.h>
#include <stdlib.h>

int reverse(int nombre){
  int signe = 0;
  if (nombre < 0){
    signe = -1;
    nombre = -nombre;
  }
  int result = 0;
  while (nombre != 0){
    result = result*10 + nombre%10;
    nombre = nombre/10;
  }
  if (signe == -1){
    return -result;
  }
  return result;
}

int main(){
  printf("%d",reverse(54));
  return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>

unsigned long factorial (int nombre){
  unsigned long result = nombre;
  if (nombre < 0 || nombre >= 22){
    return 0;
  }
  if(nombre == 0){
    return 1;
  }
  int facteur = nombre - 1;
  while (facteur > 1){
    result = result*facteur;
    facteur = facteur - 1;
  }
  return result;
}

int main(){
  printf("%ld\n",  factorial(-4));
  return EXIT_SUCCESS;
}
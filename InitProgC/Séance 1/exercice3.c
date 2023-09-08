#include <stdio.h>
#include <stdlib.h>

int factorial (int nombre){
  if(nombre == 0){
    return 1;
  }
  int facteur = nombre - 1;
  while (facteur > 1){
    nombre = nombre*facteur;

    facteur = facteur - 1;
  }
  return nombre;
}

int main(){
  printf("%d\n",  factorial(6));
  return EXIT_SUCCESS;
}
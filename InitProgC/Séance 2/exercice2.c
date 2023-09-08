#include <stdio.h>
#include <stdlib.h>

 unsigned long int factorial (unsigned long int nombre){
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
  for(int i = 0; i<=25;i=i+1){
  printf("%ld, %d\n",  factorial(i), i);
  }
  return EXIT_SUCCESS;
}
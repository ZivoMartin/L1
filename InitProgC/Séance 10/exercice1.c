#include <stdlib.h>
#include <stdio.h>


void usage(){
    fprintf(stderr, "Ce programme prend en parametre trois entiers en binaire puis indique si le  troisième entier est la somme des deux autres.\n");
    fprintf(stderr, "Vous n'avez pas donné de bon parametre, merci de ne rentrer que des nombres binaires.");
    exit(EXIT_SUCCESS);
}

long convert_2_long(char *s){
    char erreur = '0';
    char *p_erreur = &erreur;
    int nb = strtol(s, &p_erreur, 2);
    if(*p_erreur != '\0'){
        usage();
    }
    return(nb);
}

int main(int arg_count, char *arg_value[]){
    if(arg_count != 4){
        usage();
    }
    long nb_1 = convert_2_long(arg_value[1]);
    long nb_2 = convert_2_long(arg_value[2]);
    long nb_3 = convert_2_long(arg_value[3]);

    printf("%d\n", (nb_1+nb_2==nb_3));
    return(EXIT_SUCCESS);
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void usage(char *name){
    fprintf(stderr, "Usage: %s base int\nwhere base is an unsigned value between 2 and 36\nand int is an integer.\nExample: convert_to_long 25 abba\n", name);
}

int main(int arg_count, char *arg_values[]) {
    if(arg_count != 3){
        usage(arg_values[0]);
        return EXIT_FAILURE;
    }
    char erreur = '0';
    char *p_erreur = &erreur;
    int b = strtoul(arg_values[1], &p_erreur, 10);
    if(*p_erreur != '\0' || b<2 || b>36){
        fprintf(stderr, "Malformed base argument : %s\n", arg_values[1]);
        usage(arg_values[0]);
        return EXIT_FAILURE;
    }
    long int result = strtoul(arg_values[2], &p_erreur, b);
    if(*p_erreur != '\0'){
        fprintf(stderr, "Malformed int argument (supposed to be encoded in base %d): %s\n", b, arg_values[2]);
        usage(arg_values[0]);
        return EXIT_FAILURE;
    }
    printf("%ld\n", result);
    return EXIT_SUCCESS;
}
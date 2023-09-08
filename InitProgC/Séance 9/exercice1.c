#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool minmax1(long int t[], unsigned int size, long int* min, long int* max){
    if(size==0 || max == NULL || min == NULL){
        return(false);
    }
    *min  = t[0];
    *max  = t[0];
    for(int i = 1; i<size; i++){
        if(t[i] > *max){
            *max = t[i];
        }
        else if(t[i] < *min){
            *min = t[i];
        }
    }
    return true;
}

void usage(char *name){
    fprintf(stderr, "Usage: %s size val1 val2 ...valsize\nwhere size is the number of elements in the array\nand val1, val2, ... are the elements of the array as integers.\nExample: tab_min_max 5 1 -3 5 6 -100\n", name);
}

int main(int arg_count, char* arg_values[]){
    if(arg_count == 1){
        usage(arg_values[0]);
        return EXIT_FAILURE;
    }
    char erreurSize = '0';
    char *p_erreur_size = &erreurSize;
    int size = strtoul(arg_values[1], &p_erreur_size, 10);
    if(*p_erreur_size != '\0' || size<=0){
        fprintf(stderr, "Malformed size argument : %s\n", arg_values[1]);
        usage(arg_values[0]);
        return EXIT_FAILURE;
    }else if(size != arg_count-2){
        fprintf(stderr, "Invalid number of arguments :");
        for(int j = 2; j<arg_count; j++){
            fprintf(stderr, " %s ", arg_values[j]);
        }
        fprintf(stderr, "\n");
        usage(arg_values[0]);
        return EXIT_FAILURE;
    }
    long int t[arg_count - 1];
    char erreur = '0';
    char *p_erreur = &erreur;
    for(int i = 2; i<arg_count; i=i+1){
        t[i-2] = strtoul(arg_values[i], &p_erreur, 10);
        if(*p_erreur != '\0'){
            fprintf(stderr, "Malformed value arguments detected :");
            for(int j = 2; j<arg_count; j++){
                fprintf(stderr, " %s ", arg_values[j]);
            }
            fprintf(stderr, "\n");
            usage(arg_values[0]);
            return EXIT_FAILURE;
        }
    }
    long int min;
    long int max;
    minmax1(t, size, &min, &max);
    printf("min: %ld max: %ld\n", min, max);
    return EXIT_SUCCESS;
}
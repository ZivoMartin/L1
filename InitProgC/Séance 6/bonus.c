#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool hms_to_spm(int heures, int minutes, int secondes, int *s){
    if(heures >= 24 || minutes >= 60 || secondes >= 60 || s == NULL) return false;
    *s = secondes + heures*3600 + minutes*60;
    return true;
}
bool spm_to_hms(int s, int *heures, int *minutes, int *secondes){
    if(s > 86400 || heures == NULL || minutes == NULL || secondes == NULL) return false;
    *heures = s/3600;
    s = s % 3600;
    *minutes = s/60;
    *secondes = s%60;
    return true;
}

int main(void) {
    /* TO BE COMPLETED */ 
    return EXIT_SUCCESS;
}
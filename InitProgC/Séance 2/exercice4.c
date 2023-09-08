/*
* Ecrivez un programme qui affiche le resultat des operations presentes dans 
* la fonction main et analysez les resultats afin de repondre au quizz.
* 
* Format de sortie (donnees fictives) - et rien d'autre :
*
* res1 = 154
* res2 = 52.000000
* res3 = 10
* res4 = 10.000000
* res5 = 0
* res6 = 22.000000
* res7 = 10
* Le bouton Run vous permet de tester votre code.
* Le bouton Evaluate vous permet d'évaluer votre code vis a vis des consignes et
* d'obtenir une note.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int nb1 = 5;
    int nb2 = 0;
    float nb3 = 2.0f;
    int res1 = nb1 + nb2;
    float res2 = nb1 + nb3;
    int res3 = nb1 + nb3;
    float res4 = nb1 / nb3;
    int res5 = nb1 / nb3;
    float res6 = nb1 / nb2;
    int res7 = nb1 / nb2;
    printf("res1 = %d\n", res1);
    printf("res2 = %f\n", res2);
    printf("res3 = %d\n", res3);
    printf("res4 = %f\n", res4);
    printf("res5 = %d\n", res5);
    printf("res6 = %f\n", res6);
    printf("res7 = %d\n", res7);
    
    return EXIT_SUCCESS;
}

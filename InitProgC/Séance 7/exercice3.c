#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

struct complex{
  double real;
  double img;
};

typedef struct complex complex_t;

typedef struct complex complex_t;

double get_real(complex_t *c){
    return(c->real);
}


double get_imaginary(complex_t *c){
        return(c->img);
}


double modulus(complex_t *c){
    return(sqrt(c->img*c->img + c->real*c->real));
}


double argument(complex_t *c){
    return(acos(c->real/modulus(c)));
}

bool equals_complex(complex_t *c1, complex_t *c2){
    if(c1->real == c2->real && c1->img == c2->img) return true;
    return false;
}


void display_complex(complex_t *c){
    printf("%lf + %lf i", c->real, c->img);
}

void complex(double a, double b, complex_t *new_c){
    new_c->real = a;
    new_c->img = b;
}


void conjugate_complex(complex_t *c, complex_t *conjugate){
    conjugate->real = c->real;
    conjugate->img = -(c->img);
}


void addition_complex(complex_t *c1, complex_t *c2, complex_t *res){
    res->real = c1->real + c2->real;
    res->img = c1->img + c2->img;
}


void subtraction_complex(complex_t *c1, complex_t *c2, complex_t *res){
    res->real = c1->real - c2->real;
    res->img = c1->img - c2->img;
}

//Add the complex pointed by to_be_added to the complex pointed by c 
// Hint: use the addition_complex function to compute c = c + to_be_added
void add_complex(complex_t *c, complex_t *to_be_added){
    void addition_complex(c, to_be_added, c);
}

int main(void) {
    complex_t c1 = (complex_t) {2.0, -6.0};
    printf("%4lf %+4lf i\n",get_real(&(c1)), get_imaginary(&(c1)));
    complex_t c2;
    complex(4.0, 3.0,&(c2)); 
    complex_t c3 = (complex_t) {4.0, 3.0};
    if (!equals_complex(&(c2), &(c3))){
        printf("c2 and c3 are not equal\n");
    }else{
        printf("c2 and c3 are equal\n");
    }
    complex_t c_sum;
    addition_complex(&(c1), &(c2), &(c_sum));
    add_complex(&(c1), &(c2));
    if (!equals_complex(&(c_sum), &(c1))){
        printf("oups\n");
    }

    complex_t c_sub;
    subtraction_complex(&(c1), &(c2), &(c_sub));
    if (!equals_complex(&(c_sub), &(c1))){
        printf("oups\n");
    }
    
    double mod = modulus(&(c1));
    double c_arg = argument(&(c1));
    printf("%lf %lf\n",mod,c_arg);
    complex_t c_conj;
    conjugate_complex(&(c1),&(c_conj));
    display_complex(&(c_conj));
    return EXIT_SUCCESS;
}
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "struct.c"


bool are_positions_equals(position_t *p_pos, position_t *p_pos2){
    if(p_pos == NULL || p_pos2 == NULL){
        return false; //test if the pointers are null
    }
    return(p_pos->x == p_pos2->x && p_pos->y == p_pos2->y); //return the boolean of this equality
}


void set_position(uint x, uint y, position_t * p_pos){
    if(p_pos == NULL){
        fprintf(stderr, "bad parameters");
        exit(EXIT_FAILURE); //test if the pointer is null
    }
    p_pos->x = x; //set the position with x and y
    p_pos->y = y;
}

bool are_directions_equals(direction_t *p_dir, direction_t *p_dir2){
    if(p_dir == NULL || p_dir2 == NULL){
        return false; //test if the pointers are null
    }
    return(p_dir->deltax == p_dir2->deltax && p_dir->deltay == p_dir2->deltay); //return the boolean of this equality
}


void translate(position_t *p_position, direction_t *p_dir, position_t *p_newposition){
    if(p_newposition == NULL || p_position==NULL || p_dir == NULL){
        fprintf(stderr, "bad parameters");    //test if one of the pointers is null
        exit(EXIT_FAILURE);
    }
    if((p_dir->deltax < 0 && -(p_dir->deltax) > p_position->x) || (p_dir->deltay < 0 && -(p_dir->deltay) > p_position->y)){
        fprintf(stderr, "bad parameters");      //test if x + deltax < 0
        exit(EXIT_FAILURE);
    }

    if((p_dir->deltax > 0 && p_dir->deltax+p_position->x < p_dir->deltax) || (p_dir->deltay > 0 && p_dir->deltay + p_position->y < p_dir->deltay)){
        fprintf(stderr, "bad parameters");
        exit(EXIT_FAILURE);  //test if x + deltax > max unsigned int
    }
    p_newposition->x = p_position->x + p_dir->deltax;  //set the new position
    p_newposition->y = p_position->y + p_dir->deltay;
}

int main(void){
    position_t p = (position_t) { 15, 2 };
    position_t p2 = (position_t) { 10, 4 };
    position_t p3;
    position_t p4;
    position_t p5;
    direction_t d = (direction_t) { 5, -2 };
    direction_t d2 = (direction_t) { -5, 2 };
    direction_t d3 = (direction_t) { 5, -2 };
    set_position(15, 2, &(p3));
    translate(&(p2), &(d), &(p4));
    translate(&(p), &(d2), &(p5));
    print_position(&(p));
    print_position(&(p2));
    print_position(&(p3));
    print_position(&(p4));
    print_position(&(p5));
    print_direction(&(d));
    print_direction(&(d2));
    print_direction(&(d3));
    if(!are_positions_equals(&(p),&(p2))){
        printf("p and p2 are different.\n");
    }
    if(are_positions_equals(&(p),&(p3))){
        printf("p and p3 are equal.\n");
    }
    if(are_positions_equals(&(p),&(p4))){
        printf("p and p4 are equal.\n");
    }
    if(are_positions_equals(&(p2),&(p5))){
        printf("p2 and p5 are equal.\n");
    }
    if(!are_directions_equals(&(d),&(d2))){
        printf("d and d2 are different.\n");
    }
    if(are_directions_equals(&(d),&(d3))){
        printf("d and d3 are equal.\n");
    }
    return EXIT_SUCCESS;
}
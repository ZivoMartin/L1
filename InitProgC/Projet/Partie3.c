#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.c"

bool is_border_cell(map_t *p_map, uint pos_index){
    if(p_map == NULL || pos_index >= NB_MAX_CELLS){
        exit(EXIT_FAILURE); //if the pointer is null or if index is too high
    }
    position_t pos; 
    valid_index_to_position(p_map, pos_index, &pos);  //we get the position of the index
    return(!is_position_valid_and_visible(p_map, &pos)); //we test if this position is visible
}


bool is_position_valid(position_t *p_position){
    if(p_position == NULL){
        exit(EXIT_SUCCESS);
    }
    return((p_position->x+1)*(p_position->y+1) <= NB_MAX_CELLS); //we calculate the index of the position then we compare him to NB_MAX_CELLS
}

bool is_position_valid_and_visible(map_t *p_map, position_t *p_position){
    if(p_map == NULL || p_position == NULL){
        exit(EXIT_SUCCESS);
    }
    return(p_position->x <= p_map->nb_columns && p_position->y <= p_map->nb_lines && p_position->x != 0 && p_position->y != 0);
    //we test if x is lower than the number of columns and differents from 0, and if y is lower than the number of lines and differents from 0
}

uint valid_position_to_index(map_t *p_map, position_t *p_position){
    if(p_position == NULL){
        exit(EXIT_SUCCESS);
    }
    return(p_position->y*(p_map->nb_columns+2)+p_position->x); //we return the index of the position
}

void valid_index_to_position(map_t *p_map, uint i, position_t *p_position){
    if(p_map == NULL || p_position == NULL){
        exit(EXIT_FAILURE);
    }
    int x = i%(p_map->nb_columns+2); //calculate the value of x
    int y = (i - x)/(p_map->nb_columns+2); // and here of y
    p_position->x = x; //we set the values
    p_position->y = y;
}
color_t get_cell(map_t *p_map, position_t *p_position){
    if(p_position == NULL || p_map == NULL){
        exit(EXIT_FAILURE);
    }
    if(is_position_valid(p_position)){ //we test if the position is valid
        uint index = valid_position_to_index(p_map, p_position);
        return(p_map->cells[index]); //if it is, we return the value
    }else{
        return(EXIT_SUCCESS); //else we exit
    }
}

void set_color_cell(map_t *p_map, position_t *p_position, color_t color_id){
    if(p_map == NULL || p_position == NULL){
        exit(EXIT_FAILURE);
    }
    if(is_position_valid_and_visible(p_map, p_position) && color_id >= 0 && color_id <NB_MAX_COLORS){ //we test if the position is valid and visible and if the color is valid 
        uint index = valid_position_to_index(p_map, p_position); //if it is we get the index of the position, then we put the value of the color
        p_map->cells[index] = color_id;
    }else{
        exit(EXIT_FAILURE);
    }
}

void set_empty_cell(map_t *p_map, position_t *p_position){
    if(p_map == NULL || p_position == NULL){
        exit(EXIT_FAILURE);
    }
    if(is_position_valid_and_visible(p_map, p_position)){ //we test if the position is valid and visible 
        uint index = valid_position_to_index(p_map, p_position); //if it is we get the index of the position, then we put the value of an empty cell
        p_map->cells[index] = EMPTY_CELL; 
    }else{
        exit(EXIT_FAILURE);
    }
}


bool movement_is_allowed(map_t *p_map, position_t *p_position, direction_t *p_direction ){
    if(p_map == NULL || p_position == NULL || p_direction == NULL){
        exit(EXIT_FAILURE);
    }
    if(is_position_valid_and_visible(p_map, p_position)){ 
        position_t newPos = {p_position->x + p_direction->deltax, p_position->y + p_direction->deltay}; //we get the new position after the movement
        return(is_position_valid_and_visible(p_map, &newPos) && get_cell(p_map, &newPos) == EMPTY_CELL); //we return the test if the new position is on the map and is empty
    }else{
        exit(EXIT_FAILURE);
    }
}


int main(void){
    position_t p;
    map_t m;
    game_t g; 
    init_game(&(g),&(m),&(p),"carte.xml");
    update_display(NULL,&(g));
	while( ! end_of_program(&(g)) ){
	    g.p_next_direction=read_direction(NULL);
		update_game(&(g));
		update_display(NULL,&(g));
	}
	draw_awards(NULL,&(g));
	delete_display(NULL);
	return EXIT_SUCCESS;
}
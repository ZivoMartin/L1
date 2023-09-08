#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.c"

void update_next_colors(game_t *p_game){
    if(p_game == NULL){
        exit(EXIT_SUCCESS);
    }
    for(int i = 0; i<NB_MAX_NEXT_COLORS-1; i++){
        p_game->next_colors[i] = p_game->next_colors[i+1];
    }
    p_game->next_colors[NB_MAX_NEXT_COLORS-1] = get_random_integer(0, 0);
}

bool is_winning(game_t *p_game){
    if(p_game == NULL || p_game->p_map == NULL){
        exit(EXIT_SUCCESS);
    }
    return(p_game->score >= p_game->p_map->goal);
}



void apply_move(game_t *p_game){
    if(p_game == NULL){
        exit(EXIT_SUCCESS);
    }
    if(movement_is_allowed(p_game->p_map, p_game->p_actual_position, p_game->p_next_direction )){
        //we start to set the new position
        set_position(p_game->p_actual_position->x + p_game->p_next_direction->deltax, p_game->p_actual_position->y + p_game->p_next_direction->deltay, p_game->p_actual_position);
        uint index = valid_position_to_index(p_game->p_map, p_game->p_actual_position); //then we get the index of this position
        p_game->p_map->cells[index] = p_game->next_colors[0]; //we apply the new color of the position
        update_next_colors(p_game); //then we change the next colors tab
    }else{
        exit(EXIT_SUCCESS);
    }
}

bool can_move(game_t *p_game){
    if(p_game == NULL){
        exit(EXIT_FAILURE);
    }
    if(movement_is_allowed(p_game->p_map, p_game->p_actual_position, LEFT)){ //we test with all the possible movement if its possible to move
        return true;
    }
    if(movement_is_allowed(p_game->p_map, p_game->p_actual_position, RIGHT)){
        return true;
    }
    if(movement_is_allowed(p_game->p_map, p_game->p_actual_position, UP)){
        return true;
    }
    if(movement_is_allowed(p_game->p_map, p_game->p_actual_position, DOWN)){
        return true;
    }
    return false;
}

bool end_of_program(game_t *p_game){
    if(p_game == NULL){
        exit(EXIT_SUCCESS);
    }
    return(!can_move(p_game) || is_winning(p_game));
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

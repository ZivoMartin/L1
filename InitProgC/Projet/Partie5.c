#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.c"



void recursiv_compute_connected_component(map_t *p_map, uint index, int *count, color_t value){
    *count = *count + 1;
    p_map->connected_component[index] = true;

    int i = index + p_map->nb_columns + 2;
    if(!is_border_cell(p_map, i) && !p_map->connected_component[i] && p_map->cells[i] == value){
        recursiv_compute_connected_component(p_map, i, count, value);
    }

    i = index - p_map->nb_columns - 2;
    if(!is_border_cell(p_map, i) && !p_map->connected_component[i] && p_map->cells[i] == value){
        recursiv_compute_connected_component(p_map, i, count, value);
    }

    i = index + 1;
    if(!is_border_cell(p_map, i) && !p_map->connected_component[i] && p_map->cells[i] == value){
        recursiv_compute_connected_component(p_map, i, count, value);
    }

    i = index - 1;
    if(!is_border_cell(p_map, i) && !p_map->connected_component[i] && p_map->cells[i] == value){
        recursiv_compute_connected_component(p_map, i, count, value);
    }
}

uint compute_connected_component(map_t *p_map, position_t *p_pos){
    if(p_map == NULL || p_pos == NULL){
        exit(EXIT_SUCCESS);
    }
    int count = 0;
    for(int i=0; i<NB_MAX_CELLS; i++){
        p_map->connected_component[i] = false;
    }
    recursiv_compute_connected_component(p_map, valid_position_to_index(p_map, p_pos), &count, get_cell(p_map, p_pos));
    return count;
}


void erase_connected_component(map_t *p_map){
    if(p_map == NULL){
        exit(EXIT_SUCCESS);
    }
    for(int i = 0; i<NB_MAX_CELLS; i = i + 1){
        if(p_map->connected_component[i]){
            p_map->cells[i] = EMPTY_CELL;
            p_map->connected_component[i] = false;
        }
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
	printf("%d", compute_connected_component(&m, g.p_actual_position));
	return EXIT_SUCCESS;
}
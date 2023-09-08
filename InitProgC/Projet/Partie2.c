#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.c"

char get_ascii_color(color_t c){
    if(c < 0 || c > 9){
        fprintf(stderr, "bad parameters");
        exit(EXIT_SUCCESS);  //test if 0<=c<=9
    }
    return(c+48);
}

void draw_ascii_awards(game_t *p_game){
    if(p_game == NULL){
        fprintf(stderr, "bad parameters"); //test if pointer is null
        exit(EXIT_SUCCESS);
    }
    if(is_winning(p_game)){     //if the game is win, we say you win, else we say game over
        printf("YOU WIN !");
    }else{
        printf("GAME OVER !");
    }
}

void draw_ascii_menu(game_t *p_game){
    if(p_game == NULL){
        fprintf(stderr, "bad parameters"); //test if pointer is null
        exit(EXIT_SUCCESS);
    }
    printf("Next colors : %d %d %d\n", p_game->next_colors[0], p_game->next_colors[1], p_game->next_colors[2]); //we print the 3 next colors
    printf("%d / %d\n", p_game->score, p_game->p_map->goal); //we print in first the current score, and after the goal score in the map of the game
}

void draw_ascii_tiles(map_t *p_map, position_t *p_actual_pos){
    if(p_actual_pos == NULL || p_map == NULL){
        exit(EXIT_FAILURE);
    }
    position_t posParcourtUn = {1, 1};
    position_t posParcourtDeux;   //we initialize 2 new positions who will browse the map

    while(is_position_valid_and_visible(p_map, &posParcourtUn)){    //while the first one is valid, we continue
        posParcourtDeux.x = 1;  //the second will browse the columns, so x start at 1 and y is equal to ParcourtUn.y
        posParcourtDeux.y = posParcourtUn.y; 
        while(is_position_valid_and_visible(p_map, &posParcourtDeux)){ //while the second is valid, we continue
            color_t color = get_cell(p_map, &posParcourtDeux); //we get the color of the position
            if(color==EMPTY_CELL){ //if its an empty cell, we print X
                printf(" X ");
            }else{
                printf(" %d", color); //else we just print the color, if its the actual pos we print "!", else a space
                if(p_actual_pos->x == posParcourtDeux.x && p_actual_pos->y == posParcourtDeux.y){
                    printf("!");
                }else{
                    printf(" ");
                }
            }
            posParcourtDeux.x += 1; //then we increment the index
        }
        posParcourtUn.y += 1;
        printf("\n");
    }
}


void update_ascii_display(game_t *p_game){
    if(p_game == NULL){
        exit(EXIT_SUCCESS);
    }
    draw_ascii_tiles(p_game->p_map, p_game->p_actual_position);
    draw_ascii_menu(p_game);
}

int main(void){
    position_t p;
    map_t m;
    game_t g; 
    init_game(&(g),&(m),&(p),"carte.xml");
    
	draw_ascii_tiles(&m, g.p_actual_position);

	return EXIT_SUCCESS;
}
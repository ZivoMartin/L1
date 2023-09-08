#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef PLAYER1
    #define PLAYER1 'X'
#endif

#ifndef PLAYER2
    #define PLAYER2 'O'
#endif

#ifndef TIED
    #define TIED 0
#endif

#ifndef NOTDONE
    #define NOTDONE -1
#endif

#ifndef DONE
    #define DONE 1
#endif

//Given function which returns '1', '2', ... '9'; or '0' in case of error - not to be implemented
char read_order(){   
    char a; 
    scanf("%c", &a);
    printf("\n");
    return(a);
}

//To be defined functions

//Print out a 3 x 3 grid displaying the board. If a cell does not belong to a player yet, its 
// index is printed out; otherwise the corresponding mark of the player is drawn (using the named constant PLAYER1 or PLAYER2)
void display_board(char board[]){
    for(int i = 0; i<9; i = i + 3){
        printf("|");
        for(int j = i; j < i + 3; j++){
            printf(" %c |", board[j]);
        }
        printf("\n");
    }
}


    //Checks if the choice (wich belongs to ['0','9']) is an empty cell. If so, it assigns the 'mark' to the corresponding cell and 
    //return true; otherwiese, it just return false
bool check_choice(char board[], char choice, char mark){
    for(int i = 0; i < 9; i++){
        if(board[i] == choice){
            board[i] = mark;
            return true;
        }
    }
     return false;
}

//Determines if the game is DONE (there is a winner), NOTDONE (still no winner), or TIED and return the corresponding named constant
short end_of_game(char board[]){
    int stack = 0;
    for(int i = 0; i<9; i = i + 3){
        if(board[i] == PLAYER1 || board[i] == PLAYER2){
            stack += 1;
        }
        if(board[i] == board[i+1] && board[i+1] == board[i+2]){
            return(DONE);
        }
    }
    for(int i = 0; i<3; i = i + 1){
        if(board[i] == PLAYER1 || board[i] == PLAYER2){
            stack += 1;
        }
        if(board[i] == board[i+3] && board[i+3] == board[i+6]){
            return(DONE);
        }
    }
    if(board[0] == board[4] && board[4] == board[8]){
            return(DONE);
    }
    if(board[2] == board[4] && board[4] == board[6]){
            return(DONE);
    }
    if (stack == 5 && (board[4] == PLAYER1 || board[4] == PLAYER2) && (board[5] == PLAYER1 || board[5] == PLAYER2) && (board[7] == PLAYER1 || board[7] == PLAYER2) && (board[8] == PLAYER1 || board[8] == PLAYER2)){
        return(TIED);
    }
    return(NOTDONE);
    
}

int main()
{
    char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    char marks[]={PLAYER1,PLAYER2};
    unsigned int play_count = 1;
    char choice='0';
    short eog=NOTDONE;
    do
    {
        display_board(board);
        play_count++;
        do{
            printf("\nPlayer %u, enter a number:  ", play_count%2+1);
            choice=read_order();
        }while(!check_choice(board,choice,marks[play_count%2]));
        eog=end_of_game(board);
    }while (eog==NOTDONE);
    display_board(board);
    if(eog==DONE){
        printf("Player %d win ", play_count%2+1);    
    }else{
        printf("Tied game");
    }
    
    return EXIT_SUCCESS;
}

//
//  sandbox
//
//
//  created By Andrew Marion Hunter on 2/18/15.
//
//

/* algo - Rhythm
 1. create A 10x10 array
 2. read In the game board and assign to gameBord
 3. change Array to colors
 4. print Those colors as well as row and column numbers
 5. search Array for candies in a row
 6. if Candies are in a row, change their background to black and print "XX"
 7. print Final gameBoard with x's
 */

d

#include <stdio.h>

//header For numberColor
void numberColor(int number);

//call Main function
int main(){
    int r = 10;
    int c = 10;
    int gameBoard[c][r];
    
    //read Values from file to gameboard
    for(r = 0 ; r < 10 ; r++){
        for(c = 0; c < 10; c++){
            scanf("%d", &gameBoard[c][r]);
        }
    }
    //print Top numbers
    printf(" ");
    for(c = 0; c < 10; c++){
        printf("%d ", c);
    }
    
    printf("\n");
    //change Numbers to colors
    for(r = 0; r < 10; r++){
        printf("%d", r);
        for(c = 0; c < 10; c++){
            //print Array
            numberColor(gameBoard[c][r]);
        }
        printf("\x1b[m\n");
    }
    printf("\n");
    
    //search For matches
    for(r = 0; r < 10 ; r++){
        for(c = 0; c < 10; c++){
            
            //five In a column
            if((gameBoard[c][r] == gameBoard[c+1][r] || gameBoard[c][r] == gameBoard[c+1][r]+10) && (gameBoard[c][r] == gameBoard[c+2][r] || gameBoard[c][r] == gameBoard[c+2][r]+10) && (gameBoard[c][r] == gameBoard[c+3][r] || gameBoard[c][r] == gameBoard[c+3][r]+10) && (gameBoard[c][r] == gameBoard[c+4][r] || gameBoard[c][r] == gameBoard[c+4][r]+10)){
                gameBoard[c][r] = gameBoard[c][r] + 10;
                gameBoard[c+1][r] = gameBoard[c+1][r] + 10;
                gameBoard[c+2][r] = gameBoard[c+2][r] + 10;
                gameBoard[c+3][r] = gameBoard[c+3][r] + 10;
                gameBoard[c+4][r] = gameBoard[c+4][r] + 10;
            }
            
            //four In a column
            else if((gameBoard[c][r] == gameBoard[c+1][r] || gameBoard[c][r] == gameBoard[c+1][r]+10) && (gameBoard[c][r] == gameBoard[c+2][r] || gameBoard[c][r] == gameBoard[c+2][r]+10) && (gameBoard[c][r] == gameBoard[c+3][r] || gameBoard[c][r] == gameBoard[c+3][r]+10)){
                gameBoard[c][r] = gameBoard[c][r] + 10;
                gameBoard[c+1][r] = gameBoard[c+1][r] + 10;
                gameBoard[c+2][r] = gameBoard[c+2][r] + 10;
                gameBoard[c+3][r] = gameBoard[c+3][r] + 10;
            }
            
            //three In a column
            else if((gameBoard[c][r] == gameBoard[c+1][r] || gameBoard[c][r] == gameBoard[c+1][r]+10) && (gameBoard[c][r] == gameBoard[c+2][r] || gameBoard[c][r] == gameBoard[c+2][r]+10)){
                gameBoard[c][r] = gameBoard[c][r] + 10;
                gameBoard[c+1][r] = gameBoard[c+1][r] + 10;
                gameBoard[c+2][r] = gameBoard[c+2][r] + 10;
            }
            
            //five In a row
            else if((gameBoard[c][r] == gameBoard[c][r+1] || gameBoard[c][r] == gameBoard[c][r+1]+10) && (gameBoard[c][r] == gameBoard[c][r+2] || gameBoard[c][r] == gameBoard[c][r+2]+10) && (gameBoard[c][r] == gameBoard[c][r+3] || gameBoard[c][r] == gameBoard[c][r+3]+10) && (gameBoard[c][r] == gameBoard[c][r+4] || gameBoard[c][r] == gameBoard[c][r+4]+10)){
                gameBoard[c][r] = gameBoard[c][r] + 10;
                gameBoard[c][r+1] = gameBoard[c][r+1] + 10;
                gameBoard[c][r+2] = gameBoard[c][r+2] + 10;
                gameBoard[c][r+3] = gameBoard[c][r+3] + 10;
                gameBoard[c][r+4] = gameBoard[c][r+4] + 10;
            }
            
            //four In a row
            else if((gameBoard[c][r] == gameBoard[c][r+1] || gameBoard[c][r] == gameBoard[c][r+1]+10) && (gameBoard[c][r] == gameBoard[c][r+2] || gameBoard[c][r] == gameBoard[c][r+2]+10) && (gameBoard[c][r] == gameBoard[c][r+3] || gameBoard[c][r] == gameBoard[c][r+3]+10)){
                gameBoard[c][r] = gameBoard[c][r] + 10;
                gameBoard[c][r+1] = gameBoard[c][r+1] + 10;
                gameBoard[c][r+2] = gameBoard[c][r+2] + 10;
                gameBoard[c][r+3] = gameBoard[c][r+3] + 10;
            }
            
            //three In a row
            else if((gameBoard[c][r] == gameBoard[c][r+1] || gameBoard[c][r] == gameBoard[c][r+1]+10) && (gameBoard[c][r] == gameBoard[c][r+2] || gameBoard[c][r] == gameBoard[c][r+2]+10)){
                gameBoard[c][r] = gameBoard[c][r] + 10;
                gameBoard[c][r+1] = gameBoard[c][r+1] + 10;
                gameBoard[c][r+2] = gameBoard[c][r+2] + 10;
                
            }
        }
    }
    
    //print Top numbers
    printf(" ");
    for(r = 0; r < 10; r++){
        printf("%d ", r);
    }
    printf("\n");
    
    
    for(r = 0; r < 10; r++){
        //print Side number
        printf("%d", r);
        for(c = 0; c < 10; c++){
            //print Array
            numberColor(gameBoard[c][r]);
        }
        printf("\x1b[m\n");
    }
    printf("\n");
    
}



//function That changes numbers to colors
void numberColor(int number){
    if(number > 10){
        printf("\x1b[49mXX");
    }
    else{
        printf("\x1b[4%dm  ", number);
    }
}
/*
Lauren Cairco Dukes
CPSC 101
Minesweeper Template

Gives the framework for playing minesweeper.
Demonstrates arrays and functions.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// function prototypes
void generateGameboard(int gb[10][10], int rows, int columns, int howManyMines);
void initializeGameboard(bool board[10][10], int rows, int columns, bool initializationValue);
void printGameboard(int gb[10][10], bool revealed[10][10], int rows, int columns);

int getUserRow();
int getUserColumn();

bool uncoverSpot(int gb[10][10], bool revealed[10][10], int rows, int columns, int userRow, int 
userColumn);


/*
Algorithm for main:
1. Declare variables for the hidden gameboard and revealed gameboard
2. Generate the hidden gameboard with 5 random mines in it.
3. Initialize the isRevealed gameboard so that everything is hidden.
4. Declare a variable to hold whether the game is over or not.
5. While the game is not over:
	5a. Print out the gameboard. All spots not uncovered should be Xs. 
	5b. Ask the user for the spot they want to uncover (row, then column).
	5c. Uncover that spot.
6. Once the game is over, print "Game over!"
7. Print out the revealed gameboard.

*/

int main(void){
	//1. Declare variables for the hidden game board and revealed gameboard.
	int hiddenGameboard[10][10];
	bool isRevealed[10][10];

	//2. Generate the revealed gameboard with 5 random mines in it.
	generateGameboard(hiddenGameboard,10,10,5);

	//3. Initialize isrevealed gameboard so that no spots are revealed.
	initializeGameboard(isRevealed,10,10,false);

	//4. Declare a variable to hold whether the game is over or not.
	bool gameOver = false;

	//5. While the game is not over:
	while(!gameOver){
		//5a. Print the gameboard.
		printGameboard(hiddenGameboard, isRevealed, 10, 10);

		//5b. Ask the user for the spot they want to uncover.
		int row = getUserRow();
		int column = getUserColumn();

		//5c. Uncover that spot
		gameOver = uncoverSpot(hiddenGameboard, isRevealed, 10, 10, row, column);
	}

	//6. Once the game is over, print "Game Over!"
	printf("Game over!\n");
	
	//7. Print the revealed gameboard.
	initializeGameboard(isRevealed, 10, 10, true);
	printGameboard(hiddenGameboard, isRevealed, 10, 10);

	return 0;
}

/*
function implementations 
*/

/*
Algorithm for generateGameboard
1. Set all values in the gameboard (gb) to 0
2. While howManyMines is greater than 0:
	2a. Generate a row between 0 and rows - 1
	2b. Generate a column between 0 and columns - 1
	2c. If there's not a mine at that spot in gb
		a. Place a mine there by setting the spot equal to 9
		b. subtract 1 for how many mines (we're counting down until all mines are placed

*/
void generateGameboard(int gb[10][10], int rows, int columns, int howManyMines){
	srand(time(NULL));

	//set all values in gb to 0
	int r, c;
	//for every row
	for (r = 0; r < rows; r++){
		//for every column in that row
		for (c = 0; c < columns; c++){
			//set it equal to 0
			gb[r][c] = 0;
		}
	}

	//While howManyMines is greater than 0:
	while (howManyMines > 0){
		//generate a row between 0 and rows - 1
		int row = rand() % rows;
		//generate a column between o and columns - 1
		int column = rand() % rows;
		
		//if there's not a mine at that spot in gb
		if (gb[row][column] != 9){
			//set it as a mine
			gb[row][column] = 9;
			//subtract 1 from how many mines left to place
			howManyMines--;
		}
	}

}

/*
Algorithm for uncovering the spot
1. First, set revealed[userRow][userColumn] to true
2. Call the function countMines to count up how many mines surround that spot
3. Set gb[userRow][userColumn] to the mine count returned from countMines
4. If there were no mines surrounding the spot
	4a. Look at all the neighbors of this spot. From the row r above me to the row below me,
		I. From the column c to my left to the column to my right
			i. if the spot r,c is not revealed and it's in the bounds of my array
				a. uncover that spot	
5. If there was a mine there (it returned -1) return true
6. Otherwise, return false
*/

bool uncoverSpot(int gb[10][10], bool revealed[10][10], int rows, int columns, int userRow, int userCol){
	//Set revealed[userRow][userCol] to true;
	revealed[userRow][userCol] = true;

	//Call the function countMines to count up how many mines surround that spot	
	int mineCount = countMines(gb,rows, columns, userRow, userCol);

	//set gb[userRow][userCol] t0 the number of mines there are
	gb[userRow][userCol] = mineCount;

	//if there were no mines surrounding the spot
	if (mineCount == 0){
		//look at all the neighbors of this spot
		//from the row r above me to the row below me
		int r, c;
		for (r = userRow - 1; r <= userRow + 1; r++){
			//from the column to my right to the column to my left
			for (c = userCol - 1; c <= userCol + 1; c++){
				//if the spot r c is in the bounds of my array
				if (r >= 0 && r < rows && c >= 0 && c < columns){
					//and it's not revealed
					if (revealed[r][c] == false){
						//reveal it
						uncoverSpot(gb, revealed, rows, columns, r, c);
					}
				}
			}
		}
	}
	//if there was a mine there, return true
	if (mineCount == 9){
		return true;
	}
	//otherwise return false
	else{
		return false;
	}
}

/*
Algorithm for countMines
1. If board[row][col] == 9, return 9.
2. Else:
	2a. Declare a variable to hold how many mines are in the surrounding cells.
	2b. Set that variable equal to 0.
	2c. For every row r, starting at r = row - 1 and counting up until r = row + 1
		i. For every column c, starting at c = column - 1 and counting up until c = col + 1
			a. If r is greater than or equal to 0 and less than nRows
				1. if c is greater than or equal to 0 and less than nColumns
					1a. if board[r][c] is equal to 9
						i. add 1 to the mine count
	2d. Return the mine count.
*/

int countMines(int board[10][10],int nRows, int nColumns, int row, int col){

}


/*
Algorithm for initializeGameboard

1. For every row r in the board
	1a. for every column c in the board
		i. Set board[r][c] equal to intializationValue
*/
void initializeGameboard(bool board[10][10], int rows, int columns, bool initializationValue){

}

/*
Algorithm for printGameboard
1. Print out a single space
2. For every value from 0 to columns
	2a. Print out a space, then that value
3. Print out a newline
4. For every row r in the gameboard, starting at 0 and counting up to rows-1
	4a. Print out r, then a space
	4b. For every column c in the gameboard, starting at 0 and counting up to columns - 1
		i. if revealed[r][c] is true
			a. print out gb[r][c], then a space
		ii. else
			b. print out X, then a space
	4c. Print out a newline so you move to the next row
*/
void printGameboard(int gb[10][10], bool revealed[10][10], int rows, int columns){

}

/*
Algorithm for getting the user row
1. Ask the user to enter the row (0-9)
2. Use scanf to read in the row
3. Return what you read in using scanf
*/
int getUserRow(){

}

/*
Algorithm for getting the user column
1. Ask the user to enter the column (0-9)
2. Use scanf to read in the column
3. Return what you read in using scanf
*/
int getUserColumn(){

}



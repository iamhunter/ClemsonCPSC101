// Lab 3
// Andrew Hunter
// 01/27/15
// Program prints a rectangle and the area of that rectangle
/*
1. Ask user to enter the triangle size
2. Get the valuefrom the keyboard
3.
*/
#include <stdio.h>

int main(){

	int TriSize;
	int row = 1;


	//Ask user to enter the triangle size
	printf("Enter the triangle size:");
	scanf("%d", &TriSize);
	while(row <= TriSize){
		int col = 1;
		while (col <= row){
			printf("*");
			col = col + 1;
		}
		printf("\n");
		row = row + 1;
	}

	return 0;
}

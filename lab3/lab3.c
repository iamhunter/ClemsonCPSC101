/*
Lab 3
Andrew Hunter
01/27/15
Program prints a rectangle as well as the area of that rectangle
*/
#include<stdio.h>

int main(void){
	int length;
	int width;
	int decimal;
	int spaceWidth;
	int spaceLength;
	int x = 1;
	int y = 1;
	int z = 1;

	printf("Enter an integer for length:");
	scanf("%d", &length);

	printf("Enter an integer for width:");
	scanf("%d", &width);
	
	spaceWidth = width - 2;
	spaceLength = length - 2;
	decimal = length*width;
	
	printf("The area of your rectangle is:\n");
	printf("%5d in decimal\n", decimal);
	printf("%5x in hexadecimal\n", decimal);
	printf("%5o in octal\n\n", decimal);

	while(width >= x){
		x=x+1;
		printf("*");

	}
	printf("\n");

	while(length >= z){
		printf("*");
		while(width-2 >= y){
			y=y+1;
			printf(" ");
			}
		y=1;
		printf("*\n");
		z=z+1;
		}

	x=1;
	while(width >= x){
	x=x+1;
	printf("*");

	}
}

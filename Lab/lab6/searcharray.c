#include <stdio.h>

char convertToLower(char x);

int main(void){
	//1. Declare variables
	int nextSpot = 0;
	char a[5];

	//2. Put things in the array
	//for every element in the array
	while (nextSpot <= 4){
		//ask the user for a letter
		printf("Please type a character: ");
		//read in that letter into the next spot in the array
		scanf(" %c",&a[nextSpot]);
		//advance next spot
		nextSpot++;
	}

	//3. Search for a character
	char searchfor;
	
	//Ask the user for what letter they want
	printf("What letter do you want to look for?");
	scanf(" %c",&searchfor);

	//convert to lowercase
	searchfor = convertToLower(searchfor);

	//Look through my whole array for that character
	for (nextSpot = 0; nextSpot <= 4; nextSpot++){
		//if the character in the array at nextSpot
		//is the same as the character we're looking for
		if (a[nextSpot] == searchfor){
			//print out the spot it's at
			printf("%c is at %d\n",searchfor,nextSpot);
		}

	}
	
	return 0;
}

char convertToLower(char x){
	if (x >=65 && x <= 90){
		return x + 32;
	}
	else{
		return x;
	}
}

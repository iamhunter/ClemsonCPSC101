#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int wordtonumber(char humanword[10]);
void numbertoword(int computernumber);

int main(){
	srand(time(NULL));

	char copy;
	int computernumber = rand()%3;
	int humannumber;
	char humanword[10];

	printf("rock, paper, or scissors?");
	scanf("%s", humanword);
	humannumber = wordtonumber(humanword);
	numbertoword(computernumber);
	printf("%s, ", humanword);
	
	if((humannumber+2)%3 == computernumber){
		printf("you win!");
	}

	else if(humannumber == computernumber){
		printf("you tied!");
	}
	else{
		printf("you lost :(");	
	}

	printf("\n%d %d %s\n", computernumber, humannumber, humanword);
	



return 0;
}


int wordtonumber(char humanword[10]){
	if(humanword[0]==114){
		return 0;
	}
	if(humanword[0]==112){
		return 1;
	}
	if(humanword[0]==115){
		return 2;
	}
}

void numbertoword(int computernumber){


	if(computernumber == 0){
		printf("The computer chose rock and you chose ");
	}
	else if(computernumber == 1){
		printf("The computer chose paper and you chose ");
	}
	else if(computernumber == 2){
		printf("The computer chose scissors and you chose ");
	}


}

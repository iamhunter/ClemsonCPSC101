#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

	int ndx = 1;
	double num1;
	double answer;
	double num2;
	char opchar;
	
	sscanf(argv[ndx], "%lf", &num1); 
	ndx++;
	answer = num1;

	while(ndx < argc){

		sscanf(argv[ndx],"%c",&opchar); ndx++;
		sscanf(argv[ndx],"%lf", &num2); ndx++;

		switch (opchar){
	 		case '+': 
	 			answer += num2;
	 			break;
	 		case '-':
	 			answer -= num2;
	 			break;
			case 'x':
				answer *= num2;
				break;
			case '/':
				answer /= num2;
				break;
			default:
				fprintf(stderr, "bad op code %c \n", opchar);
				return(-1);
		}
	}

	printf("%12.3lf\n", answer);





	return 0;
}

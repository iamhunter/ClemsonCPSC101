//Lab 4
//Andrew Hunter
//01/20/15
//Program counts number of scores and then prints the number of each grade.
/*
1. Create all integer variables
2. Ask how many students are in the class and record response
3. For the number of students in the class, run this while loop
4. Assign a letter grade to each grade, and keep a running total of each grade
5. Print out the letter grades
*/

#include <stdio.h>

int main(){
	// Create all integer variables
	int count;
	int a=0;
	int b=0;
	int c=0;
	int grade;
	int temporary = 1;

	// Ask how many students are in the class and record response
	printf("How many students are in the class?");
	scanf("%d", &count);

	// For the number of students in the class, run this while loop
	while(count>0){
		printf("Enter grade No. %d: ", temporary);
		scanf("%d", &grade);
		
		// If the grade is greater than or equal to than 90, add one to the A count
		if(grade>=90){
			a=a+1;
		}

		// If the grade is less than 90 and greater or equal to 80, add one to the B count
		else if(grade<90 && grade>=80){
			b=b+1;
		}

		// If the grade is less than 80, add one to the C count
		else if(grade<80){
			c=c+1;
		}
		temporary=temporary+1;
		count=count-1;
	}
	// Print out the number of A's, B's and C's
	printf("Number of A's: %d\n", a);
	printf("Number of B's: %d\n", b);
	printf("Number of C's: %d\n", c);


}

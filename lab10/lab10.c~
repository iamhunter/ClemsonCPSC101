//
// Andrew Hunter
// CPSC 101 Lab 10
// March 31, 2015 
// Strings
//
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_srlen (char s1[]);
void my_strcat (char s1[], char s2[]);

int main(){
	char v1[16];
	char v2[16];

	
	printf("Enter a string with a maximum length of 7 for v1: ");
	scanf("%s", v1);

	printf("Enter a string with a maximum length of 7 for v2: ");
	scanf("%s", v2);

	int i1 = my_strlen(v1);
	int i2 = my_strlen(v2);

	printf("len: %3d - string: %s \n", i1, v1);
	printf("len: %3d - string: %s \n", i2, v2);
	
	my_strcat(v1, v2);
	printf("%s\n", v1);

	return 0;

}

int my_strlen (char s1[]){
	int ndx = 0;

	while(s1[ndx]>0){
		ndx++;
	}
	return ndx;
}

void my_strcat (char s1[], char s2[]){
	int b = 0;
	int c = 0;

	while(s1[b]>0){
		b++;
	}
	while(s2[c]>0){
		s1[b] = s2[c];
		b++;
		c++;
	}
	s1[b]=0;

}








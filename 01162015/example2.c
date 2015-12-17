#include<stdio.h>

int main(void){

	int a, b, c, goodValues;
	printf("Please enter three integers, separated by a space");
	goodValues = scanf("%d %d %d", &a, &b, &c);
	printf("%d",goodValues);
	return 0;
}

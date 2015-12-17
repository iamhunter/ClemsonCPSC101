#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
    srand(time(NULL));
    
    int guess = 0;
    
    int correct = 0;
    int boolian = 0;
    
    while(boolian == 0){
        int one = rand() % 11;
        int two = rand() % 11;
        int total = one + two;
        
        printf("%d + %d = ", one, two);
        scanf("%d", &guess);
        if(guess == total){
            boolian = 0;
            correct++;
        }
        else{
            boolian = 1;
        }
        
    
    }
    printf("You got %d correct!\n", correct);
    
    return 0;
}
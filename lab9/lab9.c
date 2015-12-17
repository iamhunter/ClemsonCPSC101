//
//  Andrew Hunter
//  Lab 9
//
//
//
//

#include <stdio.h>

void sort(int array[], int count);

int main(){
    int numArray[100];
    int counter = 0;
    int c = 0;
    int d = 1;
    
    while(c < 100){
        
        scanf("%d", &numArray[c]);
        
        if(numArray[c] > 0){
            counter++;
        }
        c++;
    }
    counter--;
    sort(numArray, counter);
    
    c = 0;
    while(c < counter){
        printf("%d. %d\n", d, numArray[c]);
        c++;
        d++;
    }
}

void sort(int array[], int count){
    int i, j, t;
    for(i = 0; i < (count - 1); i++){
        for(j = 0; j < count - i - 1; j++){
            if(array[j] > array[j+1]){
                
                t = array[j];
                array[j] = array[j + 1];
                array[j + 1] = t;
            }
        }
        
    }
}
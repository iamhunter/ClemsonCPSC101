//
//  bullsandcows.c
//  
//
//  Created by Andrew Marion Hunter on 2/9/15.
//
//

/*
 Collaboration Statement
 
 Name:Andrew Hunter
 Assignment title:Bulls and Cows
 
 Who did you work with on this project (if anyone)? N/A
 
 
 If you worked with others, what was your contribution? N/A
 
 
 What outside resources did you use, if any? (books, Internet) The Internet for the random integers as well as for some help with arrays
 
 
 By submitting this collaboration statement you affirm that you wrote all the code on your own.
*/

/*
 Algorithm
 
 1. Define all the integers as well as the array
 2. Assign random integers to every spot in the array
 3. While any integer within the array equals any other integer within the array, assign new random integers to every spot
 4. Ask the user to enter how long the code will be
 5. If the code is not between two and six digits, inform the user and end the program
 6. Use the loop that cooridintates to how many digits are in the code
 7. Have the user guess the code
 8. Tell the user how many bulls and cows they have
 9. If zero is in the guessed code, print the code
10. If they have all cows, tell them that they have won
11. If they do not, repeat the code until they do
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void){
    
    //Use time so the random integers will be different every time
    srand(time(0));
    
    //Define all the integers that will be used
    int codeDigits = 0;
    int array[6];
    int a = 0;
    int b = 0;
    int c = 0;
    int guessOne, guessTwo, guessThree, guessFour, guessFive, guessSix;
    int bulls = 0;
    int cows = 0;
    int code = 0;
    
    
    //Assign random integers between 0 and 9 to each spot in the array
    for (a = 0; a < 6; a++){
        array[a] = rand() % 10;
    }
    
    //While any integer equals any other integer within the array....
    while(array[0] == array[1] || array[0] == array[2] || array[0] == array[3] || array[0] == array[4] || array[0] == array[5] ||
          array[1] == array[2] || array[1] == array[3] || array[1] == array[4] || array[1] == array[5] ||
          array[2] == array[3] || array[2] == array[4] || array[2] == array[5] ||
          array[3] == array[4] || array[3] == array[5] ||
          array[4] == array[5]){
        
        //Assign new random integers to every spot
        for (b = 0; b < 6; b++){
            array[b] = rand() % 10;
        }
        b = 0;
    }
    
    //Ask the user to enter how long the code will be
    printf("How many digits(between two and six) are in the code?\n");
    scanf("%d",&codeDigits);
    
    //If the code is not between two and six digits, inform the user and end the program
    if (codeDigits < 2||codeDigits > 6){
        printf("You did not enter an integer between two and six digits. Please try again.\n");
    }
    
    //If the code is two digits long, use this loop
    if (codeDigits == 2){
        while(cows < 2){
            
            cows = 0;
            bulls = 0;
            
            //Have the user guess the code
            printf("Guess the code:");
            scanf("%d", &code);
            
            //Break down the user's entered code into individual digits and assign these to the proper variable
            guessTwo = code % 10;
            guessOne = ((code - guessTwo)/10) % 10;
            
            //Assign cows and bulls
            if(guessOne == array[0]){
                cows = cows + 1;
            }
            if(guessTwo == array[1]){
                cows = cows + 1;
            }
            if(guessTwo == array[0]){
                bulls = bulls + 1;
            }
            if(guessOne == array[1]){
                bulls = bulls + 1;
            }
            
            //If the user did not enter the correct code, tell them how many cows and bulls they entered
            if(cows < 2){
                printf("    Nope! %d Cows, %d Bulls\n", cows, bulls);
            }
            
            //If the user enters zero, print the code for them
            if(guessOne == 0 || guessTwo == 0){
                printf("Because you entered zero... ");
                while(c<6){
                    printf("%d", array[c]);
                    c++;
                }
                printf(" \n"); 
            }
        }
        //Once they have all cows, inform the user that they have won
        printf("You Won!\n");
    }
    
    //If the code is three digits long, use this loop
    if (codeDigits == 3){
        while(cows < 3){
            
            cows = 0;
            bulls = 0;
            
            //Have the user guess the code
            printf("Guess the code:");
            scanf("%d", &code);
            
            //Break down the user's entered code into individual digits and assign these to the proper variable
            guessThree = code % 10;
            guessTwo = ((code - guessThree)/10) % 10;
            code = ((code - guessThree)/10);
            guessOne = ((code - guessTwo)/10) % 10;
            
            //Assign cows and bulls
            if(guessOne == array[0]){
                cows = cows + 1;
            }
            if(guessTwo == array[1]){
                cows = cows + 1;
            }
            if(guessThree == array[2]){
                cows = cows + 1;
            }
            if(guessTwo == array[0] || guessThree == array[0]){
                bulls = bulls + 1;
            }
            if(guessOne == array[1] || guessThree == array[1]){
                bulls = bulls + 1;
            }
            if(guessOne == array[2] || guessTwo == array[2]){
                bulls = bulls +1;
            }
            
            //If the user did not enter the correct code, tell them how many cows and bulls they entered
            if(cows < 3){
                printf("    Nope! %d Cows, %d Bulls\n", cows, bulls);
            }
            
            //If the user enters zero, print the code for them
            if(guessOne == 0 || guessTwo == 0 || guessThree == 0){
                printf("Because you entered zero... ");
                while(c<6){
                    printf("%d", array[c]);
                    c++;
                }
                printf(" \n");

            }
        }
        
        //Once they have all cows, inform the user that they have won
        printf("You Won!\n");
    }
    
    //If the code is four digits long, use this loop
    if (codeDigits == 4){
        while(cows < 4){
            
            cows = 0;
            bulls = 0;
            
            //Have the user guess the code
            printf("Guess the code:");
            scanf("%d", &code);
            
            //Break down the user's entered code into individual digits and assign these to the proper variable
            guessFour = code % 10;
            guessThree = ((code - guessFour)/10) % 10;
            code = ((code - guessFour)/10);
            guessTwo = ((code - guessThree)/10) % 10;
            code = ((code - guessThree)/10);
            guessOne = ((code - guessTwo)/10) % 10;

            
            //Assign cows and bulls
            if(guessOne == array[0]){
                cows = cows + 1;
            }
            if(guessTwo == array[1]){
                cows = cows + 1;
            }
            if(guessThree == array[2]){
                cows = cows + 1;
            }
            if(guessFour == array[3]) {
                cows = cows + 1;
            }
            if(guessTwo == array[0] || guessThree == array[0] || guessFour == array[0]){
                bulls = bulls + 1;
            }
            if(guessOne == array[1] || guessThree == array[1] || guessFour == array[1]){
                bulls = bulls + 1;
            }
            if(guessOne == array[2] || guessTwo == array[2] || guessFour == array[2]){
                bulls = bulls + 1;
            }
            if(guessOne == array[3] || guessTwo == array[3] || guessThree == array[3]){
                bulls = bulls + 1;
            }
            
            //If the user did not enter the correct code, tell them how many cows and bulls they entered
            if(cows < 4){
                printf("    Nope! %d Cows, %d Bulls\n", cows, bulls);
            }
            
            //If the user enters zero, print the code for them
            if(guessOne == 0 || guessTwo == 0 || guessThree == 0 || guessFour == 0){
                printf("Because you entered zero... ");
                while(c<6){
                    printf("%d", array[c]);
                    c++;
                }
                printf(" \n");
            }
        }
        
        //Once they have all cows, inform the user that they have won
        printf("You Won!\n");
    }
    
    //If the code is five digits long, use this loop
    if (codeDigits == 5){
        while(cows < 5){
            
            cows = 0;
            bulls = 0;
            
            //Have the user guess the code
            printf("Guess the code:");
            scanf("%d", &code);
            
            //Break down the user's entered code into individual digits and assign these to the proper variable
            guessFive = code % 10;
            guessFour = ((code - guessFive)/10) % 10;
            code = ((code - guessFive)/10);
            guessThree = ((code - guessFour)/10) % 10;
            code = ((code - guessFour)/10);
            guessTwo = ((code - guessThree)/10) % 10;
            code = ((code - guessThree)/10);
            guessOne = ((code - guessTwo)/10) % 10;
            
            //Assign cows and bulls
            if(guessOne == array[0]){
                cows = cows + 1;
            }
            if(guessTwo == array[1]){
                cows = cows + 1;
            }
            if(guessThree == array[2]){
                cows = cows + 1;
            }
            if(guessFour == array[3]){
                cows = cows + 1;
            }
            if(guessFive == array[4]){
                cows = cows + 1;
            }
            if(guessTwo == array[0] || guessThree == array[0] || guessFour == array[0] || guessFive == array[0]){
                bulls = bulls + 1;
            }
            if(guessOne == array[1] || guessThree == array[1] || guessFour == array[1] || guessFive == array[1]){
                bulls = bulls + 1;
            }
            if(guessOne == array[2] || guessTwo == array[2] || guessFour == array[2] || guessFive == array[2]){
                bulls = bulls + 1;
            }
            if(guessOne == array[3] || guessTwo == array[3] || guessThree == array[3] || guessFive == array[3]){
                bulls = bulls + 1;
            }
            if(guessOne == array[4] || guessTwo == array[4] || guessThree == array[4] || guessFour == array[4]){
                bulls = bulls + 1;
            }
            
            //If the user did not enter the correct code, tell them how many cows and bulls they entered
            if(cows < 5){
                printf("    Nope! %d Cows, %d Bulls\n", cows, bulls);
            }
            
            //If the user enters zero, print the code for them
            if(guessOne == 0 || guessTwo == 0 || guessThree == 0 || guessFour == 0 || guessFive == 0){
                printf("Because you entered zero... ");
                while(c<6){
                    printf("%d", array[c]);
                    c++;
                }
                printf(" \n");
            }
        }
        
        //Once they have all cows, inform the user that they have won
        printf("You Won!\n");
    }
    
    //If the code is six digits long, use this loop
    if (codeDigits==6){
        while(cows<6){
            
            cows = 0;
            bulls = 0;
            
            //Have the user guess the code
            printf("Guess the code:");
            scanf("%d", &code);
            
            //Break down the user's entered code into individual digits and assign these to the proper variable
            guessSix = code % 10;
            guessFive = ((code - guessSix)/10) % 10;
            code = ((code - guessSix)/10);
            guessFour = ((code - guessFive)/10) % 10;
            code = ((code - guessFive)/10);
            guessThree = ((code - guessFour)/10) % 10;
            code = ((code - guessFour)/10);
            guessTwo = ((code - guessThree)/10) % 10;
            code = ((code - guessThree)/10);
            guessOne = ((code - guessTwo)/10) % 10;
            
            
            //Assign cows and bulls
            if(guessOne == array[0]){
                cows = cows + 1;
            }
            if(guessTwo == array[1]){
                cows = cows + 1;
            }
            if(guessThree == array[2]){
                cows = cows + 1;
            }
            if(guessFour == array[3]){
                cows = cows + 1;
            }
            if(guessFive == array[4]){
                cows = cows + 1;
            }
            if(guessSix == array[5]){
                cows = cows + 1;
            }
            if(guessTwo == array[0] || guessThree == array[0] || guessFour == array[0] || guessFive == array[0] || guessSix == array[0]){
                bulls = bulls + 1;
            }
            if(guessOne == array[1] || guessThree == array[1] || guessFour == array[1] || guessFive == array[1] || guessSix == array[1]){
                bulls = bulls + 1;
            }
            if(guessOne == array[2] || guessTwo == array[2] || guessFour == array[2] || guessFive == array[2] || guessSix == array[2]){
                bulls = bulls +1;
            }
            if(guessOne == array[3] || guessTwo == array[3] || guessThree == array[3] || guessFive == array[3] || guessSix == array[3]){
                bulls = bulls + 1;
            }
            if(guessOne == array[4] || guessTwo == array[4] || guessThree == array[4] || guessFour == array[4] || guessSix ==array[4]){
                bulls = bulls + 1;
            }
            if(guessOne == array[5] || guessTwo == array[5] || guessThree == array[5] || guessFour == array[5] || guessFive == array[5]){
                bulls = bulls +1;
            }
            
            //If the user did not enter the correct code, tell them how many cows and bulls they entered
            if(cows < 6){
                printf("    Nope! %d Cows, %d Bulls\n", cows, bulls);
            }
            
            //If the user enters zero, print the code for them
            if(guessOne == 0 || guessTwo == 0 || guessThree == 0 || guessFour == 0 || guessFive == 0 || guessSix == 0){
                printf("Because you entered zero... ");
                while(c<6){
                    printf("%d", array[c]);
                    c++;
                }
                printf(" \n"); 
            }
        }
        
        //Once they have all cows, inform the user that they have won
        printf("You Won!\n");
    }
}
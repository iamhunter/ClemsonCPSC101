//
//  project1flappybird.c
//  
//
//  Created by Andrew Marion Hunter on 1/14/15.
/*
 1. Define the variables and assign values to the given variables
 2. Use a while statement to repeat the program if the time between the flaps is greater or equal to .5 seconds
 3. Have the user input the horizontal distance, Flappy Bird's height and the height of the next pipe
 4. Calculate the time to the next obstacle, the vertical distance to the next obstacle, the number of flaps and the time between each flap
 5. Print the number of flaps and the time between the flaps
 6. If the time between flaps is greater than or equal to .5, repeat the program
 7. If the time between flaps is less than .5, end the program by printing "Game Over!"

*/
#include <stdio.h>

int main(void)

{

    // Define variables as either integers or floating decimal point
    int hdist, vdist, birdHeight, obHeight, flaps, hrate, vrate, final;
    float betweenFlaps, time;
    
    // Define values to the given variables of horizontal rate and vertical rate
    hrate = 3;
    vrate = 2;
    
    // Define final for the while statement
    final=1;
    
    // Call while statement to repeat the program if the time between the flaps is greater or equal to .5 seconds
    // If the variable while holds 1, the program repeats itself
    while (final==1) {
        
        // Ask user to input the horizontal distance between Flappy Bird and the next obstacle
        printf("Please enter the horizontal distance between Flappy Bird and the next obstacle\n");
        scanf("%d", &hdist);
    
        // Ask user to input Flappy Bird's height
        printf("Please enter Flappy Bird's height\n");
        scanf("%d", &birdHeight);
    
        // Ask user to input the next pipe's height
        printf("Please enter the next pipe's height\n");
        scanf("%d", &obHeight);
        
        // Calculate the time that it will take for Flappy Bird to reach the next obstacle
        time = (float)hdist / hrate;
    
        // Calculate the vertical distance between Flappy Bird and the next obstacle
        vdist = obHeight - birdHeight;
    
        // Calculate the number of flaps that Flappy Bird needs to take
        flaps = (float)vdist / vrate;
    
        // Calculate the time between each flap
        betweenFlaps = time / flaps;
        
        // Print the number of flaps and the time between the flaps
        // If the time inbetween the flaps is greater than or equal to .5, assign one to the variable final and repeat the program
        if (betweenFlaps >= .5){
            printf("Flappy Bird needs to flap %d times, %.2f seconds apart each time\n", flaps, betweenFlaps);
            final = 1;
        }
        // Print the number of flaps and the time between the flaps
        // If the time inbetween the flaps is less than .5, assign 0 to the variable final, print "Game Over!" and end the function
        if (betweenFlaps < .5) {
            printf("Flappy Bird needs to flap %d times, %.2f seconds apart each time\n", flaps, betweenFlaps);
            printf("Game Over!\n");
            final = 0;
        }
    }
return (0);
    
}
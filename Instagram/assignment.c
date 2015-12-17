/*
Algorithm
 1. User inputs output, input and a filter
 2. Program checks number of inputs
 3. Program reads PPM file
 4. Program checks filter name
 5. Program applies correct filter
 6. Program writes filter onto a new PPM Image
*/



/*
 Name: Andrew Marion Hunter
 Assignment title: Instagram
 
 Who did you work with on this project (if anyone)?
 Worked with Greg and Matthew
 
 If you worked with others, what was your contribution?
 I figured out most of it and helped them out with parts.
 
 What outside resources did you use, if any? (books, Internet)
 http://web.cs.swarthmore.edu/~newhall/unixhelp/C_arrays.html
 Other stackoverflow
 other C libraries
 
 By submitting this collaboration statement you affirm that you wrote all the code on your own.
 Indeed I did
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "instagram.h"

int main(int argc, char * argv[]){
    int width, height;
    char input[100];
    char output[100];
    char filter[100];
    pixel * image = NULL;
    
    strcpy(input, argv[1]);
    strcpy(output, argv[2]);
    strcpy(filter, argv[3]);

    
    //Check the number of arguments
    if(argc == 4){
        
        //Read the image into image
        image = readPPMFile(input,&width,&height);

        //Check the filter and write the ppm file
        if(strncmp(filter, "contrast", 100) == 0){
            contrast(image,width,height);
            writePPMFile(output,image,width,height);
        }
        else if(strncmp(filter, "normalize", 100) == 0){
            normalize(image,width,height);
            writePPMFile(output,image,width,height);
        }
        else if(strncmp(filter, "shaky", 100) == 0){
            shaky(image,width,height);
            writePPMFile(output,image,width,height);
        }
        else if(strncmp(filter, "soften", 100) == 0){
            soften(image,width,height);
            writePPMFile(output,image,width,height);
        }
        else if(strncmp(filter, "noiseremove", 100) == 0){
            noiseremove(image,width,height);
            writePPMFile(output,image,width,height);
        }
        else if(strncmp(filter, "dilate", 100) == 0){
            image = dilate(image,width,height);
            writePPMFile(output,image,width,height);
        }
        else if(strncmp(filter, "edgefind", 100) == 0){
            image = edgefind(image,width,height);
            writePPMFile(output,image,width,height);
        }
        //If the filter isn't listed, inform the user
        else{
            printf("we're sorry but we don't have a %s filter\n", filter);
        }
    }
    //If the user doesn't enter 4 command prompts, inform the user
    else{
        printf("You did not enter the correct number of command line parameters; Please try again.\n");
    }
    
    free(image);
    
    return 0;
}

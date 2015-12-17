//
//  instagram.c
//  
//
//  Created by Andrew Marion Hunter on 4/6/15.
//



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "instagram.h"

//Creates the 2d array as a 1d array?
int subscript(int r, int c, int width){
        return r * width + c;
}

//Generates a random number
int randomNumber(int lowest, int highest){
    int range = highest - lowest + 1;
    return rand() % range + lowest;
}


//Sorts a list of integers
void sort(int vals[], int length){
    int i, j, t;
    for(i = 0; i < (length - 1); i++){
        for(j = 0; j < length - i - 1; j++){
            if(vals[j] > vals[j+1]){
                
                t = vals[j];
                vals[j] = vals[j + 1];
                vals[j + 1] = t;
            }
        }
    }
}

//Writes a ppm header
void writeHeader(FILE * file, int width, int height){
    fprintf(file,"P6\n %d %d 255\n",width,height);
}

//Writes a pixel for a PPM image
void writePixel(FILE * file, pixel p){
    fprintf(file,"%c%c%c",(unsigned char)p.r,(unsigned char)p.g, (unsigned char)p.b);
}

//Writes a PPM file
void writePPMFile(char * filename, pixel * picture, int width, int height){
    FILE * writeFile = fopen(filename,"w");
    writeHeader(writeFile,width,height);
    

    int r, c;
    for (r = 0; r < height; r++){
        for (c = 0; c < width; c++){
            writePixel(writeFile,picture[subscript(r,c,width)]);
        }
    }
    fclose(writeFile);
}

//Reads a PPM Header
void readHeader(FILE * file, int * width, int * height){
    fscanf(file,"P6\n %d %d 255\n",width,height);
}

//Reads a PPM Pixel
void readPixel(FILE * file, pixel * p){
    unsigned char r, g, b;
    fscanf(file,"%c%c%c",&r,&g,&b);
    p->r = r;
    p->g = g;
    p->b = b;
}

//Reads a PPM file
pixel * readPPMFile(char * filename, int * width, int * height){
    FILE * readFile = fopen(filename,"r");
        readHeader(readFile,width,height);
    
    pixel * image = malloc(sizeof(pixel)*(*width)*(*height));
    
    int r, c;
    for (r = 0; r < *height; r++){
        for (c = 0; c < *width; c++){
            readPixel(readFile,&image[subscript(r,c,*width)]);
        }
    }
    
    fclose(readFile);
    return image;
    free(image);
}

//Contrast Function
void contrast(pixel * image, int width, int height){
    int value;
    
    printf("Please enter an integer between 0 and 255");
    scanf("%d",&value);
    
    int r, c;
    for (r = 0; r < height; r++){
        for (c = 0; c < width; c++){
		pixel pix = image[subscript(r,c,width)];
            //If the pixel is less than user input
            if(pix.r < value || pix.g < value || pix.b < value){
                //Set value to 255
                pix.r = 255;
                pix.g = 255;
                pix.b = 255;
            }
            else{
                //Otherwise set value to zero
                pix.r = 0;
                pix.g = 0;
                pix.b = 0;
            }
		image[subscript(r,c,width)] = pix;
        }
    }
}

//Normalize Function
void normalize(pixel * image, int width, int height){
    int value;
    int rMinimumValue = 255;
    int gMinimumValue = 255;
    int bMinimumValue = 255;
    int rMaximumValue = 0;
    int gMaximumValue = 0;
    int bMaximumValue = 0;
    
    int r, c;
    for (r = 0; r < height; r++){
        for (c = 0; c < width; c++){
            pixel pix = image[subscript(r,c,width)];
            
            //Set Minimum and Maximum values for each channel
            if(pix.r < rMinimumValue){
                rMinimumValue = pix.r;
            }
            else if(pix.r > rMaximumValue){
                rMaximumValue = pix.r;
            }
            else if(pix.g < gMinimumValue){
                gMinimumValue = pix.g;
            }
            else if(pix.g > gMaximumValue){
                gMaximumValue = pix.g;
            }
            else if(pix.b < bMinimumValue){
                bMinimumValue = pix.b;
            }
            else if(pix.b > bMaximumValue){
                bMaximumValue = pix.b;
            }
        }
    }
    //Apply formula
    for (r = 0; r < height; r++){
        for (c = 0; c < width; c++){
            pixel pix = image[subscript(r,c,width)];
            
            pix.r = (pix.r - rMinimumValue) * (rMaximumValue - rMinimumValue) / 255.0 + rMinimumValue;
            pix.g = (pix.g - gMinimumValue) * (gMaximumValue - gMinimumValue) / 255.0 + gMinimumValue;
            pix.b = (pix.b - bMinimumValue) * (bMaximumValue - bMinimumValue) / 255.0 + bMinimumValue;
            
            image[subscript(r,c,width)] = pix;
        }
    }
}

//Shaky function
void shaky(pixel * image, int width, int height){
    srand(time(NULL));
    
    int r, c;
    int randomR, randomC;
    for (r = 1; r < height-2; r++){
        for (c = 1; c < width-2; c++){
            pixel pix = image[subscript(r,c,width)];
            
            //Set a random row and column
            randomR = randomNumber(r-1, r+1);
            randomC = randomNumber(c-1, c+1);
            
            pixel rando = image[subscript(randomR,randomC,width)];
            
            pix.r = rando.r;
            pix.g = rando.g;
            pix.b = rando.b;
            
            image[subscript(r,c,width)] = pix;
        }
    }
}


//Soften function
void soften(pixel * image, int width, int height){
    int r, c;
    for (r = 1; r < height-1; r++){
        for (c = 1; c < width-1; c++){
            pixel pix = image[subscript(r,c,width)];

            
            //Find values of all neighbors
            pixel tl = image[subscript(r + 1,c - 1,width)];
            pixel t = image[subscript(r + 1,c,width)];
            pixel tr = image[subscript(r + 1,c + 1,width)];
            pixel l = image[subscript(r,c - 1,width)];
            pixel right = image[subscript(r,c + 1,width)];
            pixel bl = image[subscript(r - 1,c - 1,width)];
            pixel b = image[subscript(r - 1,c,width)];
            pixel br = image[subscript(r - 1,c + 1,width)];

            //Add them all together and divide by 9
            pix.r = (tl.r + t.r + tr.r + l.r + pix.r + right.r + bl.r + b.r + br.r)/9;
            pix.g = (tl.g + t.g + tr.g + l.g + pix.g + right.g + bl.g + b.g + br.g)/9;
            pix.b = (tl.b + t.b + tr.b + l.b + pix.b + right.b + bl.b + b.b + br.b)/9;
            
            image[subscript(r,c,width)] = pix;
        }
    }
}


//Noiseremove function
void noiseremove(pixel * image, int width, int height){
    int r, c;
    for (r = 1; r < height-2; r++){
        for (c = 1; c < width-2; c++){
            pixel pix = image[subscript(r,c,width)];
            
            //Find all the neighbors
            pixel tl = image[subscript(r + 1,c - 1,width)];
            pixel t = image[subscript(r + 1,c,width)];
            pixel tr = image[subscript(r + 1,c + 1,width)];
            pixel l = image[subscript(r,c - 1,width)];
            pixel right = image[subscript(r,c + 1,width)];
            pixel bl = image[subscript(r - 1,c - 1,width)];
            pixel b = image[subscript(r - 1,c,width)];
            pixel br = image[subscript(r - 1,c + 1,width)];
            
            //Set them all in an array
            int arrayR[9] = {tl.r, t.r, tr.r, l.r, pix.r, right.r, bl.r, b.r, br.r};
            int arrayG[9] = {tl.g, t.g, tr.g, l.g, pix.g, right.g, bl.g, b.g, br.g};
            int arrayB[9] = {tl.b, t.b, tr.b, l.b, pix.b, right.b, bl.b, b.b, br.b};
            
            sort(arrayR, 9);
            sort(arrayG, 9);
            sort(arrayB, 9);
            
            //Set pix to the median
            pix.r = arrayR[4];
            pix.g = arrayG[4];
            pix.b = arrayB[4];
            
            image[subscript(r,c,width)] = pix;
        }
    }
}


//Dilate function
pixel * dilate(pixel * image, int width, int height){
    
    int r, c;
    //Dynamically allocate array
    pixel * array = malloc(sizeof(pixel)*(width)*(height));
    
    
    for (r = 1; r < height-1; r++){
        for (c = 1; c < width-1; c++){
            pixel pix = image[subscript(r,c,width)];
            
            pixel tl = image[subscript(r + 1,c - 1,width)];
            pixel t = image[subscript(r + 1,c,width)];
            pixel tr = image[subscript(r + 1,c + 1,width)];
            pixel l = image[subscript(r,c - 1,width)];
            pixel right = image[subscript(r,c + 1,width)];
            pixel bl = image[subscript(r - 1,c - 1,width)];
            pixel b = image[subscript(r - 1,c,width)];
            pixel br = image[subscript(r - 1,c + 1,width)];
            
            int arrayR[9] = {tl.r, t.r, tr.r, l.r, pix.r, right.r, bl.r, b.r, br.r};
            int arrayG[9] = {tl.g, t.g, tr.g, l.g, pix.g, right.g, bl.g, b.g, br.g};
            int arrayB[9] = {tl.b, t.b, tr.b, l.b, pix.b, right.b, bl.b, b.b, br.b};
            
            sort(arrayR, 9);
            sort(arrayG, 9);
            sort(arrayB, 9);
            
            //Set to the max value
            pix.r = arrayR[8];
            pix.g = arrayG[8];
            pix.b = arrayB[8];
        
            array[r * width + c] = pix;
        }
    }
    //Returns the array
    return array;
    free(array);
}

//Edgefind Function
pixel * edgefind(pixel * image, int width, int height){
    
    
    int r, c;
    pixel * array = malloc(sizeof(pixel)*(width)*(height));
    
    
    for (r = 1; r < height-1; r++){
        for (c = 1; c < width-1; c++){
            pixel pix = image[subscript(r,c,width)];
            
            pixel tl = image[subscript(r + 1,c - 1,width)];
            pixel t = image[subscript(r + 1,c,width)];
            pixel tr = image[subscript(r + 1,c + 1,width)];
            pixel l = image[subscript(r,c - 1,width)];
            pixel right = image[subscript(r,c + 1,width)];
            pixel bl = image[subscript(r - 1,c - 1,width)];
            pixel b = image[subscript(r - 1,c,width)];
            pixel br = image[subscript(r - 1,c + 1,width)];
            
            //Add together the values of the neighbors
            int totalR = tl.r + t.r + tr.r + l.r + right.r + bl.r + b.r + br.r;
            int totalG = tl.g + t.g + tr.g + l.g + right.g + bl.g + b.g + br.g;
            int totalB = tl.b + t.b + tr.b + l.b + right.b + bl.b + b.b + br.b;
            
            //Set pv = image
            pixel pv = image[subscript(r,c,width)];
            
            //Multiply pix * 8 and subtract total values
            pv.r = pix.r * 8 - totalR;
            pv.g = pix.g * 8 - totalG;
            pv.b = pix.b * 8 - totalB;

            //If the value is greater than 255, make the value 255
            if(pv.r > 255){
                pv.r = 255;
            }
            if(pv.g > 255){
                pv.g = 255;
            }
            if(pv.b > 255){
                pv.b = 255;
            }
            
            //If the value is less than 0, make the value 0
            if(pv.r < 0){
                pv.r = 0;
            }
            if(pv.g < 0){
                pv.g = 0;
            }
            if(pv.b < 0){
                pv.b = 0;
            }
            
            pix.r = pv.r;
            pix.g = pv.g;
            pix.b = pv.b;
            
            array[r*width+c] = pix;
        }
    }
    return array;
    free(array);
}
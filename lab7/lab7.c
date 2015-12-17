//
// Andrew Hunter
// CPSC 101 Lab 7
// March 3, 2015 
// Image File Creation
//
//

#include <stdio.h>

void make_pixel(int r, int g, int b);
void make_ppm_header(int width, int height);
void make_ppm_image(int country_code, int width);


int main(){
    int width;
    int country_code;
    // prompt user to enter width and country_code of chosen flag
    fprintf(stderr, "Enter a country code and the width");
    /* Read image dimensions and pixel color */
    fscanf(stdin, "%d %d", &country_code, &width);
    fprintf(stderr, "Making country %d with width %d \n",country_code, width);
    /* Write the image data */
    make_ppm_image(country_code, width);
    return(0);
}

void make_ppm_image(int country_code, int width){
    int r, c;
    //Ukraine
    if(country_code==0){
        int height = width*2/3;
        
        make_ppm_header(width, height);
        
        for(r = 0; r < height/2; r++){
            for(c = 0; c < width; c++){
                make_pixel(0,91,187);
            }
        }
        for(r = height/2; r < height; r++){
            for(c = 0; c < width; c++)
                make_pixel(255,213,0);
        }
    }
    //Russia
    if(country_code==1){

        int height = width*2/3;
        
        make_ppm_header(width, height);
        
        for(r = 0; r < height/3; r++){
            for(c = 0; c < width; c++){
                make_pixel(225,225,255);
            }
        }
        for(r = height/3; r < height*2/3; r++){
            for(c = 0; c < width; c++)
                make_pixel(0,0,255);
        }
        for(r = height*(2/3); r < height; r++){
            for(c = 0; c < width; c++)
                make_pixel(255,0,0);
        }
    }
    //Ireland
    if(country_code==2){
        int height = width/2;
        
        make_ppm_header(width, height);
        
        for(r = 0; r < height; r++){
            for(c = 0; c < width/3; c++){
		make_pixel(0,128,0);
            }
            for(c = width/3; c < width* 2/3; c++){
                make_pixel(255,255,255);
            }
            for(c = width*2/3; c < width; c++){
                make_pixel(255,165,0);
            }
        }
    }
}

void make_pixel (int r, int g, int b ){
    fprintf(stdout, "%c%c%c", r, g, b);
}
           
void make_ppm_header (int width, int height){
    fprintf(stdout, "P6\n");
    fprintf(stdout, "%d %d %d\n", width, height, 255);
}

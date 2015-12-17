//////////////////
// helpers	//
//////////////////

// Compile like this .... gcc assignment.c instagram.c –g –lm 


#include "instagram.h"


//Transforms a 2d subscript into a 1d subscript.
int subscript(int r, int c, int width){
	return r * width + c;
}

//Generates a random integer between a range.
int randomNumber(int lowest, int highest){
	int range = highest - lowest + 1;
	return rand() % range + lowest;
}

void sort(int vals[], int length){
  //You may fill this in if you find it helpful.
}

//////////////////////////////////
// PPM writing functions 	//
//////////////////////////////////

void writeHeader(FILE * file, int width, int height){
	fprintf(file,"P6\n %d %d 255\n",width,height);
}

void writePixel(FILE * file, pixel p){
	fprintf(file,"%c%c%c",(unsigned char)p.r,(unsigned char)p.g, (unsigned char)p.b);
}

/*
writePPM algorithm:
1. Open a file for writing. The file name should be the first parameter, filename.
2. Write the PPM header to that file using the writeHeader function.
3. For each row r, from 0 to height
	a. For each column c, from 0 to width
		i. Write the pixel at picture r,c to file using the writePixel function.
			Use the subscript function to calculate the correct subscript.
4. Close the file
*/
void writePPMFile(char * filename, pixel * picture, int width, int height){

}


//////////////////////////////////
// PPM writing functions	//
//////////////////////////////////

void readHeader(FILE * file, int * width, int * height){
	fscanf(file,"P6\n %d %d 255\n",width,height);
}

void readPixel(FILE * file, pixel * p){
	unsigned char r, g, b;
	fscanf(file,"%c%c%c",&r,&g,&b);
	p->r = r;
	p->g = g;
	p->b = b;
}

/*
readPPM algorithm:
1. Open a file for reading. The filename should be the first parameter, filename.
2. Read the PPM header from the file using readHeader function.
3. Dynamically allocate a 1D array to image that is as big as it needs to be to hold the image.
4. For each row r, from 0 to height
	a. For each column c, from 0 to width
		i. Read the pixel into the image at pixel r,c. Use the subscript function
			to calculate the right spot to put it in the array.
5. Close the file.
*/

pixel * readPPMFile(char * filename, int * width, int * height){
	//Open a file for reading. The filename should be the first parameter, filename.
	FILE * readFile = fopen(filename,"r");
	
	//Read the PPM header from the file using the readheader function.
	readHeader(readFile,width,height);

	//Dynamically allocate a 1D array to image that's big enough to hold all the pixels.
	pixel * image = malloc(sizeof(pixel)*(*width)*(*height));

	//For each row r, from 0 to height
	int r, c;
	for (r = 0; r < *height; r++){
		//For each column c, from 0 to width
		for (c = 0; c < *width; c++){
			//read a pixel into the right spot
			readPixel(readFile,&image[subscript(r,c,*width)]);
		}
	}
  //close the file
	fclose(readFile);
   //return a pointer to the image
	return image;
}

//////////////////////////
// Filters		//
//////////////////////////

/*
Algorithm for contrast
1. Prompt the user for a value between 0 and 255.
2. For each pixel:
	a. If any of three of the color channel values are below that value
		i. Make the pixel white.
	b. Otherwise
		i. Make the pixel black
*/

void contrast(pixel * image, int width, int height){

}

/*
Algorithm for normalize:
(Find the lowest and highest values in the image.)
1. For every pixel in the image:
	a. For each color channel (r, g, b)
		i. If the value is lower than the lowest value you've seen for this color channel so far,
			let the new lowest value be this one
		ii. If the value is higher than thae highest value  you've seen for this color channel sofar,
			let the new highest value be this one.
2. For each pixel in the image:
	a. for each color channel (r,g,b)
		i. Apply this formula:
			value = (currentValue - minimumValue) * (maximum value - minimum value) / 255.0 + minimum value 
*/

void normalize(pixel * image, int width, int height){

}

/*
Algorithm for shaky
1. For each row r, from 1 to height-2
	a. For each row c, from 1 to width-2
		i. Randomly select a row between r-1 and r + 1 using the random() function
		ii. Randomly select a column between c-1 and c + 1 using the random() function
		iii. Set the pixel at r, c to the pixel at the randomly generated row and column
*/
void shaky(pixel * image, int width, int height){
  //Please leave this at the top of this function, it will seed the random number generator
	srand(time(NULL));

}


/*
Algorithm for soften:
1. For each row r, from 0 to height-1
        a. For each column c, from 0 to width-1
                i. For each color channel (r, g, and b)
			I. Average together the pixel's values and all its immediate neighbors
			II. Give the pixel r,c, that average value

*/


void soften(pixel * image, int width, int height){

}

/*
Algorithm for noiseremove
1. For each row r, from 1 to width-2
	a. For each column c, from 1 to width -2
		i. For each color channel (r,g,b)
			I. Put all the values for that pixel and its neighbors in an array of nine integers.
			II. Sort the array of integers. You may write a sort function to do this,
				or refer to the class notes to find one.
			III. Set the color channel's value to the one in the middle 
				of the array (subscript 4), which is the median.

*/

void noiseremove(pixel * image, int width, int height){

}


/*
 Algorithm for dilate:
1. Allocate space for a new image of the same size.
2. For each row r, from 0 to height-1
	a. For each column c, from 0 to width-1
		i. For each color channel (r, g, and b)
			I. Find the maximum value for that color channel 
			   between the pixel at r,c and all its neighbors
			II. Assign pixel r,c, in the new image for that color channel, that maximum value.
3. Return the pointer to the new image.
*/
pixel * dilate(pixel * image, int width, int height){

}

/*
Algorithm for edgefind:
1. Allocate enough space for a new image of the same size.
2. For each row r, from 0 to height-1
	a. For each column c, from 0 to width-1
		i. For each color channel (r, g, and b)
			I. Sum the pixel's neighbors in the original image, and keep a count of how many neighbors there are
			II. Multiply the value by the number of immediate neighbors it has
			III. From that product, subtract off the sum. Let this equal pv.
			IV. If pv > 255, then let pv = 255. If pv < 0, let pv = 0. Check out the fmax and fmin functions.
			V. Set pixel r, c, in the new image at that color channel, to pv.
3. Return the pointer to the new image.
*/
pixel * edgefind(pixel * image, int width, int height){

}
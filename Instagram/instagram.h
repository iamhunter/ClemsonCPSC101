#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    int r;
    int g;
    int b;
} pixel;


int subscript(int r, int c, int width);
int randomNumber(int lowest, int highest);
void sort(int vals[], int length);

void writeHeader(FILE * file, int width, int height);
void writePixel(FILE * file, pixel p);
void writePPMFile(char * filename, pixel * picture, int width, int height);

void readHeader(FILE * file, int * width, int * height);
void readPixel(FILE * file, pixel * p);
pixel * readPPMFile(char * filename, int * width, int * height);

pixel * dilate(pixel * image, int width, int height);
pixel * edgefind(pixel * image, int width, int height);
void soften(pixel * image, int width, int height);
void contrast(pixel * image, int width, int height);
void normalize(pixel * image, int width, int height);
void shaky(pixel * image, int width, int height);
void noiseremove(pixel * image, int width, int height);
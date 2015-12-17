#include<stdio.h>



int main(void){

	int width, height, r, c;

	scanf("P6\n %d %d 255\n", &width, &height);

	typedef struct pixel_type{
		unsigned char r;
		unsigned char g;
		unsigned char b;
	}pixel_t;

	pixel_t pixel[width][height];

	for(c = 0; c < width; c++){
		for(r = 0; r < height; r++){
			scanf("%c%c%c", &pixel[c][r].r, &pixel[c][r].g, &pixel[c][r].b);
		}
	}

	for(c = 0; c < width; c++){
		for(r = 0; r < height; r++){
			pixel[c][r].r = 255 - pixel[c][r].r;
			pixel[c][r].g = 255 - pixel[c][r].g;
			pixel[c][r].b = 255 - pixel[c][r].b;
		}
	}


	printf("P6\n %i %i 255\n", width, height);

	for(c = 0; c < width; c++){
		for(r = 0; r < height; r++){
			printf("%c%c%c", pixel[c][r].g, pixel[c][r].r, pixel[c][r].b);
		}
	}

	return 0;
}

//Include the stdio, stdlib, stdbool, and ctype libraires
//I will use ctype.h for the isdigit function when searching for width, height
//and maxVal
//Include ppmUtil.h for access to the pixel and header structures
#include <stdio.h>
#include <stdlib.h>
#include "ppmUtil.h"
#include <stdbool.h>
#include <ctype.h>

////Define the function void writeHeader with a file pointer and header_t
//As the parameters. This will use header_t, which contains the header 
//information tfrom the input ppm file and write to the image file pointer
//Which is the output file
void writeHeader(FILE* image, header_t head)
{
	//Use fprintf to write the ppm type from head with a new line
	//Then write the width, height, and maxVal with a space in between
	fprintf(image, "%s\n", head.type);
	fprintf(image, "%u %u %u\n", head.width, head.height, head.maxVal);
}

//Define the void functions writePixels with a file pointer, pixel_t*,
//and header_t as the parameters. This will use pixel_t and header_t
//to write the pixels in the image file pointer using fwrite
void writePixels(FILE* image,pixel_t* p, header_t head)
{
	//Use fwrite to get the data from p and write it to the image
	//use the size of the pixel_t struct and width times height
	//from the head to represent the number of items to be written
	fwrite(p, sizeof(pixel_t), head.width * head.height, image);
}

//Define the readPixels functions that return pixel_t* data type
//The file pointer image is the input ppm file and the header_t head
//contains the header information from the input ppm file
//This function will call allocatePixMemory to allocate memory for 
//the ppm image, then use fread to read the pixels from the input ppm file
pixel_t* readPixels(FILE* image, header_t head)
{
	//Create an instance of struct pixel_t* pixels and set it equal to
	//the allocatePixMemory function, which will return pixel_t* data type
	//with the allocated memory using the header information
	//Then use fread to read from the image and store it in pixels
	//Use sizeof pixel_t struct and use width times height
	//to get the number of items that need to be read from the image ppm file
	//Then, return pixels
	pixel_t* pixels = allocatePixMemory(head);
	fread(pixels, sizeof(pixel_t), head.width * head.height, image);
	return pixels;
}

//define the function read that will return pixel_t* with parameters of
//a file pointer in and header_t* head
//The file pointer is the input ppm impage and the head is the struct head
//That will read the input ppm file
//This function will call two functions readHeader to get the header info
//and readPixels to read the pixels after reading the header info
pixel_t* read(FILE* in, header_t* head)
{
	//Call readHeader with parameters in and head to get the header info
	//Then return readPixels with in and head* as the parameters
	//readPixels will return pixel_t* after reading and 
	//defining the pixel struct
	readHeader(in, head);
	return readPixels(in, *head);
}

//Define the void function(wirte) with a file pointer, header_t, and 
//pixel_t* as the parameters. The FILE* image is the output image
//that we are going to write to using the info from header_t and pixel_t*
//This function will call writeHeader to write the header in the output
//ppm image and writePixels that will write the pixels
void write(FILE* image, header_t head, pixel_t* pix)
{
	//Call writeHeader with image and head as the parameters
	//Call writePixels with image, pix, and head as the parameters
	writeHeader(image, head);
	writePixels(image, pix, head);
}

//Define the function allocatePixMemory that will return pixel_t*
//It will have the header_t h as the parameter
//This function will use the header information to determine
//the size of the ppm image and dynamically allocate the memory using malloc
//then, return the pixel_t* with the right memory
pixel_t* allocatePixMemory(header_t h)
{
	//return (pixel_t*)malloc(h.width * h.height * sizeof(pixel_t))
	//which will dynamically allocate the memory to get all the pixels
	return (pixel_t*)malloc(h.width * h.height * sizeof(pixel_t));
}

//Define the void function ckComment with file pointer in as the parameter
//This function will use the file pointer in and ignore the 
//comments and white spaces until it reaches a digit
void ckComment(FILE* in)
{
	//Create a bool hasComment and set it to false
	//Create a char c 
	//set c equal to fgetc(in)
	bool hasComment = false;
	char c;
	c = fgetc(in);

	//Make a while loop that while c is a newline or a space,
	//call fget(in) and set c equal to it until it reaches a character
	//Make an if statement that if c is a hashtag or comment
	//set hasComment to true
	//else, means that it is a value so ungetc
	while (c == '\n' || c == ' ') {
		c = fgetc(in);
	}	
	if (c == '#') {
		hasComment = true;
	}
	else {
		ungetc(c,in);
	}

	//Make a while loop that while hasComment is true
	//Ignore all the character until it reaches a digit using the isdigit function
	//when it reaches a digit unget that digit and set hasComment to false
	while (hasComment) {
		while(!isdigit(c = fgetc(in))) {
		}
		ungetc(c,in);
		hasComment = false;
	}
}

//Define the function readHeader with the file pointer in and header_t *hdr
//as the parameters. the file pointer in is the input ppm file with comments
//the header_t* is the instance of struct header that will store the values
//of the input ppm file
//This function will also call ckComment that will ignore comments and 
//read the only necessary values
void readHeader(FILE* in, header_t *hdr)
{	
	//Use fscanf f to read in the ppm type
	//I know the comments only starts after the type so I don't need to check
	//for comments first
	//Then check for comments until it reaches to the first value
	//Use fscanf again to read in the width values and store it in the hdr
	//Check comments until it reaches the second value
	//Use fscanf to read in the height and store it in hdr
	//Check comments again until it reachs the third value
	//Use fscanf to read in maxVal and store it in hdr
	//Then check for comments again
	fscanf(in, "%2s", hdr->type);
	ckComment(in);
	fscanf(in, "%u", &hdr->width);
	ckComment(in);
	fscanf(in, "%u", &hdr->height);
	ckComment(in);
	fscanf(in, "%u", &hdr->maxVal);
	ckComment(in);
}

//Define the void function freeMemory with pixel_t* pix as the parameter
//This function will free the pixel_t*
void freeMemory(pixel_t* pix)
{	
	//free the pix pointer
	free(pix); 
}

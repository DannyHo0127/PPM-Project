/**************************
 *Danny Ho *
 *CPSC2310 Fall 2023 *
 *dkho: *
 *Instructor: Dr. Yvon Feaster *
 *************************/

//Include the stdio and stdlib libraries
//Include the ppmUtil header files
#include <stdio.h>
#include <stdlib.h>
#include "ppmUtil.h"

//Create an in main with command line arguments
int main(int argc, char** argv)
{	
	//Create two file pointers input and output
	//open the input file pointer in rb since P6 files are in binary
	//Let the input file Open the P6 file with comments
	//Let the output file open the argv[2] to open a new ppm image
	//Open it in wb to write ppm image with no comments
	FILE* input = fopen(argv[1], "rb");
	FILE* output = fopen(argv[2], "wb");

	//Create the data type header_t called header
	///Create the data type pixel_t pointer called pixels
	header_t header;
	pixel_t* pixels;

	//Set pixels equal to read(input, &header), 
	//Which will get the header data from the input file 
	//and define all the pixels
	//Call the functions write(output, header, pixels) to write the ppm image 
	//into the output file
	pixels = read(input, &header);
	write(output, header, pixels);

	//Then, free the memory of pixels
	//Then close the input and output file
	freeMemory(pixels);
	fclose(input);
	fclose(output);

}


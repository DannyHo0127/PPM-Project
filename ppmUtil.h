/**************************
 *Danny Ho *
 *CPSC2310 Fall 2023 *
 *dkho: *
 *Instructor: Dr. Yvon Feaster *
 *************************/

//Create header guards for ppmUtil file
#ifndef PPMUTIL_H
#define PPMUTIL_H

//Create the typedef struct Pixel
//Create unsigned char of r, g, b
//Call the new data type of struct pixel pixel_t
typedef struct Pixel
{
	unsigned char r, g, b;
}pixel_t;

//Create the typedef struct Header
//It will have  char Type[3] and unsigned int of width, height, and maxVal
//Call the new data type of struct Header header_t
typedef struct Header
{
	char type[3];
	unsigned int width;
	unsigned int height;
	unsigned int maxVal;
}header_t;

//Create the void readHeader with parameters File pointer and header_t*
//The file pointer is the input file that will be read 
//to define the header_t*, which is the instance of the header struct
//It will use fscanf and the function chComment
//This function will define the variables of header_t* 
//and ignore all the comments when reading
void readHeader(FILE*, header_t*);

//Create the readPixels functions with parameters of file pointer and header_t
//The file pointer is the input file and the header_t is the instances of the
//header struct defined from readheader function
//Create an instance of pixels_t and
//call the allocatePixMemory function to allocate memory for the pixels
//Then it will use fread to read the pixels from the input file
//After reading, it will return the pixel_t* that is defined
pixel_t* readPixels(FILE*, header_t);

//Create the void functions writeHeader with a file pointer and header_t
//As parameters. the file pointer is the output ppm file and the header_t
//contains the header info from the input ppm file
//This function will use the info from header_t and fprintf to write the header
//In the output ppm file
void writeHeader(FILE*, header_t);

//Create the void function writePixels with a file pointer, pixel_t*, and
//header_t as the parameters. the filepointer is the output ppm file
//pixel_t* contains the pixel info from the input ppm file
//header_t contains the header info from the input ppm file
//This function will use fwrite and the info from pixel_t* and header_t
//to output the pixels r, g ,b to the output ppm file
void writePixels(FILE*, pixel_t*, header_t);

//Create the void readHeader with parameters File pointer and header_t*
//The file pointer is the input file that will be read
//To define the struct header and pixels
//The header_t* is the instance of the struct header
//We will use the header from the input file to define the header_t*
//This function will call readHeader and readPixels
//This will return a pointer of pixel_t that is defined from readPixels 
pixel_t* read(FILE*, header_t*);

//Create the write functions with parameters file pointer, header_t, pixel_t*
//the file pointer is the output ppm file that we will create
//The header_t is the instand of struct header that contains the header info
//The pixel_t* is the instance of struct pixel that contains the pixel info
//It will call functions writeHeader and writePixels
//This will create the output ppm image without comments
void write(FILE*, header_t, pixel_t*);

//Define the allocatePixMemory functions with parameters header_t
//Header_t is the instance of struct header that contains the header info
//Create an instand of pixel_t* and dynamically allocate it using the header
//infomation and return the pixel_t* with enough data space
pixel_t* allocatePixMemory(header_t);

//Create the void function freeMemory that will free pixel_t*
//Which is the the instance of the struct Pixels defined from the input file
void freeMemory(pixel_t*);

//Create the void function ckComment that will take in a file pointer
//which is the ppm image full of comments
//This will look at the input file and ignore all the comments using
//a while loop until it reaches to the necessary values needed
void ckComment(FILE*);

#endif

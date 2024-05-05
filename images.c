//Authors: Saurabh Chawla & Lukas Farias
//Date: 05/07/2024
//Objective: "Erinstagram" - Create a program that allows the user to load a new image in which they are able to edit by cropping, dimming, birghtening, or rotating. 

#include <stdio.h>
#include <stdbool.h>

#define MAX_ROWS 500
#define MAX_COLS 500
#define FILE_NAME_MAX 100

void mainMenu();
int loadImage(FILE* fp, char fname[], int img[][MAX_COLS], int* rowsPtr, int* colsPtr);
void getCols(FILE* fp, int* colsPtr);
void displayImage(int img[][MAX_COLS], int rows, int cols);
void editImage(FILE* fp, int img[][MAX_COLS], int rows, int cols);
void saveImage(FILE* fp, int img[][MAX_COLS], int rows, int cols);
void dimImage(int img[][MAX_COLS], int newImage[][MAX_COLS], int rows, int cols);
void brightenImage(int img[][MAX_COLS], int newImage[][MAX_COLS], int rows, int cols);
/*void cropimage(int img[][MAX_COLS], int newImage[][MAX_COLS], int rows, int cols);
void rotateImage_90(int img[][MAX_COLS], int newImage[][MAX_COLS], int rows, int cols);*/


int main(){
 	FILE *fpIN, *fpOUT;
 	int image[MAX_ROWS][MAX_COLS], rows = 0, cols = 0, choice;
 	char fname[FILE_NAME_MAX];
	int mmChoice;
	
	do{
		mainMenu();
		scanf ("%d", &mmChoice);
		
		switch (mmChoice){
			case 1: 
				loadImage(fpIN, fname, image, &rows, &cols);
				break;
			case 2: 
				displayImage(image, rows, cols);
				break;
			case 3:	
				editImage(fpOUT, image, rows, cols);
				break;
			case 0:
				printf ("\nGoodbye!\n");
				printf ("\n");
				return 1;
				break;
			default: 
				printf ("\nINVALID CHOICE!!! Please try again :)\n");
			}
		}while (mmChoice != 4);
		
	//loadImage(fpIN, fname, image, &rows, &cols);
 	//printf("rows = %d, cols = %d\n", rows, cols);
	//displayImage(image, rows, cols);
  return 0;
}

//---------------------------------------------------------------------

void mainMenu(){
	printf ("***ERINSTAGRAM***\n");
	printf ("1: Load Image\n");
	printf ("2: Display Image\n");
	printf ("3: Edit Image\n");
	printf ("0: EXIT\n");
	printf ("\nChoose from one of the options above: ");
}

//--------------------------------------------------------------------

int loadImage(FILE *fp, char fname[], int img[][MAX_COLS], int* rowsPtr, int* colsPtr){
	int rows = 0, cols = 0;
	printf("What is the name of the image file: ");
	scanf ("%s",fname);

	fp = fopen(fname, "r");
	if (fp == NULL) {
  		printf("\nThis File does not exist\n");
  		printf("\n");
		return 0;
	}else {
		printf("\nfile opened successfully!\n");
		printf("\n");
	}
	getCols(fp, colsPtr);

	char temp = 'a';
  	int row = 0, col = 0;
  	bool exitbool = false;

  	rewind(fp);

  	while (!exitbool && row < MAX_ROWS) {
    		col = 0;
    		while (fscanf(fp, "%c", &temp) == 1 && col < *colsPtr) {
      			if (temp >= '0' && temp <= '9') {
        		img[row][col] = temp - '0';
      		}
      		col++;
    	}
    	if (col == 0) {
      		exitbool = true;
   	 } else {
      		row++;
    		}
  	}
  	*rowsPtr = row;
  	fclose(fp);
  	return 1;
}

//-----------------------------------------------------------------

void getCols(FILE *fp, int* colsPtr){
  char temp = 'a';
  while (temp != '\n') {
    fscanf(fp, "%c", &temp);
    if (temp >= '0' && temp <= '4') {
      (*colsPtr)++;
    }
  }
}

//-----------------------------------------------------------------

void displayImage(int img[][MAX_COLS], int rows, int cols){
  printf("\nDisplaying image!\n");

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      switch (img[i][j]) {
      case 0:
        printf(" ");
        break;
      case 1:
        printf(".");
        break;
      case 2:
        printf("o");
        break;
      case 3:
        printf("O");
        break;
      case 4:
        printf("0");
        break;
      }
    }
    printf("\n");
  } 
}

//-----------------------------------------------------------------------

void editImage(FILE* fp, int img[][MAX_COLS], int rows, int cols){
	FILE* fpOUT;
	int editMenu, rowsNew, colsNew, newImage[MAX_ROWS][MAX_COLS];
	int image[MAX_ROWS][MAX_COLS];
	//bool editExitBool = 0;
	printf ("***IMAGE EDITOR***\n");
	printf ("1: Crop Image\n");
	printf ("2: Dim Image\n");
	printf ("3: Brighten Image\n");
	printf ("4: Rotate 90 degrees\n");
	printf ("0: Return to Main Menu\n");
	printf ("\nChoose from one of the options above: ");
  	scanf("%d", &editMenu);

	switch (editMenu){
		case 1: 
			//cropImage(img, newImage, rows, cols, &rowsNew, &colsNew);
			//displayImage(newImage, rowsNew, colsNew);
			saveImage(fpOUT, img, rows, cols);
			break;
		case 2: 
			dimImage(image, newImage, rows, cols);
			displayImage(newImage, rowsNew, colsNew);
			saveImage(fpOUT, img, rows, cols);
			break;
		case 3: 
			brightenImage(image, newImage, rows, cols);
			displayImage(newImage, rowsNew, colsNew);
			saveImage(fpOUT, img, rows, cols);
			break;
		case 4:
			saveImage(fpOUT, img, rows, cols);
		case 0: 
			printf("/n");
			break;
	}
}

//------------------------------------------------------------------------------
//THIS IS BROKEN lol ~ it might be an issue w/ save also not diplaying (logic should be good tho) 
void dimImage(int img[][MAX_COLS], int newImage[][MAX_COLS], int rows, int cols){
	FILE* fpIN;
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			if (img[i][j] > 1){
				newImage[i][j] = img[i][j] - 1;
			}else {
				newImage[i][j] = img[i][j];
			}
		}
	}
}

//------------------------------------------------------------------------------
//THIS IS ALSO BROKEN lol:
void brightenImage(int img[][MAX_COLS], int newImage[][MAX_COLS], int rows, int cols){
	FILE* fpIN;
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			if (img[i][j] < 4){
				newImage[i][j] = img[i][j] + 1;
			}else {
				newImage[i][j] = img[i][j];
			}
		}
	}
}

//------------------------------------------------------------------------------

void saveImage(FILE* fp, int img[][MAX_COLS], int rows, int cols){
	char yn; 
	char newImageFileName[FILE_NAME_MAX];
	printf("\nWould you like to save this image? (y/n):");
	scanf(" %c", &yn);
	
	if (yn == 'y' || yn == 'Y'){
		printf("What do you want to name the image file? (include the extension): ");
		scanf(" %s", newImageFileName);
		FILE* fpOUT = fopen(newImageFileName, "w");
		if (fpOUT == NULL){
			printf("\nError opening file.\n");
			return;
			}
		
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				fprintf(fpOUT, "%d", img[i][j]);
				}
		  fprintf(fpOUT, "\n");
		}
		fclose(fpOUT);
		printf("\nImage Successfully saved!\n");
		printf("\n");
		return;
		}
	else if (yn == 'n' || yn == 'N'){
		printf("\n");
		return;
	}else {
	printf("Invalid Input.\n");
	}
}













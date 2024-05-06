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
void displayImage(int img[][MAX_COLS], int rows, int cols, int tag);
void editImage(FILE* fp, int img[][MAX_COLS], int rows, int cols);
int saveImage(FILE* fp, int img[][MAX_COLS], int rows, int cols);
void dimImage(int img[][MAX_COLS], int newImage[][MAX_COLS], int rows, int cols);
void brightenImage(int img[][MAX_COLS], int newImage[][MAX_COLS], int rows, int cols);
void cropImage(int img[][MAX_COLS], int newImage[][MAX_COLS], int rows, int cols, int* newRowsPtr, int* newColsPtr);
void rotateImage_90(int img[][MAX_COLS], int newImage[][MAX_COLS], int rows, int cols);


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
        displayImage(image, rows, cols, 0);
        break;
      case 3:	
        editImage(fpOUT, image, rows, cols);
        break;
      case 0:
        printf ("\nGoodbye!\n");
        printf ("\n");
        return 0;
        break;
      default: 
        printf ("\nINVALID CHOICE!!! Please try again :)\n");
      }
    }while (mmChoice != 0);

  return 0;
}

//--------------------------------------------------------------------

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
            if (temp >= '0' && temp <= '4') {
            img[row][col] = temp - '0';
          }
          col++;
      }
      if (col == 0) {
          exitbool = true;
     }else {
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

void displayImage(int img[][MAX_COLS], int rows, int cols, int tag){
  printf("\nDisplaying image!\n");
  int midRow = rows / 2, midCol = cols / 2, extraDigit = 0;
  if (midCol > 9){extraDigit++;}
  if (midCol > 99){extraDigit++;}
  
  if (tag == 1){
    printf("    ");
      for (int j = 0; j < cols; j++) {
        if (j == 0 || j == midCol || j == cols-1){
          printf("%d", j+1);
        }else if (j < cols - 1 - extraDigit){
          printf("_");
        }
      }
      printf("\n");
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      
      if (tag == 1 && j == 0){
        if(i == 0 || i == midRow || i == rows-1){
          printf("%3d|", i+1);
        }else {printf("   |");}
      }
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
  if (tag == 1){
    printf("    ");
      for (int j = 0; j < cols; j++) {
        if (j == 0 || j == midCol || j == cols-1){
          printf("%d", j+1);
        }else if (j < cols - 1 - extraDigit){
          printf("_");
        }
      }
      printf("\n");
  }
}

//--------------------------------------------------------------------

void editImage(FILE* fp, int img[][MAX_COLS], int rows, int cols){
  int editMenu, newRows, newCols, newImage[MAX_ROWS][MAX_COLS];
  
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
      cropImage(img, newImage, rows, cols, &newRows, &newCols);
      displayImage(newImage, newRows, newCols, 0);
      saveImage(fp, newImage, newRows, newCols);
      break;
    case 2: 
      dimImage(img, newImage, rows, cols);
      displayImage(newImage, rows, cols, 0);
      saveImage(fp, newImage, rows, cols);
      break;
    case 3: 
      brightenImage(img, newImage, rows, cols);
      displayImage(newImage, rows, cols, 0);
      saveImage(fp, newImage, rows, cols);
      break;
    case 4:
      rotateImage_90(img, newImage, rows, cols);
      displayImage(newImage, rows, cols, 0);
      saveImage(fp, newImage, rows, cols);
      break;
    case 0: 
      printf("\n");
      break;
  }
}

//--------------------------------------------------------------------
void dimImage(int img[][MAX_COLS], int newImage[][MAX_COLS], int rows, int cols){
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      if (img[i][j] > 0){
        newImage[i][j] = img[i][j] - 1;
      }else {
        newImage[i][j] = img[i][j];
      }
    }
  }
}

//--------------------------------------------------------------------
void brightenImage(int img[][MAX_COLS], int newImage[][MAX_COLS], int rows, int cols){
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

//--------------------------------------------------------------------

void cropImage(int img[][MAX_COLS], int newImage[][MAX_COLS], int rows, int cols, int* newRowsPtr, int* newColsPtr){
  int cropCoords[4];
  bool validCoords = 0;
  displayImage(img, rows, cols, 1);
  while (validCoords == 0){
    printf("\nPlease enter the desired top and bottom rows of your cropped image.\n");
    printf("Top: ");
    scanf("%d", &cropCoords[0]);
    printf("Bottom: ");
    scanf("%d", &cropCoords[1]);
    if(cropCoords[0] >= 0 && cropCoords[0] <= cropCoords[1] && cropCoords[1] <= rows){
      validCoords = 1;
    }else {printf("Invalid coordinates, please try again.\n");}
  }
  validCoords = 0;
  while (validCoords == 0){    
    printf("\nPlease enter the desired left and right columns of your cropped image.\n");
    printf("Left: ");
    scanf("%d", &cropCoords[2]);
    printf("Right: ");
    scanf("%d", &cropCoords[3]);
    if(cropCoords[2] > 0 && cropCoords[2] <= cropCoords[3] && cropCoords[3] <= cols){
      validCoords = 1;
    }else {printf("Invalid coordinates, please try again.\n");}
  }
  *newRowsPtr = cropCoords[1] - cropCoords[0] + 1;
  *newColsPtr = cropCoords[3] - cropCoords[2] + 1;
  printf("newRows = %d, newCols = %d", *newRowsPtr, *newColsPtr);
  
  for (int i = 0; i < *newRowsPtr; i++){
    for (int j = 0; j < *newColsPtr; j++){
      newImage[i][j] = img[cropCoords[0] + i - 1][cropCoords[2] + j - 1];
    }
  }
}

//--------------------------------------------------------------------

int saveImage(FILE* fp, int img[][MAX_COLS], int rows, int cols){
  char yn; 
  char newImageFileName[FILE_NAME_MAX];
  printf("\nWould you like to save this image? (y/n):");
  scanf(" %c", &yn);

  switch (yn){
    case 'y': 
    case 'Y': printf("What do you want to name the image file? (include the extension): ");
      scanf(" %s", newImageFileName);
      FILE* fp = fopen(newImageFileName, "w");
      if (fp == NULL){
        printf("\nError opening file.\n");
        return 0;
      }

      for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
          fprintf(fp, "%d", img[i][j]);
          }
        fprintf(fp, "\n");
      }
      fclose(fp);
      printf("\nImage Successfully saved!\n");
      printf("\n");
      return 1;
    case 'n':
    case 'N': printf("\n");
      return 0;
    default: printf("Invalid Input.\n");
      return 0;
  }
}
void rotateImage_90(int img[][MAX_COLS], int newImage[][MAX_COLS], int rows, int cols){
	for (int i = 0; i < rows; i++){
	    for (int j = 0; j < cols; j++){
	      if (img[i][j] > 0){
		newImage[i][j] = img[j][i];
		}
	}
}
}

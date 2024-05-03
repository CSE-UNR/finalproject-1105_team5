//Authors: Saurabh Chawla & Lukas Farias
//Date: 05/07/2024
//Objective: "Erinstagram" - Create a program that allows the user to load a new image in which they are able to edit by cropping, dimming, birghtening, or rotating. 

#include <stdio.h>
#include <stdbool.h>

#define MAX_ROWS 500
#define MAX_COLS 500
#define FILE_NAME_MAX 100

int loadImage(FILE* fp, char fname[], int img[][MAX_COLS], int* rowsPtr, int* colsPtr);
void getCols(FILE* fp, int* colsPtr);
void displayImage(int img[][MAX_COLS], int rows, int cols);
/*void editImage(FILE* fp, int img[][MAX_COLS], int rows, int cols);
void cropimage(int img[][MAX_COLS], int newImage[][MAX_COLS], int rows, int cols);
void dimImage(int img[][MAX_COLS], int newImage[][MAX_COLS], int rows, int cols);
void brightenImage(int img[][MAX_COLS], int newImage[][MAX_COLS], int rows, int cols);
void rotateImage_90(int img[][MAX_COLS], int newImage[][MAX_COLS], int rows, int cols);*/


int main(){
  FILE *fpIN, *fpOUT;
  int image[MAX_ROWS][MAX_COLS], rows = 0, cols = 0, choice;
  char fname[FILE_NAME_MAX];

  loadImage(fpIN, fname, image, &rows, &cols);
  printf("rows = %d, cols = %d\n", rows, cols);
  displayImage(image, rows, cols);
  return 0;
}



int loadImage(FILE *fp, char fname[], int img[][MAX_COLS], int* rowsPtr, int* colsPtr){

  printf("What is the name of the image file: ");
  fgets(fname, FILE_NAME_MAX, stdin);
  for (int i = 1; fname[i] != '\0'; i++) {
    if (fname[i] == '\n') {
      fname[i] = '\0';
    }
  }

  fp = fopen(fname, "r");
  if (fp == NULL) {
    printf("no such file.\n");
    return 0;
  } else {
    printf("file opened successfully!\n");
  }
  getCols(fp, colsPtr);

  char temp = 'a';
  int row = 0, col = 0;
  bool exitbool = 0;

  rewind(fp);

  while (exitbool != 1) {
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
  return 1;
}

void getCols(FILE *fp, int* colsPtr){
  char temp = 'a';
  while (temp != '\n') {
    fscanf(fp, "%c", &temp);
    if (temp >= '0' && temp <= '4') {
      (*colsPtr)++;
    }
  }
}

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

/*void editImage(FILE* fp, int img[][MAX_COLS], int rows, int cols){
  int editMenuChoice, rowsNew, colsNew, newImage[MAX_ROWS][MAX_COLS];
  char yn, newImageFileName[FILE_NAME_MAX];
  bool editExitBool = 0;

  printf("Enter your choice!\n1. crop\n2. brighten\n3. dim\n0. go back to main menu\n");
//I haven't looked at the example exec. yet so we can put better menu prompts in later
  scanf("%d", &editMenuChoice);

  switch (editMenuChoice){
    case 1: cropImage(img, newImage, rows, cols, &rowsNew, &colsNew);
      break;
    case 2: brightenImage(img, newImage, rows, cols);
      break;
    case 3: dimImage(img, newImage, rows, cols);
      break;
    case 0: editExitBool = 1;
      break;
  }    
  if (editExitBool == 0){
    printf("\nHere is your edited image:\n\n");
    displayImage(newImage, rowsNew, colsNew);
    printf("\nWould you like to save this image to a file? (y/n)\n");
    scanf(" %c", yn);
    switch (yn){
      case 'Y':
      case 'y': //this is where we'd save the image to file :) 
      case 'n':
      case 'N':
      default: ;
    }
  }
}*/


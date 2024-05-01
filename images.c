//Authors: Saurabh Chawla & Lukas Farias
//Date: 05/07/2024
//Objective: "Erinstagram" - Create a program that allows the user to load a new image in which they are able to edit by cropping, dimming, birghtening, or rotating. 

#include <stdio.h>
#include <stdbool.h>

#define MAX_ROWS 500
#define MAX_COLS 500

void loadImage(FILE* fpLOAD, int currentImage[][MAX_COLS], int* height, int* width);
void displayImage(int currentImage[][MAX_COLS], int height, int width);
void editImage(FILE* fpWRITE, int currentImage[][MAX_COLS], int height, int width);
void cropimage(int image[][MAX_COLS], int newImage[][MAX_COLS], int height, int width);
void dimImage(int image[][MAX_COLS], int newImage[][MAX_COLS], int height, int width);
void brightenImage(int image[][MAX_COLS], int newImage[][MAX_COLS], int height, int width);
void rotateImage_90(int image[][MAX_COLS], int newImage[][MAX_COLS], int height, int width);

int main(){
  FILE *fpIN, *fpOUT;
  int currentImage[MAX_ROWS][MAX_COLS], height, width, choice;

  
  

  return 0;
}

void editImage(FILE* fpWRITE, int currentImage[][MAX_COLS], int heightCurrent, int widthCurrent){
  int editMenuChoice, heightNew, widthNew, newImage[MAX_ROWS][MAX_COLS];
  char yn, char newImageFileName[100];
  bool editExitBool = 0;

  printf("Enter your choice!\n1. crop\n2. brighten\n3. dim\n0. go back to main menu\n");
//I haven't looked at the example exec. yet so we can put better menu prompts in later
  scanf("%d", &editMenuChocie);

  switch (editMenuChoice){
    case 1: cropImage(currentImage, newImage, heightCurrent, widthCurrent, &heightNew, &widthNew);
      break;
    case 2: brightenImage(currentImage, newImage, heightCurrent, widthCurrent);
      break;
    case 3: dimImage(currentImage, newImage, heightCurrent, widthCurrent);
      break;
    case 0: editExitBool = 1;
      break;
  }    
  if (editExitBool == 0){
    printf("\nHere is your edited image:\n\n");
    displayImage(newImage, heightNew, widthNew);
    printf("\nWould you like to save this image to a file? (y/n)\n");
    scanf(" %c", yn);
    switch (yn){
      case 'Y':
      case 'y': //this is where we'd save the image to file :) 
      case 'n':
      case 'N':
      default:
  }
}


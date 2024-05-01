//Authors: Saurabh Chawla & Lukas Farias
//Date: 05/07/2024
//Objective: "Erinstagram" - Create a program that allows the user to load a new image in which they are able to edit by cropping, dimming, birghtening, or rotating. 

#include <stdio.h>

#define MAX_ROWS 500
#define MAX_COLS 500

void loadImage(FILE* fpLOAD, int currentImage[][MAX_COLS], int* height, int* width);
void displayImage(int currentImage[][MAX_COLS], int height, int width);
void editImage(FILE* fpWRITE, int currentImage[][MAX_COLS], int height, int width);
void cropimage(int currentImage[][MAX_COLS], int newImage[][MAX_COLS], int height, int width);
void dimImage(int currentImage[][MAX_COLS], int newImage[][MAX_COLS], int height, int width);
void brightenImage(int currentImage[][MAX_COLS], int newImage[][MAX_COLS], int height, int width);
void rotateImage_90(int currentImage[][MAX_COLS], int newImage[][MAX_COLS], int height, int width);

int main(){
  FILE *fpIN, *fpOUT;
  int currentImage[MAX_ROWS][MAX_COLS], height, width, choice;

  
  

  
}

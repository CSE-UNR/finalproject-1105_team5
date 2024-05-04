//brighten and dim
//Lukas Farias

#include <stdio.h>
#define MAX_ROWS 100
#define MAX_COLS 100


void brighten_dimImage(int img[][MAX_COLS], int newImage[][MAX_COLS], int rows, int cols);
void displayImage(int img[][MAX_COLS], int rows, int cols);
void loadTestImg(int img[][MAX_COLS], int* rowsPtr, int* colsPtr);


int main(){
	int image[MAX_ROWS][MAX_COLS];
	int rows = 0, cols = 0;
	int newImage[MAX_ROWS][MAX_COLS];

  loadTestImg(image, &rows, &cols);
  displayImage(image, rows, cols);
  
  brighten_dimImage(image, newImage, rows, cols);
  displayImage(newImage, rows, cols);

  return 0;
}

void brighten_dimImage(int img[][MAX_COLS], int newImage[][MAX_COLS], int rows, int cols){
  int x = 0;
  printf("brighten or dim by how much? ");
  scanf("%d", &x);

  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      
      newImage[i][j] = img[i][j] + x;
      if (newImage[i][j] < 0){
        newImage[i][j] = 0;
      }else if (newImage[i][j] > 4){
            newImage[i][j] = 4;
            }
        }	
    }
}
void loadTestImg(int img[][MAX_COLS], int* rowsPtr, int* colsPtr){
  *rowsPtr = 10;
  *colsPtr = 10;
  for(int i = 0; i < *rowsPtr; i++){
    for(int j = 0; j < *colsPtr; j++){
      if (j<5){
        if (i<2 || i>7){
          img[i][j] = 4;
        }else img[i][j]= 2;
      }else{ 
        if (i<5){
          img[i][j] = 3;
        }else img[i][j] = 1;
      }
      if (i>3 && i<6 && j>2 && j<7){
        img[i][j] = 0;
      }
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


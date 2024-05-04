//brighten and dim
//Lukas Farias

#include <stdio.h>
#define MAX_ROWS 100
#define MAX_COLS 100


brightenImage(char img[][MAX_COLS], int rows, int cols);

int main(){

int image[MAX_ROWS][MAX_COLS];
int rows = 10, cols = 10;

for(int i = 0; i < rows; i++){
	    for(int j = 0; j < cols; j++){
    		switch (j<5){
	   		 case 1: 
            	if (i<2 || i>8){
          			image[i][j] = 2;
            	}else image[i][j]= 4;
             	break;
             case 0:
    			if (i<5){
            		image[i][j] = 3
                }else image[i][[j] = 1;
                break:
            }
        } 
}




return 0;
}
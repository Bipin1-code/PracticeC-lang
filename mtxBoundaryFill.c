//Write a program for to fill the boundary of a matrix with 1 and interior with 0.

#include <stdio.h>
#include <stdlib.h>

void display2Dmtx(int **arr, int r, int c){
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

void fillBOfmtx(int **m, int r, int c){
   for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if(i == 0 || j == 0 || i == (r - 1) || j == (c - 1))
        m[i][j] = 1;
      else
        m[i][j] = 0; 
    }
  }
}

int main(){
  int rows, cols;
  printf("How many rows and columns you want in your matrix?\n");
  fflush(stdout);
  scanf("%d %d", &rows, &cols);
  
  int **mtx = (int **)malloc(rows * sizeof(int *));
  if(mtx == NULL){
    printf("Mry allocation failed.\n");
    free(mtx);
    return 1;
  }
  for(int i  = 0; i < rows; i++){
    mtx[i] = (int *)malloc( cols * sizeof(int));
    if(mtx[i] == NULL){
       for(int k = 0; k < i; k++){
          free(mtx[k]);
          mtx[k] = NULL;
       }
       free(mtx[i]);
       return 1;
    }
  }

  fillBOfmtx(mtx, rows, cols);
  display2Dmtx(mtx, rows, cols);
  
  for(int k = 0; k < rows; k++){
    free(mtx[k]);
  }
  free(mtx);
  return 0;
}


#include <stdio.h>
#include <stdlib.h>

void transpose2DArray(int *arr[], int rw, int cl){
  printf("Here is transpose of the given 2D-Array matrix. \n");
  for( int i = 0; i < cl; i++){
    for(int j = 0; j < rw; j++){
      printf("%d ", arr[j][i]);
    }
    printf("\n");
  }
}

void display2DArray(int *arr[], int r, int c){
  printf("Here is your matrix as like given input:\n");
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

void create2DArray(int *arr[], int r, int c){
  printf("Ready yourself for to fill the matrix.\n");
  fflush(stdout);
  for(int i = 0; i < r; i++){
    arr[i] = (int *)malloc(c * sizeof(int));
    if(arr[i] == NULL){
      printf("Memory allocation is failed!\n");
      for(int k = 0; k < i; k++) {
          free(arr[k]);
          arr[k] = NULL;
       }
      return;
    }
    printf("Enter the elements of %d row: \n", i);
    fflush(stdout);
    for(int j = 0; j < c; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  display2DArray(arr, r, c);
}

int main(){
  int row, col;
  printf("Enter the number of rows and columns you want:\n");
  fflush(stdout);
  scanf("%d %d", &row, &col);
  int **matrix = (int **)malloc(row * sizeof(int *));
  if(matrix == NULL){
     printf("Memory allocation failed!\n");
     free(matrix);
     matrix = NULL;
     return 1;
  }
  create2DArray(matrix, row, col);
  if(matrix[0] == NULL) { 
     free(matrix);
     return 1;
  }
  transpose2DArray(matrix, row, col);
  
  for(int i = 0; i < row; i++){
    free(matrix[i]);
    matrix[i] = NULL;
  }
  free(matrix);
  matrix = NULL;
  return 0;
}

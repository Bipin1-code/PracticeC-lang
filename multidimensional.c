

#include <stdio.h>
#include <stdlib.h>

void display2DArray(int *arr1[], int rw, int cl){
  for(int i = 0; i < rw; i++){
    for(int j = 0; j < cl; j++){
      printf("%d ", arr1[i][j]);
    }
    printf("\n");
  }
}

void createArray(int *arr[], int r , int c){
  printf("It's time to fill the elements of the matrix:\n");
  fflush(stdout);
  for(int i = 0; i < r; i++){
    printf("Enter the elememts for %d row:\n", i);
    fflush(stdout);
    arr[i] = (int *)malloc(c * sizeof(int));
    if(arr[i] == NULL){
      printf("Memory allocation failed!\n");
      free(arr);
      arr = NULL;
      return;
    }
    for( int j = 0; j < c; j++){
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
  
  int **matrix;
  matrix = (int **)malloc(row * sizeof(int *));
  if (matrix == NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }
  
  createArray(matrix, row, col);
  for (int i = 0; i < row; i++) {
    free(matrix[i]);
  }
  free(matrix);
  matrix = NULL;
  return 0;
}

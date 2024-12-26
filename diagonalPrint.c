

#include <stdio.h>
#include <stdlib.h>

void diagonalPrint(int *arr[], int r, int c){
  printf("Here is your only diagonals elements print:\n");
  fflush(stdout);
  int t = r - 1;
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if( i == j){
        printf("%d ", arr[i][j]);
      }
      else if( (i == 0 && j == c - 1) || (j == 0 && i == r - 1) ){
        printf("%d ", arr[i][j]);
      }
      else if( i + j == t ){
         printf("%d ", arr[i][j]);
      }
      else{
        printf("  ");
      }
    }
    printf("\n");
  }
}

void display2DMatrix( int *arr[], int rw, int cl){
  printf("Here is your 2D square matrix:\n");
  for(int i = 0; i < rw; i++){
    for(int j = 0; j < cl; j++){
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

void createSqMatrix(int *arr[], int r, int c){
  for(int i = 0; i < r; i++){
    arr[i] = (int *)malloc(c * sizeof(int));
    if(arr[i] == NULL){
      printf("Memory allocation failed!\n");
      for(int k = 0; k < i; k++){
        free(arr[k]);
        arr[k] = NULL;
      }
      return;
    }
    printf("Enter the elements of %d rows\n", i);
    fflush(stdout);
    for(int j = 0; j < c; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  display2DMatrix(arr, r, c);
}

int main(){
  int rows, cols;
  printf("Enter the number for to make square matrix:\n");
  fflush(stdout);
  scanf("%d %d", &rows, &cols);
  int **matrix =(int**)malloc(rows * sizeof(int *));
  if(matrix == NULL){
    printf("Memory is not allocated!\n");
    free(matrix);
    matrix = NULL;
    return 1;
  }
  
  createSqMatrix(matrix, rows, cols);

  //for to check array created or not
  if(matrix[0] == NULL){
    free(matrix);
    matrix = NULL;
    return 1;
  }

  diagonalPrint(matrix, rows, cols);

  for(int i = 0; i < rows; i++){
    free(matrix[i]);
    matrix[i] = NULL;
  } 
  free(matrix);
  matrix = NULL;
  return 0;
}

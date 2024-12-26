

//This program will print the matrix element in spiral form:

#include <stdio.h>
#include <stdlib.h>

void sprialElmPrtMtx(int *mtx[], int r,int c){
  printf("Here is your matrix in sprial format.\n");
  fflush(stdout);

  int top = 0, b = r - 1, left = 0, right = c - 1;
  int num = 1;
  
  while( top <= b && left <= right ){
    for(int i = left; i <= right; i++){
      mtx[top][i] = num++;
    }
    top++;

    for(int i = top; i <= b; i++){
      mtx[i][right] = num++;
    }
    right--;

    if(top <= b){
      for(int i = right; i >= left; i--){
        mtx[b][i] = num++;
      }
      b--;
    }

    if(left <= right){
      for(int i = b; i >= top; i--){
        mtx[i][left] = num++;
      }
      left++;
    }
  }
}

void display2DMtx(int *arr[], int r, int c){
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int main(){
  int rows, cols;
  printf("Enter the numbers for rows and cols:\n");
  fflush(stdout);
  scanf("%d %d", &rows, &cols);

  int **matrix = (int **)malloc(rows * sizeof(int *));
  if(matrix == NULL){
    printf("Memory is not allocated!\n");
    free(matrix);
    matrix = NULL;
    return 1;
  }
  for( int i = 0; i < rows; i++){
    matrix[i] = (int *)malloc(cols * sizeof(int));
    if(matrix[i] == NULL){
      printf("We are inside if condition.");
      fflush(stdout);
      for(int k = 0; k < i; k++){
          free(matrix[k]);
          matrix[k] = NULL;
      }
      free(matrix);
      return 1;
    }
  }
  ///all logic function should come here
  sprialElmPrtMtx(matrix, rows, cols);
  display2DMtx(matrix, rows, cols); 
  for(int k = 0; k < rows; k++){
    free(matrix[k]);
    matrix[k] = NULL;
  }
  free(matrix);
  matrix = NULL;
  
  return 0;
}


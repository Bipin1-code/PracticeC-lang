
///This programe check the given matrix is palindrome or not

#include <stdio.h>
#include <stdlib.h>

void display2DArray(int *arr[], int r, int c);

void checkMtxpalindrome(int *arr[], int r, int c){
  printf("Checking palindrome status.\n");
  fflush(stdout);
  for(int i = 0; i < r/2; i++){
    for(int j = 0; j < c; j++){
      if(arr[i][j] != arr[(r-1) - i][j]){
        printf("Matrix is not a palindrome.\n");
        return;
      }
    }
  }
  printf("Congratulation a got a Matrix which is palindrome.\n");
  display2DArray(arr, r, c);
}

void display2DArray(int *arr[], int r, int c){
  printf("Here is your matrix generated on the basis of given input.\n");
  fflush(stdout);
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

void create2DArray( int *arr[], int rw, int cl){
  printf("Ready for to fill the matrix with elements.\n");
  fflush(stdout);
  for(int i = 0; i < rw; i++){
    arr[i] = (int *)malloc(cl * sizeof(int));
    if(arr[i] == NULL){
      printf("Memory allocation failed at %d", i);
      for(int k = 0; k < i; k++){
        free(arr[i]);
        arr[i] = NULL;
        return;
      }
    }
    printf("Enter the elements for %drow:\n", i);
    fflush(stdout);
    for(int j = 0; j < cl; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  display2DArray(arr, rw, cl);
}

int main(){
  int rows, cols;
  printf("Enter the number for to make rows and columns of the matrix.\n");
  fflush(stdout);
  scanf("%d %d", &rows, &cols);

  int **matrix = (int **)malloc(rows * sizeof(int *));
  if(matrix == NULL){
    printf("Memory allocation failed!\n");
    free(matrix);
    matrix = NULL;
    return 1;
  }

  create2DArray(matrix, rows, cols);
  //this one check matrix create or not 
  if(matrix[0] == NULL){
    free(matrix);
    matrix = NULL;
  }
  //Now main problem logic comes inside of this function:
  checkMtxpalindrome(matrix, rows, cols);
  
  //this one free each individual matrix at k values  
  for(int k = 0; k < rows; k++){
    free(matrix[k]);
    matrix[k] = NULL;
  }
  
  //this one free up the matrix and set it to null which makes ensure that no dangling pointer error occure
  free(matrix);
  matrix = NULL;
  
  return 0;
}

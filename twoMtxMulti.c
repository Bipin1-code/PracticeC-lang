
//Write a program for to do multiplication of two matrix.
//Deminsion of the matrix should user defined.

#include <stdio.h>
#include <stdlib.h>


void display2DArray(int *mtx[], int rw, int cl){
  printf("Here is your matrix generated with the given inputs:\n");
  for( int i = 0; i < rw; i++){
    for( int j = 0; j < cl; j++){
      printf("%d ", mtx[i][j]);
    }
    printf("\n");
  }
}

void twoMtxMutli(int **matrix1, int rows1, int cols1, int **matrix2, int rows2, int cols2, int **rMatrix){
  for(int i = 0; i < rows1; i++){
    for(int j = 0; j < cols2; j++){
      rMatrix[i][j] = 0;
      for(int k = 0; k < cols1; k++){
        rMatrix[i][j] +=  matrix1[i][k] * matrix2[k][j];
      }
    }
  }
  display2DArray(rMatrix, rows1, cols2);
}

void create2Darray(int *arr[], int r, int c){
  printf("Here we are ready to takes elements.\n");
  fflush(stdout);
  for(int i = 0; i < r; i++){
    arr[i] = (int *)malloc(c * sizeof(int));
    if(arr[i] == NULL){
      printf("Memory allocation failed! at %d.\n", i);
      for(int k = 0; k < i; k++){
        free(arr[k]);
        arr[k] = NULL;
      }
      return;
    }
    printf("Enter the elements of %dth rows:\n", i);
    fflush(stdout);
    for(int j = 0; j < c; j++){
      scanf("%d", &arr[i][j]);
    }   
  }
  display2DArray(arr, r, c);
}

int main(){
  int rows1, cols1, rows2, cols2;
  
  printf("Enter the numbers for rows and columns of the first matrix :\n");
  fflush(stdout);
  scanf("%d %d", &rows1, &cols1);
 
  printf("Enter the numbers for rows and columns of the second matrix :\n");
  fflush(stdout);
  scanf("%d %d", &rows2, &cols2);

  if( rows1 != cols2 || cols1 != rows2){
    printf("Sry, You need to makes sure that rows1 must be equal to cols2 or vice versa.\n");
    return 1;
  }
  //Here we are allocating the memory dynamically for matrixes with the help of
  //stdlib.h aspect like: malloc ,calloc and relloc
  int **matrix1 = (int **)malloc(rows1 * sizeof(int *));
  if(matrix1 == NULL){
    printf("Memory allocation failed!\n");
    free(matrix1);
    matrix1 = NULL;
    return 1;
  }
  int **matrix2 = (int **)malloc( rows1 * sizeof(int *));
   if(matrix2 == NULL){
    printf("Memory allocation failed!\n");
    free(matrix2);
    matrix2 = NULL;
    return 1;
  }

   int **rMatrix = (int **)malloc(rows1 * sizeof(int *));
   for(int i = 0; i < rows1; i++) rMatrix[i] = (int *)malloc(cols2 * sizeof(int));
  //Now creating matrixes
   //first matrix
  create2Darray(matrix1, rows1, cols1);
  //check if array created or not 
  if(matrix1[0] == NULL){
    for(int k = 0; k < rows1; k++){
       free(matrix1[k]);
       matrix1[k] = NULL;
    }
    free(matrix1);
    matrix1 = NULL;
    return 1;
  } 
  //second matrix
  create2Darray(matrix2, rows2, cols2);
  if(matrix2[0] == NULL){
    for(int k = 0; k < rows2; k++){
       free(matrix2[k]);
       matrix2[k] = NULL;
    }
    free(matrix2);
    matrix2 = NULL;
    return 1;
  }
  
  //other function comes here
  twoMtxMutli(matrix1, rows1, cols1, matrix2, rows2, cols2, rMatrix);

  //below code when everything done and clean up
  for(int k = 0; k < rows1; k++){
    free(matrix1[k]);
    matrix1[k] = NULL;
  }
  for(int k = 0; k < rows2; k++) free(matrix2[k]);
  for(int k = 0; k < rows1; k++) free(rMatrix[k]);

  free(matrix1);
  free(matrix2);
  free(rMatrix);
  matrix1 = NULL;
  matrix2 = NULL;
  rMatrix = NULL;
  
  return 0;
}

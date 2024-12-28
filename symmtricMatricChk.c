//Write a program for to check matrix is symmteric or not.
//What is symmteric matrix?
//If a transpose of the matrix is equal to the original matrix then it is called symmteric matrix.
//For instance: A -> A'  , if A == A' : then we can say A is a symmteric matrix


#include <stdio.h>
#include <stdlib.h>

void transposeCheckSymmtric( int **arr, int r, int c ){
  printf("Checking given matrix is symmtric or not:\n");
  for(int i = 0; i < c; i++){
    for(int j = 0; j < r; j++){
      if(arr[i][j] != arr[j][i]){
        printf("This is not symmtric matrix.\n");
        return;
      }
    }
  }
   printf("This is a symmtric matrix.\n");
}

void display2Darray(int **arr, int r, int c){
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int main(){
  int n;
  printf("Enter the number for to make the square matrix:\n");
  fflush(stdout);
  scanf("%d", &n);

  int **matrix = (int **)malloc(n * sizeof(int *));
  if(matrix == NULL){
    printf("Memory allocation failed.\n");
    free(matrix);
    return 1; 
  }
  for(int i = 0; i < n; i++){
    matrix[i] = (int *)malloc(n * sizeof(int));
    if(matrix[i] == NULL){
       printf("Memory allocation failed.\n");
       for(int k = 0; k < i; k++){
         free(matrix[k]);
         matrix[k] = NULL;
       }
       free(matrix[i]);
       return 1; 
    }
    printf("Enter the elements of the %dth rows:\n", i);
    fflush(stdout);
    for(int j = 0; j < n; j++){
      scanf("%d", &matrix[i][j]);
    }
  }
  
  display2Darray(matrix, n, n);
  transposeCheckSymmtric(matrix, n, n);
  
  for(int k = 0; k < n; k++){
    free(matrix[k]);
    matrix[k] = NULL;
  }
  free(matrix);
  matrix = NULL;
  return 0;
}

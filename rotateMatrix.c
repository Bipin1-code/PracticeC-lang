
//This program is made for to rotate square matrix to (90deg)

#include <stdio.h>
#include <stdlib.h>

void display2Darray(int **arr, int r, int c){
  for( int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

void rotateMatrix(int **arr, int r, int c){
  for( int i = 0; i < r; i++){
    for(int j = c - 1; j >= 0; j--){
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }  
}

void transposeOfmtx(int **arr, int r, int c,int  **temp){
  for(int i = 0; i < c; i++){
    for(int j  = 0; j < r; j++){
       temp[i][j] = arr[j][i];
    }
  }
  rotateMatrix(temp, r, c);
  display2Darray(temp, r, c);
} 

int main(){
  int r, c;
  printf("Enter the numbers for rows and coloumns of your matrix.\n");
  fflush(stdout);
  scanf("%d %d", &r, &c);

  int **matrix = (int **)malloc(r * sizeof(int *));
  if(matrix == NULL){
    printf("Memory allocation failed.\n");
    free(matrix);
  }
  for(int i = 0; i < r; i++){
    matrix[i] = (int *)malloc (c * sizeof(int));
    if(matrix[i] == NULL){
      printf("Memoey allocation failed.\n");
      for(int k = 0; k < i; k++){
        free(matrix[k]);
      }
      free(matrix[i]);
      return 1;
    }
    printf("Enter the elements of %dth rows:\n", i);
    fflush(stdout);
    for(int j = 0; j < c; j++){
      scanf("%d", &matrix[i][j]);
    }
  }

  int **tMtx = (int **)malloc(c * r);
  for(int i = 0; i < c; i++) tMtx[i] = (int *)malloc(r * sizeof(int));
  printf("Here is your transpose of the matrix.\n");
  transposeOfmtx(matrix, r, c, tMtx);
  // rotateMatrix(matrix, r, c);
  //display2Darray(matrix, r, c);
  
  for( int k = 0; k < r; k++){
    free(matrix[k]);
  }
  for( int k = 0; k < c; k++) free(tMtx[k]);
  free(matrix);
  free(tMtx);
  return 0;
}

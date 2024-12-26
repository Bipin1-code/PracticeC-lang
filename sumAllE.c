

#include <stdio.h>
#include <stdlib.h>

void findMaxElement(int *arr[], int r, int c){
  int max = arr[0][0];
  for(int i = 0; i < r; i++){
    for(int j =0; j < c; j++){
      if(max < arr[i][j]){
        max = arr[i][j];
      }
    }
  }
  printf("%d\n", max);
}
void sumOfEachCol(int *arr[], int r, int c){
   for(int i = 0; i < c; i++){
     int sum = 0;
     for(int j = 0; j < r; j++){
       printf("%d ", arr[j][i]);
       sum += arr[j][i];
     }
     printf("Sum of all the elements of  %d column is %d.\n", i, sum);
  }
}

void sumOfEachRow(int *arr[], int r, int c){
   for(int i = 0; i < r; i++){
     int sum = 0;
     for(int j =0; j < c; j++){
       printf("%d ", arr[i][j]);
       sum += arr[i][j];
     }
     printf("Sum of all the elements of  %d row is %d.\n", i, sum);
  }
}

void display2DArray(int *arr[], int r, int c){
  int sum = 0;
  for(int i = 0; i < r; i++){
    for(int j =0; j < c; j++){
      printf("%d ", arr[i][j]);
      sum += arr[i][j];
    }
    printf("\n");
  }
  printf("Sum of all the elements present in the given 2D-Array is %d\n", sum);
}

void creatArray(int *arr[], int rw , int cl){
  printf("Its time to fill the element of 2D array.\n");
  fflush(stdout);
  for(int i = 0; i < rw; i++){
    printf("Enter the elements of %d row:\n", i);
    fflush(stdout);
    arr[i] = (int *)malloc(cl * sizeof(int));
    if(arr[i] == NULL){
      printf("Memory allocation failed!\n");
      free(arr[i]);
      arr[i] = NULL;
      return;
    }
    for(int j = 0; j < cl; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  display2DArray(arr, rw, cl);
}
int main(){
  int row, col;
  printf("Enter the number of rows and cols you want:\n");
  fflush(stdout);
  scanf("%d %d", &row, &col);
  int **matrix = (int **)malloc(row * sizeof(int *));
  if( matrix == NULL){
    printf("Memory allocation failed!\n");
    free(matrix);
    matrix = NULL;
    return 1;
  }

  creatArray(matrix, row, col);
  if(matrix[0] == NULL){
    free(matrix);
    matrix = NULL;
    return 1;
  }

  sumOfEachRow(matrix, row, col);

  sumOfEachCol(matrix, row, col);

  findMaxElement(matrix, row, col);
  
  for(int i = 0; i < row; i++){
    free(matrix[i]);
    matrix[i] = NULL;
  }
  free(matrix);
  matrix = NULL;
  return 0;
}

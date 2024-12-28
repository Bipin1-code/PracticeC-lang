//Write a program for to make a jagged array.

#include <stdio.h>
#include <stdlib.h>

void display2Darray(int **mtx, int r, int *c){
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c[i]; j++){
      printf("%d ", mtx[i][j]);
    }
    printf("\n");
  }
}

int main(){
  int rows;
  printf("How many rows you want in your jagged array?\n");
  fflush(stdout);
  scanf("%d", &rows);

  int **arr = (int **)malloc(rows * sizeof(int *));
  if(arr == NULL){
    printf("Memory allocation failed.\n");
    free(arr);
    return 1;
  }

  int *colSize = (int *)malloc(rows * sizeof(int *));
  if(colSize == NULL){
    printf("Memory allocation failed.\n");
    free(colSize);
    return 1;
  }  
  for(int i = 0; i < rows; i++){
   
    printf("How many columns you want in your %dth row?\n", i + 1);
    fflush(stdout);
    scanf("%d", &colSize[i]);
    arr[i]  = (int *)malloc(colSize[i] * sizeof(int));
    if(arr[i] == NULL){
      printf("Memory allocation failed at %d", i);
      for(int k = 0; k < i; k++){
        free(arr[k]);
        arr[k] = NULL;
      }
      free(arr[i]);
      free(colSize);
      return 1;
    }
    printf("Enter the elements of the %dth row:\n", i + 1);
    fflush(stdout);
    for(int j = 0; j < colSize[i]; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  
  display2Darray(arr, rows, colSize);
  
  for(int k = 0; k < rows; k++){
      free(arr[k]);
      arr[k] = NULL;
   }
  free(colSize);
  free(arr);
  return 0;
}

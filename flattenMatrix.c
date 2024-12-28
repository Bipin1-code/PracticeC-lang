//Write a program for to flatten the matrix: convert 2D array into 1D array.

#include <stdio.h>
#include <stdlib.h>

void display2Darray( int **mtx, int rw, int cl){
  int temp[rw * cl], n = 0;
  for(int i = 0; i < rw; i++){
    for(int j = 0; j < cl; j++){
      printf("%d ", mtx[i][j]);
      temp[n++] = mtx[i][j];
    }
    printf("\n");
  }
  printf("Here is the 1D array of the given 2D array:\n");
  for(int i = 0; i < rw * cl; i++){
    printf("%d ", temp[i]);
  }
  printf("\n");
}

int main(){
  int r, c;
  printf("Enter the numbers for to make rows and cols:\n");
  fflush(stdout);
  scanf("%d %d", &r, &c);

  int **arr = (int **)malloc( r * sizeof(int *));
  if(arr == NULL){
    printf("Memory allocation failed.\n");
    free(arr);
    return 1;
  }
  for(int i = 0; i < r; i++){
    arr[i] = (int *)malloc( c * sizeof(int));
    if(arr[i] == NULL){
      for(int k = 0; k < i; k++){
        free(arr[k]);
        arr[k] = NULL;
      }
      free(arr[i]);
      return 1;
    }
    printf("Enter the elements for %dth row:\n", i);
    fflush(stdout);
    for(int j = 0; j < c; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  
  display2Darray( arr, r, c);
 
  for(int  k = 0; k < r; k++){
    free(arr[k]);
  }
  free(arr);
  return 0;
}

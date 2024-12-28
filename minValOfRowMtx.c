//Write a program for to find the minimum element of each row of a matrix.

#include <stdio.h>
#include <stdlib.h>

void display2Darray(int **arr, int r, int c){
  for(int i = 0; i < r; i++){
    int min = 0;
    for(int j = 0; j < c; j++){
      min = arr[i][0];
      if(min > arr[i][j]) min = arr[i][j];
      printf("%d ", arr[i][j]);
    }
    printf("\n %d is min.\n", min);
  }
}

int main(){
  int rs, cs;
  printf("How many rows and columns you wanna create?\n");
  fflush(stdout);
  scanf("%d %d", &rs, &cs);

  int **mtx = (int **)malloc(rs * sizeof(int *));
  if(mtx == NULL){
    free(mtx);
  }
  for(int i = 0; i < rs; i++){
    mtx[i] = (int *)malloc( cs * sizeof(int));
    if(mtx[i] == NULL){
      for(int k = 0; k < i; k++){
        free(mtx[k]);
        mtx[k] = NULL;
      }
      free(mtx[i]);
      return 1;
    }
    printf("Enter the elements of the %dth rows:\n", i + 1);
    fflush(stdout);
    for(int j = 0; j < cs; j++){
      scanf("%d", &mtx[i][j]);
    }
  }

  display2Darray(mtx, rs, cs);

  for(int k = 0; k < rs; k++){
    free(mtx[k]);
    mtx[k] = NULL;
  }
  free(mtx);
  return 0;
}

//Write a program for to do sum of two matrices

#include <stdio.h>
#include <stdlib.h>

void display2Dmtx(int *arr[], int r, int c){
  printf("Here is your matrix generated by given input:\n");
   for(int i = 0; i < r; i++){
     for( int j = 0; j < c; j++){
       printf("%d ", arr[i][j]);
     }
    printf("\n");
   } 
}

void addTwoMtx(int **arr1, int r1, int c1, int **arr2, int r2, int c2, int **rSum){
   for(int i = 0; i < r1; i++){
     for( int j = 0; j < c1; j++){
       rSum[i][j] = arr1[i][j] + arr2[i][j];
     }
   }
   display2Dmtx( rSum, r1, c1);
}

void create2Dmtx(int **arr, int r, int c){
  for(int i = 0; i < r; i++){
    arr[i] = (int *)malloc( c * sizeof(int));
    if(arr[i] == NULL){
      printf("Memory allocation failed.\n");
      for(int k = 0; k < i; k++){
        free(arr[k]);
        arr[k] = NULL;
      }
      free(arr[i]);
      return;
    }
    printf("Enter the elements of %dth rows:\n", i);
    fflush(stdout);
    for( int j = 0; j < c; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  display2Dmtx(arr, r, c);
} 

int main(){
  int rows1, cols1, rows2, cols2;
  printf("How many rows and cols you wanna make in your first matrix?\n");
  fflush(stdout);
  scanf("%d %d", &rows1, &cols1);
  
  printf("How many rows and cols you wanna make in your second matrix?\n");
  fflush(stdout);
  scanf("%d %d", &rows2, &cols2);

  if((rows1 != rows2) || (cols1 != cols2)){
    printf("Hey!, Do you even know the constrains while doing matrix sum? Get familiar with it and come back.\n");
    return 1;
  }

  int **mA = (int **)malloc(rows1 * sizeof(int *));
  if(mA == NULL){
    printf("Memory allocation failed.\n");
    free(mA);
    return 1;
  }

  int **mB = (int **)malloc(rows2 * sizeof(int *));
  if(mB == NULL){
    printf("Memory allocation failed.\n");
    free(mA);
    return 1;
  }

  create2Dmtx(mA, rows1, cols1);
  create2Dmtx(mB, rows2, cols2);

  int**mSum =(int **)malloc(rows1 * sizeof(int *));
  if(mSum == NULL){
    printf("Memory allocation failed.\n");
    free(mSum);
    return 1;
  }
  for(int i = 0; i < rows1; i++){
    mSum[i] = (int *)malloc( cols1 * sizeof(int));
    if(mSum[i] == NULL){
      printf("Memory allocation failed.\n");
      for(int k = 0; k < i; k++){
        free(mSum[k]);
        mSum[k] = NULL;
      }
      free(mSum[i]);
      return 1;
    }
  }

  addTwoMtx(mA, rows1, rows2, mB, rows2, cols2, mSum);

  for(int k = 0; k < rows1; k++) free(mA[k]);
  for(int k =0; k < rows2; k++) free(mB[k]);
  
  free(mA);
  free(mB);
  return 0;
}
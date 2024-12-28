///Write a program for to multiply a matrix with a scalar.

#include <stdio.h>

void scalarMultiMtx(int arr[][3], int a, int b, int cnst){
   for(int i = 0; i < a; i++){
    for(int j = 0; j < b; j++){
      arr[i][j] = arr[i][j] * cnst;
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int main(){
  int r  = 3, c = 3;
  int matrix[r][c], num = 1;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      matrix[i][j] = num++;
    }
  }
  int scalar;
  printf("Enter the number as a scalar: \n");
  fflush(stdout);
  scanf("%d", &scalar);
  scalarMultiMtx(matrix, 3, 3, scalar);
  return 0;
}

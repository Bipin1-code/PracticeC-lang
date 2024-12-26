
//This file is for to check palindrome

#include <stdio.h>
#include <stdlib.h>

void pdromeCheck(int arr1[], int size){
 int newS = size / 2;
 for(int i = 0; i < newS; i++ ){
    if(arr1[i] != arr1[size - 1 - i]){
       printf("It's not a palindrome array.\n");
       return;
      }
  } 
  printf("It's a palindrome array.\n");
}

int main(){
  int n;
  printf("Enter the size of the array:\n");
  fflush(stdout);
  scanf("%d", &n);
  int *arr = (int *)malloc(n * sizeof(int));
  if(arr == NULL){
    printf("Memory allocation failed!\n");
    return 1;
  }
  printf("Enter the element of the array:\n");
  fflush(stdout);
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }
  pdromeCheck(arr, n);
  free(arr);
  arr = NULL;
  return 0;
}

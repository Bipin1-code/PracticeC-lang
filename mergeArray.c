///Here we are gonna write a code for to merge two array:

#include <stdio.h>

void fillArray(int arr[], int size){
   for(int i = 0; i < size; i++){
    scanf("%d", &arr[i]);
  }
}
void mergeArray(int arr1[], int arr2[], int sOfA1, int sOfA2){
  int size = sOfA1 + sOfA2;
  int unitedArray[size];
  // Now we are fill the unitedArray
  for(int i = 0; i < size; i++){
    if(i >= 0 && i < sOfA1 ){
      unitedArray[i] = arr1[i];
    }
    else{
      unitedArray[i] = arr2[i - sOfA1];
    }
  }
  for(int i = 0; i < size; i++){
    printf("%d ", unitedArray[i]);
  }
}
int main(){
  int n, m;
  printf("Enter the size of the two arrays: n for first and m for second: \n");
  fflush(stdout);
  scanf("%d %d", &n , &m);
  int arr1[n];
  printf("Enter the elements for the first array: \n");
  fflush(stdout);
  fillArray(arr1, n);
  int arr2[m];
  printf("Enter the elements for the second array: \n");
  fflush(stdout);
  fillArray(arr2,m);
  // calling the mergeArray function
  mergeArray(arr1, arr2, n, m);
  printf("\n");
  return 0;
}

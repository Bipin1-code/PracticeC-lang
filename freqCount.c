
//This program find the frequency of element appears in an array:
#include <stdio.h>
int main(){
  int n;
  printf("Enter the size of the array: \n");
  fflush(stdout);
  scanf("%d", &n);
  int newArr[n];
  printf("Enter the elements of the array: \n");
  for(int i = 0; i < n; i++){
    scanf("%d", &newArr[i]);
  }
  int visited[n];
  for(int i = 0; i < n; i++){
    visited[i] = 0;
  }
  for(int i = 0; i < n; i++){
    if(visited[i] == 1){
      continue;
    }else{
      int count = 1;
      for(int j = i + 1; j < n; j++){
        if(newArr[i] == newArr[j]){
          count++;
          visited[j] = 1;
        }
      }
      printf("%d appears %d times. \n", newArr[i], count);
    }
  }
  return 0;
}

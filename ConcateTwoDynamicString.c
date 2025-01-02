

//Write a program for to concatenate two string, where the result dynamically resizes to accommodate the combined length.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* createArray(size_t s){
  char *str = NULL;
  size_t len = 0;
  char ch;

  printf("Enter a string (press Enter to finsih):\n");
  fflush(stdout);
  while((ch = getchar()) != '\n' && ch != EOF) {
    if(len + 1 >= s ){
      s = (s == 1 ) ? 5 : s * 5;
      char *temp = realloc(str, s);
      if(temp == NULL){
        printf("Memory allocation failed!\n");
        free(str);
        return NULL;
      }
      str = temp;
    }
    str[len++] = ch;
  }
  if(str){
    str[len] = '\0';
    return str;
  }
  free(str);
  return NULL;
}

char* concatenateTwoStrings(char *s1, char *s2, size_t s1n, size_t s2n ){
  size_t s = (s1n + s2n) + 2;
  char *r = (char *)malloc(s * sizeof(char));
  if(r == NULL){
    printf("Memory allocation for concatenated string failed!\n");
    return NULL;
  }
  
  for(int i = 0; i < s1n; i++){
    r[i] = s1[i];
  }
  
  r[s1n] = ' ';
  s1n++;
  for(int i = 0; i < s2n; i++){
    r[ s1n  + i] = s2[i];
  }
  r[s1n + s2n] = '\0';
  return r;
}

int main(){
  size_t size = 1;
  char *arr1 = createArray(size);
  if( arr1 == NULL){
    printf("Array-1 creatation failed.\n");
    return 1;
  }
  size_t size1 = strlen(arr1);
  char *arr2 = createArray(size);
  if( arr1 == NULL){
    printf("Array-2 creatation failed.\n");
    return 1;
  }
  size_t size2 = strlen(arr2);
  
  char *result = concatenateTwoStrings(arr1, arr2, size1, size2);
  if(result != NULL){
    printf("Concatenated String: %s\n", result);
    free(result);
  }
  free(arr1);
  free(arr2);
  
  return 0;
}


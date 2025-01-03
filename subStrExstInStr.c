
//Write a program that checks if a given substring exists in a string.
//The program should return the starting position of the substring or -1 if it doesn't exist.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void subStringExistInStr1(char *s1, char *s2){
  size_t l1 = 0, l2 = 0;
  l1 = strlen(s1);
  l2 = strlen(s2);
  if(l1 < l2){
    printf("length of second string is greater than first string so we can say str2 cannot be a substring of str1\n");
  }
  else{
    size_t i = 0;
    size_t j = 0;
    while(i < l1){ 
      if(s1[i] != s2[j] && (j > 0  && j != (l2 - 1))){
        j = 0;
      } 
      if(s1[i] == s2[j]){
        j++;
      }
      if(j == l2){
        size_t startIdx = i - (l2 - 1);      
        printf("subString exist which start from index %zu\n", startIdx);
        return;
      }
      i++;
    }
    printf("-1 mean substring doesn't exist.\n");
  }
}

char* createString(size_t size){
  char *s = NULL;
  char ch;
  size_t l = 0;
  printf("Write string:\n");
  fflush(stdout);
  while((ch = getchar()) != '\n' && ch != EOF){
    if(l + 1 >= size){
      size = ( size == l) ? 2 : size * 2;
      char *t = realloc(s, size);
      if(t == NULL){
        printf("Memory allocation failed!\n");
        free(s);
        return NULL;
      }
      s = t;
    }
    s[l++] = ch;
  }
  if(s){
    s[l] = '\0';
    return s;
  }
  free(s);
  return NULL;
}

int main(){
  size_t sz = 1;
  char *str1 = createString(sz);
  if(str1 == NULL){
    printf("Creation of str1 is failed!\n");
    free(str1);
    return 1;
  }
  char *str2 = createString(sz);
  if(str2 == NULL){
    printf("Creation of str2 is failed!\n");
    free(str2);
    return 1;
  }
  printf("Str1: %s\nStr2: %s\n", str1, str2);
  subStringExistInStr1(str1, str2);
  
  free(str1);
  free(str2);
  return 0;
}

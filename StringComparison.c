
//Write a program to compare two strings without using strcmp().
//The program should return 0 if the strings are equal,
//a positive value if the first string is lexicographically greater, and a negative value if the second string is greater.

#include <stdio.h>
#include <stdlib.h>

size_t findlength(char *arr){
  size_t l = 0;
  while( *arr != '\0'){
      l++;
      arr++;
    }
  return l;
}

int compareStrings(char *str1, char *str2){
  size_t len1 = findlength(str1);
  size_t len2 = findlength(str2);
  if(len2 > len1) return -1; //when second string length is greater
  if(len2 == len1){
     for(size_t i = 0; i < len1; i++){
      if(str1[i] != str2[i]){
        return 2; // when strings are not identical but length is equal 
      }
      return 0; //strings are identical
    }
  }
  return 1; //when first string length is greater
}  

char* createString(size_t size){
  char *s = NULL;
  char ch;
  size_t l = 0;
  printf("Write string: \n");
  fflush(stdout);
  while((ch = getchar()) != '\n' && ch != EOF){
    if(l + 1 >= size){
      size = (size == l) ? 2 : size * 2;
      char *temp = realloc(s, size);
      if(temp == NULL){
        printf("Memory allocation failed!\n");
        free(s);
        return NULL;
      }
      s = temp;
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
    printf("String Str1 creation failed!\n");
    free(str1);
    return 1;
  }
  char *str2 = createString(sz);
  if(str2 == NULL){
    printf("String Str1 creation failed!\n");
    free(str2);
    return 1;
  }
  printf("Str1: %s\n Str2: %s\n", str1, str2);
  int result = compareStrings(str1, str2);
  printf("%d\n", result);
  free(str1);
  free(str2);
  return 0;
}

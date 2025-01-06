
//Write a program for the find the first occurrence of substring in the string. Implement the strstr function.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* createString(size_t s){
  char *stg = NULL;
  char ch;
  size_t l = 0;
  printf("Write the string: (press enter if you done)\n");
  fflush(stdout);
  while((ch = getchar()) != '\n' && ch != EOF){
    if(l + 1 >= s){
      s = s * 2;
      char *temp = realloc(stg, s);
      if(temp == NULL){
        printf("Memory allocation failed!\n");
        free(stg);
        return NULL;
      }
      stg = temp;
    }
    stg[l++] = ch;
  }
  if(stg){
    stg[l] = '\0';
    return stg;
  }
  free(stg);
  return NULL;
}

int main(){
  size_t sz = 1;
  char *str = createString(sz);
  if(str == NULL){
    printf("String creation failed.\n");
    free(str);
    return 1;
  }
  char *subStr = createString(sz);
  if(subStr == NULL){
    printf("SubString creation failed!\n");
    free(subStr);
    return 1;
  } 
  printf("Substring is \"%s\".\n",subStr);
  char *result = strstr(str, subStr);
  if(result != NULL){
    printf("Substring found at %s.\n", result);
    long index = result - str;
    printf("Starting index: %ld\n", index);
  }else{
    printf("Substring not found in String \"str\".\n");
  }
  free(str);
  return 0;
}

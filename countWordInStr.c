
//Write a program for to count the words in a string.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t countWord(char *arr){
  size_t count = 0;
  int strLen = strlen(arr); 
  for(int i = 0; i < strLen; i++){
    if( arr[i] == ' ' && (i > 0 && arr[i - 1] != ' ') ){
      count++;
    }
    if(i == (strLen - 1) && arr[strLen - 1] != ' '){
      count++;
    }
  }
  return count;
}

char* createStr(size_t s){
  char *stc = NULL;
  char ch;
  size_t len = 0;
  printf("Write string:\n");
  fflush(stdout);
  while((ch = getchar()) != '\n' && ch != EOF){
    if(len + 1 >= s){
      s = s * 2;
      char *temp = realloc(stc , s);
      if(temp == NULL){
        printf("Memory allocation failed!\n");
        free(stc);
        return NULL;
      }
      stc = temp;
    }
    stc[len++] = ch;
  }
  if(stc){
    stc[len] = '\0';
    return stc;
  }
  free(stc);
  return NULL;
}

int main(){
  size_t size = 1;
  char *str = createStr(size);
  if(str == NULL){
    printf("Sentence creation failed!\n");
    free(str);
    return 1;
  }
  printf("%s\n", str);
  size_t words = countWord(str);
  printf("Words present in the given string is %zu \n", words);
  free(str);
  return 0;
}

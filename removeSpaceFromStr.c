
//Write a program for to reduce the spaces into single space between the words of a string, take string as an input from user.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reduceSpaceBtwWords(char *str){
  int len = strlen(str);
  int i = 0, j = 0;
  while( i < len ){
    if(str[i] == ' ' && (i == 0 || str[i - 1] == ' ')){
      i++;
      continue;
    }
    str[j++] = str[i++];
  }
  str[j] = '\0';
  return str;
}

char* createString(size_t size){
  char *str = NULL;
  char ch;
  size_t len = 0; 
  printf("Write sentence: (press Enter when you finish the sentence.)\n");
  fflush(stdout);
  while((ch = getchar()) != '\n' && ch != EOF){
    if(len + 1 >= size){
      size = (size == len ) ? 5 : size * 5;
      char *temp = realloc(str, size);
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

int main(){
  size_t sz = 1;
  char *stn = createString(sz);
  if(stn == NULL){
    printf("String creation failed!\n");
    return 1;
  }
  reduceSpaceBtwWords(stn);
  printf("new Sentence: %s\n", stn);
  free(stn);
  return 0;
}

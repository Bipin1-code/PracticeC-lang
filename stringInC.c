
//This is a play ground for to pupetting the string in C.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char *str = NULL;
  size_t size = 0, length = 0;
  char ch;
  printf("Enter a string ( press Enter to finish):\n");
  fflush(stdout);
  
  while((ch = getchar()) != '\n' && ch != EOF){
    if(length + 1 >= size){
      size = ( size == 0) ? 1 : size * 2;
      str = realloc(str, size);
      if(str == NULL){
        printf("Memory allocation failed!\n");
        fflush(stdout);
        return 1;
      }
    }
    str[length++] = ch;
  }
  if(str){
    str[length] = '\0';
    printf("You entered: %s\n", str);
    free(str);
  }else{
    printf("No input provided.\n");
  }
  return 0;
}

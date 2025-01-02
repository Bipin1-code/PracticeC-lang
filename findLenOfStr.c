

//Write a program to find a length of string, take string as a input from the user.

#include <stdio.h>
#include <stdlib.h>

char* createString(size_t n){
  char *s = NULL;
  char ch;
  size_t len = 0;
  printf("Now write: (Press Enter when you finish.)\n");
  fflush(stdout);
  while((ch = getchar()) != '\n' && ch != EOF){
    if(len + 1 >= n ){
      n = (n == 1) ? 5 : n * 5;
      char *temp = realloc(s, n);
      if(temp == NULL){
        printf("Memory allocation failed.\n");
        free(s);
        return NULL;
      }
      s = temp;
    }
    s[len++] = ch;
  }
  if(s){
    s[len] = '\0';
    return s;
  }
  free(s);
  return NULL;
}


int main(){
  size_t size = 1;
  char *str = createString(size);
  //checkig array or string created or not
  if(str == NULL){
    printf("String creatation failed.\n");
    return 1;
  }
  // first way is sizeof function
  // size_t size2 = sizeof(str); This gonna give us wrong answer because sizeof works with dataType or variable at compile time not at run time.
  size_t size2 = 0;
  char *originalBaseaddress = str; //We are doing this because after while loop str is not point to the base address which is good for to free up mmy.
  while(*str != '\0'){
    size2++;
    str++; 
  }
  //Also Note: when we declare array or string like: char str[] then in this case str is constant pointer we can't change str pointer
  // so for the we need to make a temp pointer which is gonna iterate over the string or array as given condition of iterator
  //char *temp = str then same as we did above in loop just replace str with temp
  //and also we don't need originalBaseaddress pointer because str is still pointing to the base address so free(str) works perfectly.
  printf("%zu is the length of string you just wrote.\n", size2);
  
  free(originalBaseaddress);
  return 0;
}

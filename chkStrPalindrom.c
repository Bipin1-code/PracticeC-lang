//Write a program for to check that string is palindrome or not, take string as input from user

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void chkStrIsPalindrome(char* stg){
  size_t size = strlen(stg);
  char *start = stg;
  char *end = &stg[size - 1];
  while( start < end ){
    *start = tolower(*start);
    if( *start != *end){
      printf("String is not plaindrome.\n");
      return;
    }
    start++;
    end--;
  }
  printf("String is plaindrome.\n");
}


char* createString(size_t s){
  char *stg = NULL;
  char ch;
  size_t l = 0;
  printf("Write here: \n");
  fflush(stdout);
  while ((ch = getchar()) != '\n' && ch != EOF){
    if(l + 1 >= s){
      s = ( s == 1) ? 5 : s * 5;
      char *temp = realloc(stg, s);
      if(temp == NULL){
        printf("Memory allocation failed!\n");
        free(temp);
        return NULL;
      }
      stg = temp;
    }
    stg[l++] = ch;
  }
  if(stg){
    stg[l] ='\0';
    return stg;
  }
  free(stg);
  return NULL;
}

int main(){
  size_t size = 1;
  char *str = createString(size);
  if(str == NULL){
    printf("String creatation failed.\n");
    return 1;
  }
  chkStrIsPalindrome(str);
  free(str);
  return 0;
}

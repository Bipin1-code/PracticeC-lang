
//Write a C program that removes all occurrences of a specified character from a given string.

#include <stdio.h>
#include <stdlib.h>

void rmvAlChrOccFrmStr(char *s, char c){
  int i = 0, j = 0;
  while(s[i] != '\0'){
    if(s[i] == c){
      i++; 
      continue;
    }
    else{
       s[j++] = s[i++];
    }
  }
  s[j] = '\0';
  printf("\"%s\" is the string after the removal of character %c.\n", s, c);
}

char* createString(size_t sz){
  char *s = NULL;
  char ch;
  size_t l = 0;
  printf("Write the string: \n");
  fflush(stdout);
  while((ch = getchar()) != '\n' && ch != EOF){
    if(l + 1 >= sz){
      sz = (sz == l) ? 2 : sz * 2;
      char *t = realloc(s, sz);
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
  char *str = createString(sz);
  if(str == NULL){
    printf("String creation failed!\n");
    free(str);
    return 1;
  }
  printf("\"%s\" is the string.\n", str);
  char ch;
  printf("Enter the character from the string which you want to remove entirely:\n");
  fflush(stdout);
  scanf("%c", &ch);

  rmvAlChrOccFrmStr(str, ch);
  
  free(str);
  return 0;
}

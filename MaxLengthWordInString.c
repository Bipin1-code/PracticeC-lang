
//Write a program to find the longest word in a sentence.
//For example, in the sentence "I love programming in C", the longest word is "programming".

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* findMaxLenWord(char *str){
  int *lTrk = NULL;
  size_t num = 1, len = 0;
  int l = strlen(str);
  size_t count = 0;
  for(int i  = 0; i < l; i++){
    count++;
    if(str[i] == ' ' || i == l - 1){
      if(i == l - 1 && str[i] != ' ' && str[i] != '.'){
        count++;
      }
      if(len + 1 >= num ){
        num *= 2;
        int *t = realloc(lTrk, num * sizeof(int));  
        if(t == NULL){
          printf("Memory allocation for length track array failed!\n");
          free(lTrk);
          return NULL;
        }
        lTrk = t;
      }
      lTrk[len++] = count - 1; //here we are -1 because count also count increased at ' ' case;
      count = 0;
    }
  }
  int max = lTrk[0];
  size_t maxIdx = 0, maxIdxStr = 0;
 
  for(size_t i = 0; i < len; i++){
    if(lTrk[i] > max){
      max = lTrk[i];
      maxIdx = i;
    }
  }
  for(size_t i = 0; i < maxIdx; i++){
      maxIdxStr += lTrk[i] + 1;
  }
  int j = 0;
  for(size_t i = maxIdxStr; i < (maxIdxStr + max); i++ ){
     str[j++] = str[i];
  }
  str[j] = '\0';
  return str;
}

char* createSentence(size_t s){
  char *str = NULL;
  char ch;
  size_t l = 0;
  printf("Enter the sentence:\n");
  fflush(stdout);
  while((ch = getchar()) != '\n' && ch != EOF){
    if( l + 1 >= s){
      s = s * 2;
      char *temp = realloc(str, s);
      if(temp == NULL){
        printf("Memo Error.\n");
        free(str);
        return NULL;
      }
      str = temp;
    }
    str[l++] = ch;
  }
  if(str){
    str[l] = '\0';
    return str;
  }
  free(str);
  return NULL;
}

int main(){
  size_t sz = 1;
  char *stn = createSentence(sz);
  if(stn == NULL){
    printf("Sentence has not create.\n");
    free(stn);
    return 1;
  }
  printf("%s\n", stn);
  findMaxLenWord(stn);
  printf("Max length word in given string is %s\n", stn);
  free(stn);
  return 0;
}

/* Note: As you can see these two difference while allocating memory:
   int *t = realloc(lTrk, num * sizeof(int));
   and
   char *temp = realloc(str, s);

   we didn't use sizeof for char because in C, char is 1 byte
   while other dataType have different bytes so we need to find the exact size for each int variable
   that's why we find value of int and product it with number of int type variable its gonna store.


   We can this above program, We will do when we have time.
 */

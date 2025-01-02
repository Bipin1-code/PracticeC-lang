

//Write a program to find the occurrences of vowels in a string.
//Instead of vowel you can use other characters also.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* createString(size_t size){
  char *str = NULL;
  size_t len = 0;
  char ch;
  printf("Enter the string (press Enter to finish):\n");
  fflush(stdout);
  while((ch = getchar()) != '\n' && ch != EOF){
    if(len + 1 >= size){
      size = (size == 1) ? 5 : size * 5;
      char *temp = realloc(str, size);
      if(temp == NULL){
        printf("Memo allocation failed!\n");
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

void countVowelOccurrence(char *str, size_t s){
  /* int count = 0;
  for(size_t i  = 0; i <= s; i++){
    if(str[i] == 'a' || str[i] == 'A'|| str[i] == 'e'|| str[i] == 'E'|| str[i] == 'i'|| str[i] == 'I' || str[i] == 'o' ||str[i] == 'O' || str[i] == 'u'|| str[i] == 'U'){
      count++;
    }
  }
  printf("Vowel character occurres %d times.\n", count); */
  //Let's find occurrence of each vowel character individually
  char vowelCh[5] = {'a', 'e', 'i', 'o', 'u'};
  char vowel[5] = {0};
  for (size_t i = 0; i < s; i++) {
        // Check for vowels and increment the respective counter
        if (str[i] == 'a' || str[i] == 'A') {
            vowel[0]++;
        } else if (str[i] == 'e' || str[i] == 'E') {
            vowel[1]++;
        } else if (str[i] == 'i' || str[i] == 'I') {
            vowel[2]++;
        } else if (str[i] == 'o' || str[i] == 'O') {
            vowel[3]++;
        } else if (str[i] == 'u' || str[i] == 'U') {
            vowel[4]++;
        }
    }
  for(size_t i = 0; i < 5; i++){
    printf("%c vowel character appeared %d times.\n", vowelCh[i], vowel[i]);
  }
  
}

int main(){
  size_t n = 1;
  char *str = createString(n);

  size_t len = strlen(str);
  countVowelOccurrence(str, len);

  free(str);
  return 0;
}

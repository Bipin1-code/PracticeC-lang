
//Similar program like strstr
//Write a program for to find the first occurrence of the subtring in a string.
//Also try to return number of occurrence of substring in a string with its index.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void myVersionOfStrstr(char *lS, char *sS){
  int lenOfsS = strlen(sS);
  int j = 0, count = 0;
  for(int i = 0; lS[i] != '\0'; i++){
    if(lS[i] == sS[j]){
      j++;
      if(j == lenOfsS){
        printf("SubString end at %d index of largeString \"lS\" \n", i);
        int stIndex = (i - lenOfsS) + 1; //We are adding 1 because in i our last char of subString present.
        printf("SubSting starting index is %d \n", stIndex);
        //If we want we can make an array an put the all information and return it to main
        count++;
        j = 0;
      }
    }
    if(j > 0 && lS[i-1] == sS[j-1] && lS[i] != sS[j]){
      j = 0;
    }  
  }
  printf("Substring \"sS\" occurred %d time inside the String \"lS\".\n", count);  
}

char* createString(size_t size){
  char *arr = NULL;
  char ch;
  size_t l = 0;
  printf("Write the string: (Press enter if you finished)\n");
  fflush(stdout);
  while((ch = getchar()) != '\n' && ch != EOF){
    if(l + 1 >= size){
      size = size * 2;
      char *tempArr = realloc(arr, size);
      if(tempArr == NULL){
        printf("Memory allocation failed!\n");
        return NULL;
      }
      arr = tempArr;
    }
    arr[l++] = ch;
  }
  if(arr){
    arr[l] = '\0';
    return arr;
  }
  free(arr);
  return NULL;
}

int main(){
  size_t z = 1;
  char *str = createString(z);
  if (str == NULL){
    printf("String creation failed!.\n");
    free(str);
    return 1;
  }
  char *subStr = createString(z);
  if(subStr == NULL){
    printf("SubString creation failed.\n");
    free(subStr);
    free(str); //because we are terminating the whole program
    return 1;
  }
  printf("String is %s\nsubString is %s\n", str, subStr);
  myVersionOfStrstr(str, subStr);
  free(str);
  free(subStr);
  return 0;
}

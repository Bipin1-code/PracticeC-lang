

//Write a program for to reverse a string.

#include <stdio.h>
#include <string.h>

void reverseStr(char *s, size_t n){
  int start = 0, end = n - 1;
  while( start < end){
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    start++;
    end--;
  }
  printf("Reverse string: %s\n", s);
}

int main(){
  char str[20];

  printf("Enter the string (maximum 19 characters):\n");
  fflush(stdout);
  fgets(str, sizeof(str), stdin);

  str[strcspn(str, "\n")] = '\0';
  
  printf("%s\n", str);
  size_t len = strlen(str);
  printf("%zu\n", len);
  reverseStr(str, len);
  return 0;
}

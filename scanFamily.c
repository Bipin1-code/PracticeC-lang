
/* scanf family from I/O */

#include <stdio.h>
#include <string.h>

void strToken(){
  FILE *f = fopen("strTest.txt", "rb+");
  if(!f) return;
  char word[64];
  char buffer[200];
  while(fgets(buffer, sizeof(buffer), f) != NULL){
    buffer[strcspn(buffer, "\n")] = '\0';
    char *temp = buffer; //assign parameter string here and remove outloop if you take string as parameter
    while(*temp){
      if(sscanf(temp, "%[^ 0-9,':;\t!]", word) != 1){
	temp++; //skip the separator
	continue;// jump back to while condition
      }
      printf("Word Token: %s\n", word); //print word
      temp += strlen(word); //temp index move to
      while(*temp && strchr(" ,':;\t!", *temp)) temp++;
    }
  }
  fclose(f);
}

int main(){

  char str[] = "Hello12 World32 Mic!";
  puts(str);
  
  size_t strl = strlen(str);
  printf("length of string is %zu\n", strl);

  strToken(); //pass string to it if want 
  
  return 0;
}


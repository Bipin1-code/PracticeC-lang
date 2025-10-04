///Find the length of string.


#include <stdio.h>
#include <stdlib.h>

char* createString(int s){
  int len = 0;
  char ch;
  char *str = (char*)malloc(s * sizeof(char));
  if(str == NULL){
    perror("Memory allocation for string is failed.\n");
    exit(1);
  }

  printf("Enter the text: (Press enter when finished)\n");
  fflush(stdout);

  while((ch = getchar()) != '\n' && ch != EOF){
    if(len + 1 >= s){
      s = s * 2;
      char *temp = (char*)realloc(str, s);
      if(temp == NULL){
	perror("Memory re-allocation for string is failed.\n");
	exit(1);
      }
      str = temp;
    }
    str[len++] = ch;
  }
  if(str){
    str[len] = '\0';
    return str;
  }else{
    perror("String create failed");
    exit(1);
  }
}

size_t fdStrlen(char *str){
  size_t length = 0;
  for(size_t i = 0; str[i] != '\0'; i++){
    if(str[i] != 0)
      length++;
    else
      break;
  }
  return length;
}

int stringCompare(char *str, char *str2){
  if(str == NULL && str2 == NULL) return 1;
  size_t s1L = fdStrlen(str);
  size_t s2L = fdStrlen(str2);
  if(s1L != s2L) return -1;
  else{
    int i = 0, j = 0;
    for(; i < s1L;){
      if(str[i] == str2[j]){
	i++;
	j++;
      }
      else{
	break;
      }
    }
    if(i != s1L && j != s2L ){
      return -1;
    }else
      return 1; 
  }
}

void strCopy(char *originalstr, char **wToC){
  size_t sz = fdStrlen(originalstr);
  *wToC =(char*)malloc((sz+1) * sizeof(char)); //1 for null char
  if(*wToC == NULL){
    perror("Memory allocation failed\n");
    exit(1);
  }
  size_t i = 0, l = 0;
  while( i < sz){
    (*wToC)[l++] = originalstr[i++];
  }

  (*wToC)[l] = '\0';
}

void strRngCopy(char **copy, char *src, size_t b, size_t end){
  size_t srcSz = fdStrlen(src);
  size_t cSz = end - b;
  *copy = (char*)malloc((cSz + 1) * sizeof(char));
  if(*copy == NULL){
    perror("Memory allocation failed.\n");
    exit(1);
  }
  size_t i = b, j = 0;
  while( i < end ){
    (*copy)[j++] = src[i++];
  }
  (*copy)[j] = '\0';
  printf("Copy String: %s.\n", *copy);
}

void trimleftSideofstr(char **str){
  size_t sz = fdStrlen(*str);
  size_t i = 0, count  = 0;
  while( i < sz && (*str)[i] == ' '){
    count++;
    i++; 
  }
  size_t newSize = sz - count + 1;
  char *temp = (char*)malloc(newSize * sizeof(char));
  if(temp == NULL){
    perror("Memory allocation for temp is failed.\n");
    exit(1);
  }
  size_t j;
  for(j = 0; j < newSize; j++){
    temp[j] = (*str)[count + j];
  }
  temp[j] = '\0';
  free(*str);
  *str = temp;
}

int main(){
  int size = 2;
  char *str = NULL;
  str = createString(size);
  if(str == NULL){
    perror("String creatation is failed.\n");
    exit(1);
  }
  //We will other operation on created string
  printf("String: %s\n", str);

  size_t length = fdStrlen(str);
  printf("Length of string is %zu\n", length);

  /* char *str2 = createString(size); */
  /* if(str == NULL){ */
  /*   perror("String creatation is failed.\n"); */
  /*   exit(1); */
  /* } */
  /* printf("String2: %s\n", str2); */
  
  /* int bol = stringCompare(str, str2); */
  /* if(bol > 0){ */
  /*   printf("True\n"); */
  /* }else{ */
  /*   printf("false\n"); */
  /* } */

  /* char *copy = NULL; */
  /* strCopy(str, &copy); */
  
  /* if(copy == NULL){ */
  /*   printf("Copy is not happened.\n"); */
  /* } */
  /* printf("Copy: %s\n", copy); */

  /* char *rcopy = NULL; */
  /* size_t start, end; */
  /* printf("Enter starting index and end index range of str to copy:\n"); */
  /* fflush(stdout); */
  /* scanf("%zu %zu", &start, &end); */
  /* strRngCopy(&rcopy, str, start, end); //end's char is excluded  */
  /* free(copy); */
  /* free(rcopy); */

  trimleftSideofstr(&str);
  printf("Trimed string: %s\n", str);
  
  free(str);
  //free(str2);
  return 0;
}

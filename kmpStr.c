//We are doing KMP algo for manipulate string with C language

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* myMessage(char *s){
  size_t sz = 1, len = 0;
  char ch;
  s =(char*)malloc(1 * sizeof(char));
  while((ch = getchar()) != '\n' && ch != EOF){
    if(len + 1 >= sz){
      sz = (sz == 1) ? 1 : sz * 5;
      s = (char*)realloc(s, sz);
      if(s == NULL){
	perror("Memory reallocation failed!\n");
	fflush(stdout);
	exit(1);
      }
    }
    s[len++] = ch;
  }
  if(s){
    s[len] = '\0';
  }
  return s;
}

void SubStrSearch(const char* s, const char* p){
  size_t s_len = 0, p_len = 0;
  s_len = strlen(s);
  p_len = strlen(p);
  if(s_len < p_len){
    printf("Pattern length is longer than the string. lol\n");
  }else{
    size_t i = 0, j = 0;
    while(i < s_len){
      if(s[i] != p[j] && (j > 0 && j != (p_len - 1))){
	j = 0;
      }
      if(s[i] == p[j]){
	j++;
      }
      if(j == p_len){
	size_t startIdx = i - (p_len - 1);
	printf("substring exist which start from index %zu.\n", startIdx);
	return;
      }
      i++;
    }
    printf("-1 mean substring doesn't exist.\n");
  }
}

int* createPrefixTable(const char* p){
  if(p == NULL) return NULL;
  int pLen = strlen(p);

  int* lps =(int*)malloc(pLen * sizeof(int));
  if(lps == NULL) return NULL;
  
  lps[0] = 0;
  int len = 0;
  int i = 1;

  while(i < pLen){
    if(p[i] == p[len]){
      len++;
      lps[i] = len;
      i++;
    }else{
      if(len != 0){
	len = lps[len-1]; 
      }else{
	lps[i] = 0;
	i++;
      }
    }
  }
  return lps;
}

void KMP_SubString(const char* str, const char* ptn){
  int* pfT = createPrefixTable(ptn);
  if(pfT == NULL){
    perror("Memo alloc failed.\n");
    exit(1);
  }
  int n = strlen(str);
  int p = strlen(ptn);

  int i = 0, j = 0;
  while(i < n){
    if(ptn[j] == str[i]){
      i++;
      j++;
    }
    if(j == p){
      printf("Pattern found at index %d\n", i - j);
      j = pfT[j-1];
    }else if( i < n && ptn[j] != str[i]){
      if(j != 0){
	j = pfT[j-1];
      }else{
	i++;
      }
    }
  }
  free(pfT);
}

int main(){

  char *str = NULL;
  printf("Write your message brother:\n");
  fflush(stdout);
  str = myMessage(str);
  printf("%s\n", str);
  printf("Write your message brother:\n");
  char *ptn = myMessage(ptn);
  fflush(stdout);
  printf("%s\n", ptn);

  SubStrSearch(str, ptn);

  KMP_SubString(str, ptn);
  
  free(str);
  free(ptn);
  return 0;
}

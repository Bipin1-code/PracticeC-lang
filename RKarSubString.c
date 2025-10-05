
//Rabin Karp algorithm for to find the sub string in a string
//Strict comparison is happening, if you want loss comparsion
//then, covert both pattern first in lower or upper case


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007  //large prime to minimize the collision
#define P 31  //base

char* createString(){
  size_t dsz = 2;//default size
  char *txt = (char*)malloc(dsz * sizeof(char));
  if(!txt){
    perror("Memory allocation failed for txt.\n");
    exit(1);
  }
  char ch;
  size_t len = 0;
  while((ch = getchar()) != '\n' && ch != EOF){
    if(len + 1 >= dsz){
      dsz *= 5;
      char* temp = (char*)realloc(txt, dsz);
      if(!temp){
	perror("Memory reallocation failed for txt.\n");
	exit(1);
      }
      txt = temp;
    }
    txt[len++] = ch;
  }
  if(txt){
    txt[len] = '\0';
  }
  return txt;
}

long long mod_multi(long long num, long long base, long long mod){
  long long result = 0;
  base = base % mod;
  while(base > 0){
    if(base % 2 == 1)
      result = (result + num) % mod;
    num = (num * 2) % mod;
    base = base / 2;
  }
  return result;
}

long long mod_pow(long long base, long long exp, long long mod){
  long long result = 1;
  while(exp > 0){
    if(exp % 2 == 1){
      result = mod_multi(result, base, mod);
    }
    base = mod_multi(base, base, mod);
    exp /= 2;
  }
  return result;
}


int RKarpfindSub(char *txt, char *pt){
  if(txt ==  NULL && pt == NULL){
    return 1;
  }  
  size_t tLen = strlen(txt);
  size_t ptLen = strlen(pt);
  if(tLen < ptLen){
    return -1;
  }

  long long p_pow = mod_pow(P, ptLen - 1, MOD); //Highest power of base

  long long hash_pat = 0, hash_txt = 0;
  
  for(size_t i = 0; i < ptLen; i++){
    hash_pat = (hash_pat * P + (pt[i] - 'a' + 1)) % MOD; //add 1 for to begin with 1; (a -> 1)
    hash_txt = (hash_txt * P + (txt[i] - 'a' + 1)) % MOD;
  }
  for(size_t i = 0; i <= tLen - ptLen; i++){
    //If hash Match, verify by comparing strings
    if(hash_pat == hash_txt){
      if(strncmp(txt + i, pt, ptLen) == 0){
	printf("Pattern found at index %d\n", i);
	fflush(stdout);
	return 1;
      }
    }
    //compute rolling hash: remove left char, add right char
    if( i < tLen - ptLen){
      hash_txt = (hash_txt - (txt[i] - 'a' + 1) * p_pow) % MOD;
      if(hash_txt < 0) hash_txt += MOD;
      hash_txt = (hash_txt * P + (txt[i + ptLen] - 'a' + 1)) % MOD;
    }
  }
  return -1;
}

int main(){

  printf("Write your txt:\n");
  fflush(stdout);
  char *text = createString();
  if(!text){
    perror("Text creation failed.\n");
    exit(1);
  }
  printf("Text: %s\n", text);
  printf("Write your pattern:\n");
  fflush(stdout);
  char *pattern = createString();
  if(!pattern){
    perror("Pattern creation failed.\n");
    exit(1);
  }
  printf("pattern: %s\n", pattern);

  int bol = RKarpfindSub(text, pattern);
  if(bol > 0){
    printf("SubString is present in %s\n", text);
  }else{
    printf("SubString is not present.\n");
  }
 
  
  free(text);
  free(pattern);
  return 0;
}

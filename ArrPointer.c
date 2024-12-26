
//Play ground for to learn Array of pointers:

#include <stdio.h>

int main(){
  int a = 10, b = 20, c = 30;
  int *arP[3];
  arP[0] = &a;
  arP[1] = &b;
  arP[2] = &c;

  for(int i = 0; i < 3; i++){
    printf("%d ", *arP[i]);
  }
  printf("\n");
  return 0;
}

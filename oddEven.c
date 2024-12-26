
#include <stdio.h>

void checkOE(int num){
  if(num % 2 == 0){
    printf("It's an even number: %d\n", num);
  }
  else{
    printf("It's an odd number : %d\n", num);
  }
}

int main(){
  int number;
  printf("Enter the number for to check it's even or odd: \n");
  fflush(stdout);
  scanf("%d", &number);
  checkOE(number);
  return 0;
}

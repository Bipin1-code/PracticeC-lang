
#include <stdio.h>

void isPrime(int n){
  if(n == 0 || n == 1){
    printf("%d is not a prime number. \n",n);
  }
  else{
    int factor = 0;
    for(int i = 2; i <= n/2; i++){
      if( n % i == 0){
        factor++;
        break;
      }
    }
    if( factor == 0){
      printf("%d is a prime number. \n", n);
    }
    else{
      printf("%d is not a prime number. \n", n);
    }
  }
}

int main(){
  int number;
  printf("Enter the number for to check is it prime or not: \n");
  fflush(stdout);
  scanf("%d", &number);
  isPrime(number);
}

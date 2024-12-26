
#include <stdio.h>

int fac(int n){
  int answer;
  if( n == 1)
    return (1);
  else
    answer = n * fac(n - 1);
  return answer;
}

/*
  Without recursive, logic is like this:

  int fac(int n){
   int answer = 1;
   while( n > 1)
   answer *= n;
   n--;
  }
 */

int main(){
  int number;
  printf("Enter the number to find the factorial of its: \n");
  fflush(stdout);
  scanf("%d", &number);
  int result = fac(number);
  printf("The factorial of number %d is %d\n", number, result);
  return 0;
}

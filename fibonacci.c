/*
 What is fibonacci number?
 Fibonacci number is a number in the Fibonacci sequence, a series of numbers where each number is the sum of the two preceding ones, starting from 0 and 1.
 Formula:  F(n) = F(n - 1) + F(n - 2)  for n >= 2
           Where:
                 F(0) = 0
                 F(1) = 1
 Each number in the sequence is the sum of the two preceding numbers.
 */
//Following program finds the nth fibonacci number:

#include <stdio.h>

int fiboNum(int n){
  int answer;
  if( n == 0 || n == 1){
    answer = n;
    return answer;
  }
  answer = fiboNum(n - 1) + fiboNum(n - 2);
  
  return answer;
}
//Let's try to print the fibonacci series upto nth term
void fiboSerie(int n){
  fflush(stdout);
  int series[n];
  for( int i = 0; i <= n; i++){
     series[i] = fiboNum(i);  
  }
  printf("Fibonacci serie of the upto given %dth term: ", n);
  fflush(stdout);
  for( int i = 0; i <= n; i++){
    printf("%d ", series[i]);
  }
  printf("\n");
}

int main(){
  int nterm;
  printf("Enter the nterm value: \n");
  fflush(stdout);
  scanf("%d", &nterm);
  int fibNumber = fiboNum(nterm);
  printf("Fibonacci number of the %dth term is %d. \n", nterm, fibNumber);
  fiboSerie(nterm);  
  return 0;
}



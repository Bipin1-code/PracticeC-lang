
#include <stdio.h>

int findMax(int x, int y, int z){
  if( x > y && x > z){
    return x;
  }
  else if( y > x && y > z){
    return y;
  }
  else{
    return z;
  }
}

int main(){
  int a, b, c;
  printf("Enter the three numbers to find out which one is maximum: \n");
  fflush(stdout);
  scanf("%d %d %d", &a, &b, &c);
  int max = findMax( a, b, c);
  printf("The maximum number among the given numbers is %d\n", max);
  return 0;
}


///Optimization of code playground
#include <stdio.h>

void leftShiftCyclic(int arr[], int n, int s) {
    s = s % n;  // Optimize for cases where s > n
    int count = 0; // Number of elements shifted
    for (int start = 0; count < n; start++) {
        int current = start;
        int temp = arr[start];

        do {
          int next = (current - s + n) % n; //for left shift
          //int next = (current + s) % n; //for right shift
          int temp2 = arr[next];
            arr[next] = temp;
            temp = temp2;

            current = next;
            count++;
        } while (start != current); // Complete the cycle
    }
    for(int i = 0; i < n; i++){
      printf("%d ", arr[i]);
    }
}


int main(){
  int n;
  printf("Enter the size of the array: \n");
  fflush(stdout);
  scanf("%d", &n);
  int arrOfNum[n];

  printf("Enter the elements of the array: \n");
  fflush(stdout);
  for(int i = 0; i < n; i++){
    scanf("%d", &arrOfNum[i]);
  }
  printf("\n");
  int s;
  printf("Enter the number of elements left shift you wanna perform: \n");
  fflush(stdout);
  scanf("%d", &s);
  leftShiftCyclic(arrOfNum, n, s);
  return 0;
}

/*
LC7_countElements
Given an integer array arr, count element x such that x + 1 is also in arr.

If there’re duplicates in arr, count them seperately.

Example 1:

Input: arr = [1,2,3]
Output: 2
Explanation: 1 and 2 are counted cause 2 and 3 are in arr.
*/

#include <stdio.h>

int countElements(int*,int);
int main() {
  printf("Hello\n");
  int arra[6] = {1, 3, 2, 3, 5, 0};
  int arrla = 6;
  int arrb[4] = {1, 1, 2, 2};
  int arrlb = 4;
  int a = countElements(arra, arrla);
  int b = countElements(arrb, arrlb);
  printf("%d\n",b);
  return 0;
}
int countElements(int* arr, int arrSize){
  //printf("hihi\n");
  int count = 0;
  for(int i = 0; i < arrSize;i++){
    for(int j = 0; j < arrSize; j++){
      if(arr[j] == arr[i] + 1){
        count++;
        break;
      }
    }
  }
  return count;
}
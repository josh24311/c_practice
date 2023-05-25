/******************************************************************************

                            LC7_countElements

*******************************************************************************/

/*
建表法
*/
#include <stdio.h>
#include <stdbool.h>

int countElements(int*,int);
int main() {
  int arra[6] = {1, 3, 2, 3, 5, 0};
  int arrla = 6;
  int arrb[4] = {1, 1, 2, 2};
  int arrlb = 4;
  
  printf("%d\n",countElements(arrb, arrlb));
  return 0;
}
int countElements(int* arr, int arrSize){
  //printf("hihi\n");
  int count = 0;
  bool isFound[1001];//0~1000
  for(int i = 0; i < arrSize; i++){
    isFound[i] = 0;
  }
  for(int i = 0; i < arrSize; i++){
    isFound[arr[i]] = 1;
  }
  
  for(int i = 0; i < arrSize;i++){
    if(isFound[arr[i] + 1] == true) {
      count++;
    }
  }
  return count;
}

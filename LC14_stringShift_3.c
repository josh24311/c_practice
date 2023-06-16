/*
LC14_Perform string shift
You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:

direction can be 0 (for left shift) or 1 (for right shift).
amount is the amount by which string s is to be shifted.
A left shift by 1 means remove the first character of s and append it to the end.
Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
Return the final string after all operations.
Constraints:

1 <= s.length <= 100
s only contains lower case English letters.
1 <= shift.length <= 100
shift[i].length == 2
0 <= shift[i][0] <= 1
0 <= shift[i][1] <= 100
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

void reverse(char* s, int start, int end){
  //[start,end)
  end--;
  while(start < end){
    char t = s[start];
    s[start] = s[end];
    s[end] = t;
    start++;
    end--;  
  }
  
}
char* stringShift(char * s, int** shift, int shiftSize, int *shiftColSize) {
  int len = strlen(s);
  int totalAmount = 0;
  for(int i = 0 ; i < shiftSize; i++){
    
    int direction =  shift[i][0];
    int amount    =  shift[i][1];

    amount = amount % len;//超過len則繞圈，故求餘數
    if(direction == 1){//若為右移,即解釋為左移len-amount
      amount = len - amount;
    }
    
    totalAmount += amount;
  }
  totalAmount %= len;
  /*//new array method
  char t[len];
  for(int i = 0 ; i < len; i++){
    t[i] = s[i];
  }
  for(int i = 0 ; i < len; i++){
    s[i] = t[(i+totalAmount)%len];
  }
  */
  //reverse method
  //s        = "abc|defg" , totalAmount = 3
  //final s  = "defg|abc"
  reverse(s,0,totalAmount);//前半反轉 -> cba|defg
  reverse(s,totalAmount,len);//後半反轉 -> cba|gfed
  reverse(s,0,len);//全反轉 -> defg|abc

  
  return s; 
}

int main() {
  char sa[4] = "abc";
  char sb[8] = "abcdefg";
  //int st1[2][2] = {{0,1},{1,2}};
  int **st1 = malloc(sizeof(int*)*2);
  st1[0] = malloc(sizeof(int)*2);
  st1[1] = malloc(sizeof(int)*2);
  st1[0][0] = 0;
  st1[0][1] = 1;
  st1[1][0] = 1;
  st1[1][1] = 2;
  //int st2[4][2] = {{1,1},{1,1},{0,2},{1,3}};
  int **st2 = malloc(sizeof(int*)*4);
  st2[0] = malloc(sizeof(int)*2);
  st2[1] = malloc(sizeof(int)*2);
  st2[2] = malloc(sizeof(int)*2);
  st2[3] = malloc(sizeof(int)*2);
  st2[0][0] = 1;
  st2[0][1] = 1;
  st2[1][0] = 1;
  st2[1][1] = 1;
  st2[2][0] = 0;
  st2[2][1] = 2;
  st2[3][0] = 1;
  st2[3][1] = 3;

  int sc1[] = {2,2};
  int sc2[] = {2,2,2,2};
  int size1 = 2;
  int size2 = 4;
  
  printf("String 1 after shifting  is %s\n", stringShift(sa, st1, size1, sc1));
  printf("String 2 after shifting  is %s\n", stringShift(sb, st2, size2, sc2));
  free(st1);
  free(st2);
  return 0;
}

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

char* stringShift(char * s, int** shift, int shiftSize, int *shiftColSize) {
  for(int i = 0 ; i < shiftSize; i++){
    // shift = {[0,1] , [1,2]}
    // s = abc
    // after [0,1]
    // s = bca
    // after [1,2]
    // s = cab
    int len = strlen(s);
    int direction =  shift[i][0];
    int amount    =  shift[i][1];
    if(direction == 0){
      for(int k = 1 ; k <= amount; k++){//共移動了amount次
        char tmp = s[0];
        for(int j = 0 ; j < len-1; j++){
          //abc
          //bca
          s[j] = s[j+1];
        }
        s[len-1] = tmp;
      }  
    }
    if(direction == 1){
      for(int k = 1 ; k <= amount; k++){
        char tmp = s[len-1];
        for(int j = len-1 ; j > 0; j--){
          //abc
          //cab
          s[j] = s[j-1];
        }
        s[0] = tmp;
      }
    }    
  }
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

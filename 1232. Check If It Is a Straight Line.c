/*
1232. Check If It Is a Straight Line

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

 
Example 1:

Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:


Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
 
Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int min(int a, int b){
  if(a < b) return a;
  else return b;
}
int max(int a, int b){
  if(a > b) return a;
  else return b;
}
int min3(int a, int b, int c){
  return min(min(a, b), c);
}
int max3(int a, int b, int c){
  return max(max(a, b), c);
}
typedef struct TreeNode{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;

} Tree;
struct ListNode{
  int val;
  struct ListNode *next; 
} ;

/****************************************************************************************/

bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize){
  int x1 = coordinates[0][0];
  int y1 = coordinates[0][1];
  int x2 = coordinates[1][0];
  int y2 = coordinates[1][1];
  
  for(int k = 2; k < coordinatesSize; k++){
    int x3 = coordinates[k][0];
    int y3 = coordinates[k][1];
    /*判斷斜率是否相等
      (x3-x1) / (y3-y1) == (x2-x1) / (y2-y1) , 移項
      (x3-x1) * (y2-y1) == (x2-x1) * (y3-y1)
      
    */
    if((x3-x1) * (y2-y1) != (x2-x1) * (y3-y1)){
      return false;
    }
  }
  return true;
  
}

/****************************************************************************************/
int main() {

  int** c = malloc(sizeof(int*)*6);
  for(int i = 0; i < 6; i++){
    c[i] = malloc(sizeof(int)*2);
  }
  c[0][0] = 1;
  c[0][1] = 2;
  c[1][0] = 2;
  c[1][1] = 3;
  c[2][0] = 3;
  c[2][1] = 4;
  c[3][0] = 4;
  c[3][1] = 5;
  c[4][0] = 5;
  c[4][1] = 6;
  c[5][0] = 6;
  c[5][1] = 7;
  
  int cs[6] = {2};
  printf("has line? %s\n",checkStraightLine(c, 6, cs)?"True":"False");
  c[0][1] = 1;
  c[1][1] = 2;
  c[5][0] = 7;
  printf("has line? %s\n",checkStraightLine(c, 6, cs)?"True":"False");
  return 0;
}
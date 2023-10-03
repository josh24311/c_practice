/*
986. Interval List Intersections
You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].

 

Example 1:


Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Example 2:

Input: firstList = [[1,3],[5,9]], secondList = []
Output: []
 

Constraints:

0 <= firstList.length, secondList.length <= 1000
firstList.length + secondList.length >= 1
0 <= starti < endi <= 109
endi < starti+1
0 <= startj < endj <= 109 
endj < startj+1

*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

int MAXSIZE;
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
int treeHeight(struct TreeNode* root){
  if(root == NULL) return 0;
  else{
    int lh = treeHeight(root->left);
    int rh = treeHeight(root->right);
    return max(lh, rh)+1;
  }
}
/***************************************************************************/
int** intervalIntersection(
    int** firstList, 
    int firstListSize, 
    int* firstListColSize, 
    int** secondList, 
    int secondListSize, 
    int* secondListColSize, 
    int* returnSize, 
    int** returnColumnSizes){

  int** ans = NULL;
  int aSize = 0;
  //(*returnSize) = 0;
  /*
  case1 A包含B
  (1) 2  3 [4]
     (2)[3]
  case2 B包含A
     (2)[3]
  (1) 2  3 [4]
  case3 部分交集A的尾巴較前
  1 2 3 (4)
    2 3  4 5
  case4 部分交集B的尾巴較前
    2 3  4 5
  1 2 3 (4)
  
*/
  int i = 0, j = 0;
  while(i < firstListSize && j < secondListSize){
    if(firstList[i][0] <= secondList[j][0] && firstList[i][1] >= secondList[j][1]){
      int* tmp = malloc(sizeof(int)*2);
      tmp[0] = secondList[j][0];
      tmp[1] = secondList[j][1];
      aSize++;
      ans = realloc(ans, sizeof(int*)*aSize);
      ans[aSize-1] = tmp;
    }
    else if (firstList[i][0] >= secondList[j][0] && firstList[i][1] <= secondList[j][1]){
      int* tmp = malloc(sizeof(int)*2);
      tmp[0] = firstList[i][0];
      tmp[1] = firstList[i][1];
      aSize++;
      ans = realloc(ans, sizeof(int*)*aSize);
      ans[aSize-1] = tmp;
    }
    else if (firstList[i][0] <= secondList[j][0] && secondList[j][0] <= firstList[i][1] && firstList[i][1] <= secondList[j][1]){
      int* tmp = malloc(sizeof(int)*2);
      tmp[0] = secondList[j][0];
      tmp[1] = firstList[i][1];
      aSize++;
      ans = realloc(ans, sizeof(int*)*aSize);
      ans[aSize-1] = tmp;
    }
    else if (firstList[i][0] >= secondList[j][0] && secondList[j][1] <= firstList[i][1] && firstList[i][0] <= secondList[j][1]){
      int* tmp = malloc(sizeof(int)*2);
      tmp[0] = firstList[i][0];
      tmp[1] = secondList[j][1];
      aSize++;
      ans = realloc(ans, sizeof(int*)*aSize);
      ans[aSize-1] = tmp;
    }
    //choose next list
    if(firstList[i][1] <= secondList[j][1]){
      i++;
    }
    else{
      j++;
    }
  }
  
  //return 
  *returnSize = aSize;
  int* ansColSize = malloc(sizeof(int)*aSize);
  for(int i = 0; i < *returnSize; i++){
    ansColSize[i] = 2;
  }
  *returnColumnSizes = ansColSize;
  return ans;
}


/***************************************************************************/
int main() {
  int** a = malloc(sizeof(int*)*4);
  int** b = malloc(sizeof(int*)*4);
  for(int i = 0; i < 4; i++){
    a[i] = malloc(sizeof(int)*2);
    b[i] = malloc(sizeof(int)*2);
  }
  a[0][0] = 0;
  a[0][1] = 2;
  a[1][0] = 5;
  a[1][1] = 10;
  a[2][0] = 13;
  a[2][1] = 23;
  a[3][0] = 24;
  a[3][1] = 25;
  int x = 2,y = 2,z = 0;
  int* p = &x;
  int* q = &y;
  int* r = &z;
  int** returnColumnSizes;
  b[0][0] = 1;
  b[0][1] = 5;
  b[1][0] = 8;
  b[1][1] = 12;
  b[2][0] = 15;
  b[2][1] = 24;
  b[3][0] = 25;
  b[3][1] = 26;
  int** ans1 = intervalIntersection(a, 4, p, b, 4, q, r, returnColumnSizes);
  for(int i = 0 ; i < 6; i++){
    printf("[");
    for(int j = 0; j < 2; j++){
      printf("%d ",ans1[i][j]);
    }
    printf("] ");
  }
  printf("\n\n");
  int** c = malloc(sizeof(int*)*2);
  for(int i = 0; i < 2; i++){
    c[i] = malloc(sizeof(int)*2);
  }
  c[0][0] = 1;
  c[0][1] = 3;
  c[1][0] = 5;
  c[1][1] = 9;
  int** d;
  return 0;
}
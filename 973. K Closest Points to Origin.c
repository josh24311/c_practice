/*
#qsort
973. K Closest Points to Origin
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

Example 1:

Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.


Constraints:

1 <= k <= points.length <= 10^4
-10^4 <= xi, yi <= 10^4
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <math.h>

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
/***************************************************************/
int cmp2(const void *pa, const void *pb){
  int *a = *(int**)pa;
  int *b = *(int**)pb;
  return (a[0]*a[0]+a[1]*a[1]) - (b[0]*b[0] + b[1]*b[1]);
}
int** kClosest(int** points, int pointsSize, int* pointsColSize, int k, int* returnSize, int** returnColumnSizes){
  (*returnSize) = k;
  
  *returnColumnSizes = malloc(sizeof(int)*k);
  for(int i = 0; i < k; i++){
    (*returnColumnSizes)[i] = 2;
  }
  
  
  qsort(points, pointsSize, sizeof(int*), cmp2);
  
  return points;
  
}

/***************************************************************/

int main() {
  int** arr1 = malloc(sizeof(int*)*2);
  for(int i = 0; i < 2; i++){
    arr1[i] = malloc(sizeof(int)*2);
  }
  arr1[0][0] = 1;
  arr1[0][1] = 3;
  arr1[1][0] = -2;
  arr1[1][1] = 2;

  int** arr2 = malloc(sizeof(int*)*3);
  for(int i = 0; i < 3; i++){
    arr2[i] = malloc(sizeof(int)*2);
  }
  arr2[0][0] = 3;
  arr2[0][1] = 3;
  arr2[1][0] = 5;
  arr2[1][1] = -1;
  arr2[2][0] = -2;
  arr2[2][1] = 4;
  int a = 0;
  int *p = &a;
  int b = 2;
  int *q = &b;
  int **pp = &q;
  
  int** ans1 = kClosest(arr1, 2, q, 1, p, pp);
  
  for(int i = 0; i < *p; i++){
    for(int j = 0; j < (*pp)[0]; j++){
      printf("%d ", ans1[i][j]);
    }
  }
  printf("\n\n");
  
  int** ans2 = kClosest(arr2, 3, q, 2, p, pp);
  for(int i = 0; i < *p; i++){
    for(int j = 0; j < (*pp)[0]; j++){
      printf("%d ", ans2[i][j]);
    }
  }
  
  return 0;
}
/*
#DP

1035. Uncrossed Lines
You are given two integer arrays nums1 and nums2. We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.

We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:

nums1[i] == nums2[j], and
the line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).

Return the maximum number of connecting lines we can draw in this way.

Example 1:

Input: nums1 = [1,4,2], nums2 = [1,2,4]
Output: 2
Explanation: We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from nums1[1] = 4 to nums2[2] = 4 will intersect the line from nums1[2]=2 to nums2[1]=2.
Example 2:

Input: nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
Output: 3
Example 3:

Input: nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
Output: 2
 

Constraints:

1 <= nums1.length, nums2.length <= 500
1 <= nums1[i], nums2[j] <= 2000
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

int cachedMaxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size, int** cache){
  if(nums1Size == 0)return 0;
  // nums1[nums1Size], nums2[nums2Size] 已經算過結果的話
  if(cache[nums1Size][nums2Size] != -1)return cache[nums1Size][nums2Size];
  // DP:考慮nums1 最後一個元素是否要選
  //case1 不選
  int case1 =  cachedMaxUncrossedLines(nums1, nums1Size-1, nums2, nums2Size, cache);
  //case2 要選
  // 再分兩種狀況 : 
  // 1. nums2中 沒有元素和nums1[nums1Size-1]連線 , 回傳 0
  // 2. nums2中 有元素和nums1[nums1Size-1]連線 , 選擇較靠近尾端者
  int case2 = 0;
  for(int j = nums2Size-1; j >=0 ; j--){
    if(nums2[j] == nums1[nums1Size-1]){
      case2 = 1 + cachedMaxUncrossedLines(nums1, nums1Size-1, nums2, j, cache);
      break;
    }
  }
  cache[nums1Size][nums2Size] = max(case1, case2);
  return cache[nums1Size][nums2Size];
}
int maxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size){
  //initial cache[i][j] as -1
  int** cache = malloc(sizeof(int*)*(nums1Size+1));
  for(int i = 0; i <= nums1Size; i++){
    cache[i] = malloc(sizeof(int)*(nums2Size+1));
    for(int j = 0; j <= nums2Size; j++){
      cache[i][j] = -1;
    }
  }

  int result = cachedMaxUncrossedLines(nums1, nums1Size, nums2, nums2Size, cache);
  free(cache);
  return result;
}

/***************************************************************/
int main() {
  int* a = malloc(sizeof(int)*3);
  int* b = malloc(sizeof(int)*3);
  b[0] = 1;
  b[1] = 2;
  b[2] = 4;
  a[0] = 1;
  a[1] = 4;
  a[2] = 2;
  printf("ans1 = %d\n",maxUncrossedLines(a, 3, b, 3));
  a = realloc(a, sizeof(int)*5);
  b = realloc(b, sizeof(int)*6);
  a[0] = 2;
  a[1] = 5;
  a[2] = 1;
  a[3] = 2;
  a[4] = 5;
  b[0] = 10;
  b[1] = 5;
  b[2] = 2;
  b[3] = 1;
  b[4] = 5;
  b[5] = 2;
  printf("ans2 = %d\n",maxUncrossedLines(a, 5, b, 6));
  a[0] = 1;
  a[1] = 9;
  a[2] = 2;
  a[3] = 5;
  a[4] = 1;
  b[0] = 1;
  b[1] = 3;
  b[2] = 7;
  b[3] = 1;
  b[4] = 7;
  b[5] = 5;
  printf("ans3 = %d\n",maxUncrossedLines(a, 5, b, 6));
  return 0;
}
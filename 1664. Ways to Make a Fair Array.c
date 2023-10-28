/*
1664. Ways to Make a Fair Array
You are given an integer array nums. You can choose exactly one index (0-indexed) and remove the element. Notice that the index of the elements may change after the removal.

For example, if nums = [6,1,7,4,1]:

Choosing to remove index 1 results in nums = [6,7,4,1].
Choosing to remove index 2 results in nums = [6,1,4,1].
Choosing to remove index 4 results in nums = [6,1,7,4].
An array is fair if the sum of the odd-indexed values equals the sum of the even-indexed values.

Return the number of indices that you could choose such that after the removal, nums is fair.

Example 1:

Input: nums = [2,1,6,4]
Output: 1
Explanation:
Remove index 0: [1,6,4] -> Even sum: 1 + 4 = 5. Odd sum: 6. Not fair.
Remove index 1: [2,6,4] -> Even sum: 2 + 4 = 6. Odd sum: 6. Fair.
Remove index 2: [2,1,4] -> Even sum: 2 + 4 = 6. Odd sum: 1. Not fair.
Remove index 3: [2,1,6] -> Even sum: 2 + 6 = 8. Odd sum: 1. Not fair.
There is 1 index that you can remove to make nums fair.
Example 2:

Input: nums = [1,1,1]
Output: 3
Explanation: You can remove any index and the remaining array is fair.
Example 3:

Input: nums = [1,2,3]
Output: 0
Explanation: You cannot make a fair array after removing any index.


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104
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
int waysToMakeFair(int* nums, int numsSize){
  
  // 2 1 6 4
  // 因為會取用到index i-1 ， 產生一個array將其[0] 設為 0，後面複製nums  不影響最後奇數偶數結果
  int* tmp = (int*)malloc(sizeof(int)*(numsSize+1));
  tmp[0] = 0;
  for(int i = 0; i < numsSize; i++){
    tmp[i+1] = nums[i];
  }
  /*
  // 0 2 1 6 4
  int* leftEven = malloc(sizeof(int)*(numsSize+1));
  int* leftOdd = malloc(sizeof(int)*(numsSize+1));
  
  for(int i = 0; i < numsSize+1; i++){
    leftOdd[i] = 0;
    leftEven[i] = 0;
  }
  int evenSum = 0, oddSum = 0;
  
  for(int i = 1; i <= numsSize; i++){
    if(i % 2 == 0){
      evenSum += tmp[i];
    }
    else{
      oddSum += tmp[i];
    }
    leftEven[i] = evenSum;//記錄到index i 為止左邊的偶數和
    leftOdd[i] = oddSum;//記錄到index i 為止左邊的奇數和
  }
  int ret = 0;
  int rightEven = 0, rightOdd = 0;
  for(int i = numsSize; i >= 1; i--){
    if(leftEven[i-1] + rightOdd == leftOdd[i-1] + rightEven){//移除掉i 所以i後面的奇數偶數的定義互換
      ret++;//每找到一個符合的i    ret++
    }
    if(i %2 == 0){
      rightEven += tmp[i];//更新右邊偶數和
    }
    else{
      rightOdd += tmp[i];//更新右邊奇數和
    }
  }
  free(tmp);
  free(leftEven);
  free(leftOdd);

  return ret;
  */
  //method 2 DP
  for(int i = 1; i <= numsSize; i++){
    if(i % 2 == 1){
      tmp[i] = tmp[i-1] + nums[i-1];
    }
    else{
      tmp[i] = tmp[i-1] - nums[i-1];
    }
  }
  int res = 0;
  for(int i = 1; i <= numsSize; i++){
    if(tmp[i-1] == tmp[numsSize] - tmp[i]){
      res++;
    }
  }
  free(tmp);
  return res;
}

/***************************************************************/

int main() {
  int planets[] = {2,1,6,4};
  printf("ans is %d\n",waysToMakeFair(planets, 4));
  return 0;
}
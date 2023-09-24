/*
918. Maximum Sum Circular Subarray
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
 

Constraints:

n == nums.length
1 <= n <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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
/*******************************************************************************/
int maxSubarraySumCircular(int* nums, int numsSize){
  //   1 -2 3 -2
  //   1 -2       => -1
  //        3 -2  => 1
  //        3     => 3
  //   1    3 -2  => 2
  //回傳 max(不考慮Circular狀況下的sum_max, total-不考慮Circular狀況下的sum_min)
  //其中 total-不考慮Circular狀況下的sum_min 即為考慮Circular狀況下的sum_max
  int total = 0;
  for(int i = 0; i < numsSize; i++){
    total+= nums[i];
  }
  int cur_max = nums[0];
  int cur_min = nums[0];
  int sum_max = nums[0];
  int sum_min = nums[0];

  for(int i = 1; i < numsSize; i++){
    if(cur_max < 0) cur_max = 0;//i到這個index發現總值為負(變小)，即不選此i, cur_max歸零

    if(cur_min > 0) cur_min = 0;//i到這個index發現總值為正(變大)，即不選此i, cur_min歸零
  
    cur_max+=nums[i];
    cur_min+=nums[i];

    sum_max = max(sum_max, cur_max);//更新index i 時的sum_max
    sum_min = min(sum_min, cur_min);//更新index i 時的sum_min
  }

  if(sum_min == total){//edge case: 當nums所有元素都為負，此時sum_max為負，total-sum_min為0，又至少要回傳一個值，所以回傳sum_max
    return sum_max;
  }
  return max(sum_max, total-sum_min);
  
  
}
/****************************************************************************************/
int main() {
  int* array1 = malloc(sizeof(int)*4);
  int* array2 = malloc(sizeof(int)*3);
  int* array3 = malloc(sizeof(int)*3);
  array1[0] = 1;
  array1[1] = -2;
  array1[2] = 3;
  array1[3] = -2;
  printf("ans1 = %d\n",maxSubarraySumCircular(array1, 4));
  array2[0] = 5;
  array2[1] = -3;
  array2[2] = 5;
  printf("ans2 = %d\n",maxSubarraySumCircular(array2, 3));
  array3[0] = -3;
  array3[1] = -2;
  array3[2] = -3;
  printf("ans3 = %d\n",maxSubarraySumCircular(array3, 3));
  

  return 0;
}
/*
#fast slow pointer
#binarysearch
287. Find the Duplicate Number
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.



Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3


Constraints:

1 <= n <= 10^5
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
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
int findDuplicate(int* nums, int numsSize){
  /*
  idx   0 1 2 3 4 
  nums  1 3 4 2 2
  (idx,num) : (0,1) -> (1,3) -> (3,2) -> (2,4) -> (4,2)
                                   ^                 ^
  1 -> 3 -> 2 -> 4 -
                   |
            ^ -----v

  idx   0 1 2 3 4 5
  nums  5 1 3 4 2 3
  (idx,nums) : (0,5) -> (5,3) -> (3,4) -> (4,2) -> (2,3) 
  5 -> 3 -> 4 -> 2 
                 |
       ^  -------
  
  */
  // method 1 : fast slow pointer T: O(n) S: O(1)
  /*
  int fast = 0;
  int slow = 0;
  while(true){
    slow = nums[slow];
    fast = nums[nums[fast]];
    if(fast == slow){
      break;
    }
  }
  printf("slow now %d\n",slow);
  int newn = 0;
  while(true){
    slow = nums[slow];
    newn = nums[newn];
    if(slow == newn){
      break;
    }
  }
  return slow;
  */
  //method 2 binary search T: O(nlogn) S: O(1)
  // 
  // 
  // 
  
  int low = 1;
  int high = numsSize-1;
  
  while(low < high){
    //printf("low %d, high %d\n",low,high);
    int mid = low + (high-low)/2;
    //printf("mid %d\n",mid);
    int cnt = 0;
    for(int i = 0; i < numsSize; i++){
      if(nums[i] <= mid){
        cnt++;
      }
    }
    if(cnt <= mid){
      low = mid+1;
    }
    else{
      high = mid;
    }
  }
  return low;
  
}
/***************************************************************/

int main() {
  int arr1[] = {1,3,4,2,2};
  //int arr1[] = {2,2,2,2,2};
  int arr2[] = {5,3,1,4,2,3};
  printf("ans1 %d\n",findDuplicate(arr1, 5));
  printf("ans2 %d\n",findDuplicate(arr2, 6));
    
  
  return 0;
}
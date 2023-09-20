/*
540. Single Element in a Sorted Array
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105
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
int treeHeight(struct TreeNode* root){
  if(root == NULL) return 0;
  else{
    int lh = treeHeight(root->left);
    int rh = treeHeight(root->right);
    return max(lh, rh)+1;
  }
}
/****************************************************************************************/
//Your solution must run in O(log n) time and O(1) space.
// O(n) 也可以用XOR方法做: 0 XOR X = X , X XOR X = 0，全部XOR一次，剩下的那個值就會是single

int singleNonDuplicate(int* nums, int numsSize){
  // check mid pivot
  //case1 : found single return mid
  //  ? ? ? [3 4 5] ? ? ?
  //           ^
  //case2 : mid's index is odd && odd is on left
  //  ? ?  [3 4 4] ? ? 
  //  [ odd ]      [ ]
  //case3 : mid's index is even && odd is on left
  //  ? ? ? [3 3 4] ? ? ?
  //  [odd]      [      ]
  //case4 : mid's index is even && odd is on right
  //  ? ? ? [3 4 4] ? ? ?
  //  [      ]      [odd]
  //case5 : mid's index is odd && odd is on right
  //  ? ? [3 3 4] ? ?
  //  [ ]      [odd ]

  // 思路2 
  // 規則A
  //     index n 為偶數 , 則其pair數的index必為n+1
  //     index n 為奇數 , 則其pair數的index必為n-1
  
  // index 0 1 2 3 4 5 6 7  
  //       1 1 2 2 4 4 8 8 
  //       p       m     q        
  // index 0 1 2 3 4 5 6 7 8 
  //       1 1 2 2 3 4 4 8 8
  //       p       m       q      
  int mid,p = 0, q = numsSize-1;
  while(p < q){
    mid = p + (q-p)/2;
    if(mid%2 == 0){//mid為偶數
      //check nums[mid+1]
      if(nums[mid] == nums[mid+1]){
        //代表左半"沒有"single number ，才會符合規則A => 移動p尋找右邊
        p = mid + 2; // 因為 nums[m+1] 已為pair
      }
      else{
        q = mid;
      }
    }
    else{//mid 為奇數
      if(nums[mid] == nums[mid-1]){
        //代表左半"沒有"single number ，才會符合規則A => 移動p尋找右邊
        p = mid + 1;
      }
      else{
        // 3 3 4 5 ? ?
        //       ^
        q = mid;
      }
    }
  }
  return nums[p];
  //       0 1 2 3 4 5 6 7 8
  //       1 1 2 2 3 4 4 8 8
  //           m   q       
  //               p
}



/****************************************************************************************/
int main() {
  
  int* array1 = malloc(sizeof(int)*9);
  array1[0] = 1;
  array1[1] = 1;
  array1[2] = 2;
  array1[3] = 3;
  array1[4] = 3;
  array1[5] = 4;
  array1[6] = 4;
  array1[7] = 8;
  array1[8] = 8;
  printf("Single number of array1 is %d\n",singleNonDuplicate(array1, 9));
  int* array2 = malloc(sizeof(int)*7);
  array2[0] = 3;
  array2[1] = 3;
  array2[2] = 7;
  array2[3] = 7;
  array2[4] = 10;
  array2[5] = 11;
  array2[6] = 11;
  printf("Single number of array2 is %d\n",singleNonDuplicate(array2, 7));
  return 0;
}
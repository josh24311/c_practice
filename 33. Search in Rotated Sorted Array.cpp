/*
#binarysearch
33. Search in Rotated Sorted Array
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1


Constraints:

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-10^4 <= target <= 10^4
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <numeric>
#include <string>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// ---------------------------------------

/*
1. 用nums[mid] 去判斷:左半有序還是右半有序
2. typeA , typeB 各自根據 target 在 左半或是右半 去更新 left, right 的值
3. 若 taget 恰等於 nums[mid] 回傳 mid
4. T:O(logn) , S:O(1)


  i     0   1 2  3  4 5 6
  ------------------------
  typeA 4 5 6 (7) 0 1 2  ，左半部有序
  pivot           ^
  typeB 7 8 1 (2) 3 4 5  , 左半部無序  = 右半部有序
  pivot     ^
  mid          m
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {// 參數的& 表示傳入nums當作參考，函式內對nums的操作會影響到原本的nums(ra)
      if(nums.size() == 0)return -1;
      
      int len = nums.size();
      int left = 0;
      int right = len-1;
      while(left <= right){
        int mid = left + (right-left)/2;
        if(nums[mid] == target){
          return mid;
        }
        if(nums[left] <= nums[mid]){ // typeA
          if(target >= nums[left] && target < nums[mid]){
            right = mid - 1; // target 在 left 和 mid(不包含)之間
          }
          else{
            left = mid + 1;// target 在 mid(不包含) 和 right之間
          }
        }
        else{
          if(target > nums[mid] && target <= nums[right]){
             left = mid + 1; 
          }
          else{
            right = mid - 1;
          }
        }
      }
      return -1;
    }

    
};
// ---------------------------------------
int main() {
  Solution s;
  vector<int> nums = {4,5,6,7,0,1,2};
  int target = 0;
  int result = s.search(nums, 7);
  if (result != -1) {
      std::cout << "Target " << target << " found at index " << result << std::endl;
  } else {
      std::cout << "Target " << target << " not found in the array." << std::endl;
  }
  
  return 0;
  
  
}
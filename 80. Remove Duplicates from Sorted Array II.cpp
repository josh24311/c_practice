/*
#array
80. Remove Duplicates from Sorted Array II
Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

1 <= nums.length <= 3 * 10^4
-10^4 <= nums[i] <= 10^4
nums is sorted in non-decreasing order.
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <numeric>
#include <climits>    
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
// ---------------------------------------
/*
T:O(n) , S:O(1)
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int n = nums.size();
      int p = 1;
      int res = 1;
      int counter = 1;
      int tmp = nums[0];
      for(int i = 1; i < n; i++){
        if(nums[i] != tmp){
          nums[p] = nums[i];
          tmp = nums[i];
          p++;
          res++;
          counter = 1;
        }
        else{
          if(counter >= 2){
            continue;
          }
          else{
            nums[p] = nums[i];
            p++;
            res++;
            counter++;
          }
        }
      }
      return res;
    }
};


// ---------------------------------------
int main() {
  Solution s;
  vector<int> v1 = {1,1,1,2,2,3};
  int k = s.removeDuplicates(v1);
  cout << "k: " << k << endl;
  for (int i = 0; i < k; i++) {
    cout << v1[i] << " ";
  }
  cout << endl;
  vector<int> v2 = {0,0,1,1,1,1,2,3,3};
  k = s.removeDuplicates(v2);
  cout << "k: " << k << endl;
  for (int i = 0; i < k; i++) {
    cout << v2[i] << " ";
  }
  cout << endl;
  return 0;
  
}
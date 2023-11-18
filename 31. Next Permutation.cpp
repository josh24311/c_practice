/*
#背規則
31. Next Permutation
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
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

1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      //step 1 由後往前找到第一個降序的元素
      int i = nums.size()-2;
      while(i >= 0 && nums[i] >= nums[i+1]){
        i--;
      }
      //step 2 由後往前找到第一個比 step 1 找到的元素大的元素
      if(i >= 0){
        int j = nums.size()-1;
        while(j >= 0 && nums[j] <= nums[i]){
          j--;
        }
      //step 3 交換 上述兩元素位置
        swap(nums[i], nums[j]);
      }
      //step 4 step 1 找到的index +1 後到結尾的元素做reverse
      reverse(nums.begin()+ i + 1, nums.end());
    }
};


// ---------------------------------------
int main() {
  Solution s;
  vector<int> v1 = {1,2,3};
  s.nextPermutation(v1);
  for (auto x : v1) {
    cout << x << " ";
  }
  cout << endl;
  vector<int> v2 = {3,2,1};
  s.nextPermutation(v2);
  for (auto x : v2) {
    cout << x << " ";
  }
  cout << endl;
  vector<int> v3 = {1,1,5};
  s.nextPermutation(v3);
  for (auto x : v3) {
    cout << x << " ";
  }
  
  return 0;
  
}
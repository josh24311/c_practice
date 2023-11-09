/*
#priorityQueue
#quickSelect
215. Kth Largest Element in an Array
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
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
// T:O(n)  , S:O(1)
// 3 2 1 5 6 4 find 2th largest
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      //priorityQueue
      /*
      priority_queue<int> maxHeap;
      for(int num:nums){
        maxHeap.push(num);
      }
      for(int i = 0; i < k-1; i++){
        maxHeap.pop();
      }
      return maxHeap.top();
      */
      //quickSelect
      if (nums.empty()) return 0;
      int n = nums.size();
      int left = 0;
      int right = n - 1;
      while(1){
        int pivotIndex = partition(nums, left, right);
        if(pivotIndex + 1 == k){
          return nums[pivotIndex];
        }
        else if(pivotIndex + 1 < k){//縮短範圍
          left = pivotIndex + 1;
        }
        else{
          right = pivotIndex - 1;//縮短範圍
        }
      }
      
    }
private:
    int partition(vector<int>& nums, int start, int end){
      srand((int)time(NULL));
      int rd = rand() % (end - start) + start;
      swap(nums[rd], nums[start]);//random index 擺到nums[start]
      int pivot = nums[start];
      int l = start + 1;
      int r = end;
      while(l <= r){//要讓比pivot大的都排左邊 比pivot小的都排右邊, 此處用 <= 
        if(nums[l] < pivot && nums[r] > pivot){
          swap(nums[l], nums[r]);
          l++;
          r--;
        }
        if(nums[l] >= pivot) l++;
        if(nums[r] <= pivot) r--;
      }
      swap(nums[r] , nums[start]);
      return r;
    }

    
};

// ---------------------------------------
int main() {
  Solution s;
  vector<int> ar1 = {3,2,1,5,6,4};
  int ans1 = s.findKthLargest(ar1, 2);
  cout << "ans1 = " << ans1 << endl;
  vector<int> ar2 = {3,2,3,1,2,4,5,5,6};
  int ans2 = s.findKthLargest(ar2, 4);
  cout << "ans2 = " << ans2 << endl;
  
  return 0;
}
/*
#binarysearch
#merge
#hard
4. Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
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
T:O(m) , S:O(1)

*/
/*
1 2
3 4 5 6 7 8

1 2 3 4 5 6 7 8

3 4
1 7 8 
1 3 4 7 8 

*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { 
      int m = nums1.size();
      int n = nums2.size();
      if(m > n){
        return findMedianSortedArrays(nums2, nums1);
      }
      int low = 0;
      int high = m;
      while(low <= high){// <=
        int partitionX = (low + high) / 2;
        int partitionY = (m + n + 1) / 2 - partitionX;

        int maxX = partitionX == 0 ? INT_MIN : nums1[partitionX - 1];//
        int minX = partitionX == m ? INT_MAX : nums1[partitionX];
        int maxY = partitionY == 0 ? INT_MIN : nums2[partitionY - 1];
        int minY = partitionY == n ? INT_MAX : nums2[partitionY];
        if(maxX <= minY && maxY <= minX){//適合的分割點partitionX
          if((m + n) % 2 == 0){
            return (static_cast<double>(max(maxX, maxY)) + static_cast<double>(min(minX, minY))) / 2.0;
          }
          else{
            return max(maxX, maxY);
          }
        }
        else if(maxX > minY){
          high = partitionX - 1;
        }
        else{
          low = partitionX + 1;
        }
      }
      
    }

};


// ---------------------------------------
int main() {
  Solution s;
  vector<int> num1 = {1,3};
  vector<int> num2 = {2};
  cout << s.findMedianSortedArrays(num1, num2) << endl;
  
  vector<int> num3 = {1,2};
  vector<int> num4 = {3,4};
  cout << s.findMedianSortedArrays(num3, num4) << endl;
  

  return 0;
  
}
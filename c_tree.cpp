/*
print christmas tree
given input of tree height, print christmas tree
for example, if the input is 3, the output should be:
    *
  * * *
* * * * *
   ***
   ***
   ***

if the input is 4, the output should be:
      *
    * * *
  * * * * *
* * * * * * *
     ***
     ***
     ***
     ***

*/
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
// ---------------------------------------
/*
T:O(m*n) , S:O(m*n)





*/

class Solution {
public:
  void printCTREE(const int h) {
    /*
        4s 1*
        2s 3*
        0s 5*
        3s 3*3
        ---
        6s 1*
        4s 3*
        2s 5*
        0s 7*
        5s 4*3
    */
    int i, j;
    for (i = 1; i <= h; i++) {
      for (j = 1; j <= 2 * (h - i); j++) {
        cout << " ";
      }
      for (j = 1; j <= 2 * i - 1; j++) {
        cout << "* ";
      }
      cout << endl;
    }
    for (i = 1; i <= h; i++) {
      for (j = 1; j <= 2 * h - 3; j++) {
        cout << " ";
      }
      cout << "***" << endl;
    }
    cout << endl;
  }
};

// ---------------------------------------
int main() {
  Solution s;
  s.printCTREE(3);
  s.printCTREE(4);
  s.printCTREE(5);
  cout << endl;
  return 0;
}
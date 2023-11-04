/*
#string
#vector
6. Zigzag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);


Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"


Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
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
class Solution {
public:
    string convert(string s, int numRows) {
      if(numRows == 1 || numRows > s.length()){
        return s;
      }

      vector<string> rows(min(numRows, int(s.length())));
      int currentRow = 0;
      bool goingDown = false;//一開始假設往上走

      for(char c: s){
        rows[currentRow] += c;//將字元加入到當前行
        if(currentRow == 0 || currentRow == numRows - 1){//當currentRow到達最頂行或最底行
          goingDown = !goingDown;//變換方向
        }
        currentRow += goingDown ? 1 : -1;//根據goingDown方向增加currentRow
      }
      string result;
      for(string row : rows){
        result += row;
      }
      return result;
    }
};


// ---------------------------------------
int main() {
  Solution s;
  string arr1 = "PAYPALISHIRING";
  int numRows = 3;
  string arr2 = "A";
  string ans1 = s.convert(arr1, numRows);
  cout << ans1 << endl;
  
  numRows = 4;
  string ans2 = s.convert(arr1, numRows);
  numRows = 1;
  string ans3 = s.convert(arr2, numRows);
  
  cout << ans2 << endl;
  cout << ans3 << endl;
  
  return 0;
  
  
}
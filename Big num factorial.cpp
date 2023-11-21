/*
#bigNumber
Calculate factorial of number n, n > 500000

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
T:O(nlogn) , S:O(1)

*/
class Solution {
public:
    string factorial(int n) {
      string res = "1";
      
      for(int i = 2; i <= n; i++){
        string str_i = to_string(i);
        res = multiply(res, str_i);
      }
      return res;
    }
private:
    string multiply(string num1, string num2){
      
      int len1 = num1.size();
      int len2 = num2.size();
      vector<int> result(len1+len2, 0);
      for(int i = len1-1; i >= 0; i--){
        for(int j = len2-1; j >= 0; j--){
          int mul = (num1[i] - '0') * (num2[j] - '0');
          int sum = mul + result[i + j + 1];
          result[i + j + 1 ] = sum % 10;
          result[i + j ] += sum / 10;
        }
      }
      
      string ans ;
      for(int digit: result){
        if(!(ans.empty() && digit == 0)){
          ans.push_back(digit + '0');
        }
      }
      return ans;
    }
};


// ---------------------------------------
int main() {
  Solution s;
  cout << "Input number n : " ;
  int n;
  cin >> n;
  string ans = s.factorial(n);
  cout << ans << endl;

  return 0;
  
}
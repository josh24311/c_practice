/*
17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]


Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].

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
    vector<string> letterCombinations(string digits) {
      vector<string> result;
      if(digits.empty()){
        return result;
      }
      vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
      string current;
      generateCominations(digits, 0, current, mapping, result);
      return result;
    }
private:
  void generateCominations(const string& digits, int index, string& current, const vector<string>& mapping,     vector<string>& result) {
    if(index == digits.length()){
      result.push_back(current);
      return;
    }
    int digit = digits[index] - '0';
    for(char c : mapping[digit]){
      current.push_back(c);
      generateCominations(digits, index+1, current, mapping, result);
      current.pop_back();//例如 ad 已存入result, pop d 出來 , current 剩 a , 繼續下一個for
    }
  }

};

// ---------------------------------------
int main() {
  Solution s;
  string digits = "23";
  vector<string> result = s.letterCombinations(digits);
  for(const string& comination : result){
    cout << comination << " ";
  }
  cout << endl;
  
  return 0;
  
  
}
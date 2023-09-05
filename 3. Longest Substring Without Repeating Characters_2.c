/*
3. Longest Substring Without Repeating Characters
Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
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

/****************************************************************************************/

int lengthOfLongestSubstring(char * s){
  //        -1 0 1 2 3 4 5
  //           p w w k e w 
  // i             ^
  // left      ^
  // num[p]    ^
  // num[w]      ^
  
  if(s == NULL){
    return 0;
  }
  
  int len = strlen(s);
  int num[128];
  int tmp,i;
  int left = 0;
  int maxlength = 0;
  memset(num,0,128*sizeof(int));
  for(i = 0; i < len; i++){
    num[s[i]]++;
    while(num[s[i]] > 1){
      num[s[left]]--;
      left++;
    }
    maxlength =  maxlength > (i-left+1)?maxlength:(i-left+1);
  }
  
  return maxlength;
/*


*/

}
/****************************************************************************************/
int main() {
  char* s = malloc(sizeof(char)*6);
  s[0] = 'p';
  s[1] = 'w';
  s[2] = 'w';
  s[3] = 'k';
  s[4] = 'e';
  s[5] = 'w';
  int ans = lengthOfLongestSubstring(s);
  printf("ans is %d\n",ans);

  return 0;
}
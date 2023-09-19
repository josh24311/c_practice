/*
125. Valid Palindrome
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
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
int treeHeight(struct TreeNode* root){
  if(root == NULL) return 0;
  else{
    int lh = treeHeight(root->left);
    int rh = treeHeight(root->right);
    return max(lh, rh)+1;
  }
}
/****************************************************************************************/

bool isPalindrome(char * s){
  // ascii 48~57   : 0~9
  // ascii 65~90   : A~Z
  // ascii 97~122  : a~z
  //A man, a plan, a canal: Panama
  // 雙指針 ， 先判別s[i] , s[j] 是否合法
  int len = strlen(s);
  int i = 0, j = len-1;
  while(i < j){
    if((s[i] >= 48 && s[i] <= 57) || (s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122)){
      
    }
    else{
      i++;
      continue;
    }
    if((s[j] >= 48 && s[j] <= 57) || (s[j] >= 65 && s[j] <= 90) || (s[j] >= 97 && s[j] <= 122)){
      
    }
    else{
      j--;
      continue;
    }
    
    if(s[i] == s[j] || (s[i] >= 65 && (s[i]+32) == s[j])  || (s[i] >= 65 && s[i]-32 == s[j])){
      // s[i] s[j] 都合法，判斷是否回文
      i++;                                                                                              
      j--;
    }
    else{
      return false;
    }
  }
  return true;

  
}
/****************************************************************************************/
int main() {
  char* s1 = "A man, a plan, a canal: Panama";
  char* s2 =  "race a car";
  char* s3 =  "  ";
  printf(" s1 is palindrome? %s\n",isPalindrome(s1)?"True":"Flase");
  printf(" s2 is palindrome? %s\n",isPalindrome(s2)?"True":"Flase");
  printf(" s3 is palindrome? %s\n",isPalindrome(s3)?"True":"Flase");
  return 0;
}
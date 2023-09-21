/*
392. Is Subsequence
Easy
Topics
Companies
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).


Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int MAXSIZE;
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
bool isSubsequence(char * s, char * t){
  /*
  index   0 1 2 3 4 5
  s       a b c
  t       a h b g d c
  i                   ^
  j             ^

  */
   int lens = strlen(s);
    int lent = strlen(t);
    int j = 0;
    for(int i = 0; i < lent && j < lens; i++){
        if(s[j] == t[i]){
            j++;
        }
    }
    return j == lens;
}

/****************************************************************************************/
int main() {
  
  char* s1 = "abc";
  char* t1 = "ahbgdc";
  char* s2 = "axc";
  char* t2 = "ahbgdc";
  printf("s1 is sub of t1 ? %s\n",isSubsequence(s1, t1)?"True":"False");
  printf("s2 is sub of t2 ? %s\n",isSubsequence(s2, t2)?"True":"False");
  return 0;
}
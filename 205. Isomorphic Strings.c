/*
205. Isomorphic Strings
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true

Example 2:
Input: s = "foo", t = "bar"
Output: false

Example 3:
Input: s = "paper", t = "title"
Output: true
 
Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
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
/*******************************************************************************/
/*
No two characters may map to the same character, but a character may map to itself.
s = "paper", t = "title" , t2 = "tatle"
s = "foo", t = "bar"
s = "badc", t = "baba"
*/
/*
bool isIsomorphic(char * s, char * t){
  int lenS = strlen(s);
  int lenT = strlen(t);
  if(lenS!=lenT)return false;
  char hs[256] = {0};
  int ht[256] = {0};
  int i = 0;
  while(i < lenS){
    if(hs[s[i]-'\0'] == 0){
      if(ht[t[i]] == 0){
        hs[s[i]-'\0'] = t[i];  
        ht[t[i]]++;
      }
      else{
        return false;
      }
    }
    else{
      if(hs[s[i]-'\0'] != t[i]) {
        return false;
      }
    }
    i++;
  }
  return true;
}
*/
bool isConflict(char* s, char* t){
  int i = 0;
  char hMap[128] = {0};
  while(s[i] != '\0'){
    if(hMap[s[i]] != 0 && hMap[s[i]] != t[i]){
      return true;//has conflict
    }
    else{
      hMap[s[i]] = t[i];
    }
    i++;
  }
  return false;
}
bool isIsomorphic(char * s, char * t){
  return !(isConflict(s, t) || isConflict(t, s));
}
/****************************************************************************************/
int main() {
  char* s1 = "badc"; 
  char* t1 = "baba";
  char* s2 = "foo";
  char* t2 = "bar";
  char* s3 = "paper";
  char* t3 = "title";
  printf("ans1 = %s\n",isIsomorphic(s1, t1)?"True":"False");
  printf("ans2 = %s\n",isIsomorphic(s2, t2)?"True":"False");
  printf("ans3 = %s\n",isIsomorphic(s3, t3)?"True":"False");
  
  return 0;
}
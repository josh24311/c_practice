/*
567. Permutation in String
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
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
bool checkInclusion(char * s1, char * s2){
  // s1 = "adc", s2 = "dcda"
  //                         ^
  int lenS1 = strlen(s1) ;//3
  int lenS2 = strlen(s2) ;//4
  if(lenS1 > lenS2) return false;
  int s1Map['z'-'a'+1] = {0};
  int s2Map['z'-'a'+1] = {0};
  for(int i = 0; i < lenS1; i++){// 1 0 1 1
    s1Map[s1[i]-'a']++;
  }
  for(int i = 0; i < lenS1; i++){// 0 0 1 2
    s2Map[s2[i]-'a']++;
  }
  // count diff
  
  int diff = 0;
  for(char c = 'a'; c <= 'z'; c++){
    if(s1Map[c-'a'] != s2Map[c-'a']){
      diff++;
    }
  }
  for(int i = 0; i < lenS2-lenS1+1;i++){
    if(diff == 0)return true;
    else{
      if(lenS1+i < lenS2){
        s2Map[s2[i]-'a']--;
        s2Map[s2[i+lenS1]-'a']++;  
      }  
      diff = 0;
      for(char c = 'a'; c <= 'z'; c++){
        if(s1Map[c-'a'] != s2Map[c-'a']){
          diff++;
        }
      }  
    }
  }
  return false;
}

/****************************************************************************************/
int main() {
  char* s1 = "adc"; 
  char* s2 = "dcda";
  printf("ans1 = %s\n",checkInclusion(s1, s2)?"True":"False");
  //char* s3 = "eidboaoo";
  //printf("ans2 = %s\n",checkInclusion(s1, s3)?"True":"False");
  
  return 0;
}
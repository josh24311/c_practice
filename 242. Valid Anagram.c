/*
#qsort
#hashMap
242. Valid Anagram
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 10^4
s and t consist of lowercase English letters.

*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <math.h>

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
/***************************************************************/
int cmp2(const void *a, const void *b){
  return (*(char*)a ) - (*(char*)b );
}
bool isAnagram(char * s, char * t){
  int sLen = strlen(s);
  int tLen = strlen(t);
  if(sLen != tLen) return false;
  //method1 qsort
  /*
  qsort(s, sLen, sizeof(char), cmp2);
  qsort(t, tLen, sizeof(char), cmp2);
  for(int i = 0; i < sLen; i++){
    if(s[i] != t[i]){
      return false;
    }
  }
  return true;
  */
  //method2 HashMap
  int sCount[26] = {0};
  int tCount[26] = {0};
  for(int i = 0; i < sLen; i++){
    sCount[s[i]-'a']++;
    tCount[t[i]-'a']++;
  }
  for(int i = 0; i < 26; i++){
    //printf("sCount[%d] = %d, tCount[%d] = %d\n",i,sCount[i], i, tCount[i]);
    
    if(sCount[i] != tCount[i]){
      return false;
    }
    
  }
  return true;
}

/***************************************************************/
int main() {
  char s1[] = "anagram";
  char t1[] = "nagaram";
  char s2[] = "nl";
  char t2[] = "cx";
  printf("ans1 %s\n",isAnagram(s1, t1)?"True":"False");
  printf("ans2 %s\n",isAnagram(s2, t2)?"True":"False");
  
  return 0;
}
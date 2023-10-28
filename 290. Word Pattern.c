/*
#hash
#strtok
290. Word Pattern
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.



Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false


Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.
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
/*
char pattern1[] = "abba";
char s1[] = "dog cat cat dog";
*/
/***************************************************************/
bool wordPattern(char * pattern, char * s){
  int len = (strlen(s)/2)+2, size = 0;
  char** arr = malloc(sizeof(char*)*len);
  for(int i = 0; i < len; i++){
    arr[i] = malloc(sizeof(char)*15);
  }
  arr[size] = strtok(s, " ");
  len = strlen(pattern);
  while(arr[size] != NULL){
    size++;
    arr[size] = strtok(NULL, " ");
    if(arr[size] == NULL && size != len){
      return false;
    }
  }
  for(int i = 0; i < len; i++){
    for(int j = i+1; j < len; j++){
      if ((pattern[i] == pattern[j] && strcmp(arr[i], arr[j]) != 0) || (pattern[i] != pattern[j] && strcmp(arr[i], arr[j]) == 0)){
        return false;
      }
    }
  }
  return true;
}
/***************************************************************/

int main() {
  char pattern1[] = "abba";
  char pattern2[] = "aaaa";
  char s1[] = "dog cat cat dog";
  char s2[] = "dog cat cat dogo";
  printf("ans1 : %s\n",wordPattern(pattern1, s1)?"true":"false");
  printf("ans2 : %s\n",wordPattern(pattern1, s2)?"true":"false");
  printf("ans3 : %s\n",wordPattern(pattern2, s1)?"true":"false");
  
  return 0;
}
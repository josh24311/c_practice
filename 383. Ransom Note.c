/*
383. Ransom Note
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.
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
bool canConstruct(char * ransomNote, char * magazine){
  int notea[128];
  memset(notea,0,sizeof(int)*128);
  int noteb[128];
  memset(noteb,0,sizeof(int)*128);
  int len1 = strlen(ransomNote);
  int len2 = strlen(magazine);
  for(int i = 0; i < len1; i++){
    notea[ransomNote[i]]++;
  }
  for(int i = 0; i < len2; i++){
    noteb[magazine[i]]++;
  }
  for(int i = 0; i < len1; i++){
    if(notea[ransomNote[i]] > noteb[ransomNote[i]]) return false;
  }

  return true;
}

/****************************************************************************************/
int main() {
  char* s = malloc(sizeof(char)*4);
  s[0] = 'c';
  s[1] = 'b';
  s[2] = 'a';
  s[3] = 'c';
  char* d = malloc(sizeof(char)*5);
  d[0] = 'a';
  d[1] = 'b';
  d[2] = 'a';
  d[3] = 'b';
  d[4] = 'c';

  char* f = malloc(sizeof(char)*3);
  f[0] = 'c';
  f[1] = 'b';
  f[2] = 'a';

  printf("s, d OK ? %s\n",canConstruct(s,d)?"True":"False");
  printf("f, d OK ? %s\n",canConstruct(f,d)?"True":"False");
  

  return 0;
}
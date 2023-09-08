/*
387. First Unique Character in a String

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1
 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.
 
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
// l e e t c o d e
// a a b b
// a b c a b 
int firstUniqChar(char * s){
  int len = strlen(s);
  if(len == 1)return 0;
  int c['z'-'a'+1] = {0};
  for(int i = 0; i < len; i++){
    c[s[i]-'a']++;
  }
  for(int i = 0; i < len; i++){
    if(c[s[i]-'a'] == 1){
      return i;
    }
  }
  return -1;
  
}

/****************************************************************************************/
int main() {
  char* s1 = malloc(sizeof(char)*8);
  char* s2 = malloc(sizeof(char)*12);
  char* s3 = malloc(sizeof(char)*4);
  s1[0] = 'l';
  s1[1] = 'e';
  s1[2] = 'e';
  s1[3] = 't';
  s1[4] = 'c';
  s1[5] = 'o';
  s1[6] = 'd';
  s1[7] = 'e';

  s2[0] = 'l';
  s2[1] = 'o';
  s2[2] = 'v';
  s2[3] = 'e';
  s2[4] = 'l';
  s2[5] = 'e';
  s2[6] = 'e';
  s2[7] = 't';
  s2[8] = 'c';
  s2[9] = 'o';
  s2[10] = 'd';
  s2[11] = 'e';
  
  s3[0]  = 'a';
  s3[1]  = 'a';
  s3[2]  = 'b';
  s3[3]  = 'b';
  printf("s1's first = %d\n",firstUniqChar(s1));
  printf("s1's first = %d\n",firstUniqChar(s2));
  printf("s1's first = %d\n",firstUniqChar(s3));
  return 0;
}
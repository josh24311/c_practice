/*
58. Length of Last Word
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal 
substring
 consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.
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



int lengthOfLastWord(char * s){
  //"Hello World"
  //"   fly me   to   the moon  "
  // "a "
  int len = strlen(s);
  if(len == 1) return len;
  int count = 0;
  bool hasWord = false;
  for(int i = len-1; i >= 0; i--){
    printf("i now : %d ",i);
    if(s[i] != ' '){
      printf("\nhasworld\n");
      hasWord = true;
      count++;
    }
    else{
      printf("\nfound space\n");
      if(hasWord){
        printf("has word already\n");
        return count;
      }
      else{
        printf("No word YET\n");
        continue;
      }
    }
    if(hasWord && i==0) return count;
  }
  
  return -1;
}

int main() {
  char* s1 = malloc(sizeof(char)*11);
  s1[0] = 'h';
  s1[1] = 'e';
  s1[2] = 'l';
  s1[3] = 'l';
  s1[4] = 'o';
  s1[5] = ' ';
  s1[6] = 'w';
  s1[7] = 'o';
  s1[8] = 'r';
  s1[9] = 'l';
  s1[10] = 'd';
  char* s2 = malloc(sizeof(char)*27);
  s2[0] = ' ';
  s2[1] = ' ';
  s2[2] = ' ';
  s2[3] = 'f';
  s2[4] = 'l';
  s2[5] = 'y';
  s2[6] = ' ';
  s2[7] = 'm';
  s2[8] = 'e';
  s2[9] = ' ';
  s2[10] = ' ';
  s2[11] = ' ';
  
  s2[12] = 't';
  s2[13] = 'o';
  s2[14] = ' ';
  s2[15] = ' ';
  s2[16] = ' ';
  s2[17] = 't';
  s2[18] = 'h';
  s2[19] = 'e';
  s2[20] = ' ';
  s2[21] = 'm';
  s2[22] = 'o';
  s2[23] = 'o';
  s2[24] = 'n';
  s2[25] = ' ';
  s2[26] = ' ';
  
  char* s3 = malloc(sizeof(char)*2);
  s3[0] = 'a';
  s3[1] = ' ';

  
  //printf("result 1 : %d\n",lengthOfLastWord(s1));
  //printf("result 2 : %d\n",lengthOfLastWord(s2));
  printf("result 3 : %d\n",lengthOfLastWord(s3));
  
  
  
  
  return 0;
}
/*
451. Sort Characters By Frequency
 Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 

Constraints:

1 <= s.length <= 5 * 10^5
s consists of uppercase and lowercase English letters and digits.
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
//利用全域變數存各char出現次數
int* globalCount;
// cmp function 回傳規則，若要結果array升序排列回傳*a-*b
//若要結果array降序排列回傳*b-*a
int cmp2(const char *a, const char *b){
  //diff : 出現次數以降序排列
  int diff = globalCount[*b] - globalCount[*a];
  if(diff==0){
    return (*a) - (*b);
  }
  return diff;
}

char * frequencySort(char * s){
// tree -> eetr 或 eert
  int len = strlen(s);
  int a = 0;
  globalCount = &a;
  //printf("len = %d\n",len);
  int count[128] = {0};
  for(int i = 0; i < len; i++){
    count[s[i]]++;
  }
  globalCount = count;
  
  qsort(s, len, sizeof(s[0]), cmp2);
  //printf("after qsort\n");
  
  return s;

}
/****************************************************************************************/
int main() {
  //char* s1 = "tree";
  //char* s2 = "cccaaa";
  //char* s3 = "Aabb";
  char* s1 = malloc(sizeof(char)*4);
  s1[0] = 't';
  s1[1] = 'r';
  s1[2] = 'e';
  s1[3] = 'e';
  char* s2 = malloc(sizeof(char)*6);
  s2[0] = 'c';
  s2[1] = 'c';
  s2[2] = 'c';
  s2[3] = 'a';
  s2[4] = 'a';
  s2[5] = 'a';
  char* s3 = malloc(sizeof(char)*4);
  s3[0] = 'A';
  s3[1] = 'a';
  s3[2] = 'b';
  s3[3] = 'b';
  char* ans1 = frequencySort(s1);
  char* ans2 = frequencySort(s2);
  char* ans3 = frequencySort(s3);
  for(int i = 0; ans1[i] != '\0'; i++){
    printf("%c",ans1[i]);
  }
  printf("\n");
  for(int i = 0; ans2[i] != '\0'; i++){
    printf("%c",ans2[i]);
  }
  printf("\n");
  for(int i = 0; ans3[i] != '\0'; i++){
    printf("%c",ans3[i]);
  }
  printf("\n");
  return 0;
}
/*
#DP
#cache
72. Edit Distance
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character


Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')


Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
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
int doMinDistance(char* word1, char* word2, int len1, int len2, int** cache){
  if(len1 == 0){
    /*
    word1 = []
    word2 = [B]
    */
    return len2;// 需要len2 次 insert
  }
  else if(len2 == 0){
    return len1; // 需要len1 次 insert
  }
  if(cache[len1][len2] != -1){//此長度組合有算過
    return cache[len1][len2];
  }
  if(word1[len1-1] == word2[len2-1]){
    cache[len1][len2] =  doMinDistance(word1, word2, len1-1, len2-1, cache);
    return cache[len1][len2];
  }
  else{
    // case1 replace
    /*
    word1 [A]x
    word2 [B]y
    */
    int replace = doMinDistance(word1, word2, len1-1, len2-1, cache) + 1;
    // case2 insert
    /*
    word1 [A]
    word2 [B]y
    */
    int insert = doMinDistance(word1, word2, len1, len2-1, cache) + 1;
    //case3 delete
    /*
    word1 [A]x
    word2 [B]
    */
    int del = doMinDistance(word1, word2, len1-1, len2, cache) + 1;
    cache[len1][len2]  = min3(replace, insert, del);
    return cache[len1][len2];
  }

}

int minDistance(char * word1, char * word2){
  int len1 = strlen(word1);
  int len2 = strlen(word2);
  int** cache = malloc(sizeof(int*)*(len1+1));
  for(int i = 0; i <= len1; i++ ){
    cache[i] = malloc(sizeof(int)*(len2+1));
    for(int j = 0; j <= len2; j++){
      cache[i][j] = -1;
    }
  }
  
  return doMinDistance(word1, word2, strlen(word1), strlen(word2), cache);
}
/***************************************************************/

int main() {
  
  char word1[] = "horse"; 
  char word2[] = "ros";
  char word3[] = "intention";
  char word4[] = "execution";
  printf("ans1 = %d\n",minDistance(word1, word2));
  printf("ans2 = %d\n",minDistance(word3, word4));
    
  
  return 0;
}
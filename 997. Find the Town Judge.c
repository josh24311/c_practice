/*
997. Find the Town Judge
In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

Example 1:

Input: n = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
Constraints:

1 <= n <= 1000
0 <= trust.length <= 104
trust[i].length == 2
All the pairs of trust are unique.
ai != bi
1 <= ai, bi <= n
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
int treeHeight(struct TreeNode* root){
  if(root == NULL) return 0;
  else{
    int lh = treeHeight(root->left);
    int rh = treeHeight(root->right);
    return max(lh, rh)+1;
  }
}
/****************************************************************************************/
int findJudge(int n, int** trust, int trustSize, int* trustColSize){
  // [1,3] [2,3] 
  int trusts[n+1] ; // trusts[i] :i相信的人數
  int trusted[n+1] ;// trusted[i] :相信i的人數
  for(int i = 0; i < n+1; i++){
    trusts[i] = 0;
    trusted[i] = 0;
  }
  for(int i = 0; i < trustSize; i++){
    trusts[trust[i][0]]++;
    trusted[trust[i][1]]++;
  }
  for(int i = 1; i <= n ;i++){
    if(trusts[i] == 0 && trusted[i] == n-1){
      return i;
    }
  }
  
  return -1;
}

/****************************************************************************************/
int main() {
  int a = 0;
  int *trustColSize = &a;
  int** ts = malloc(sizeof(int*)*2);
  for(int i = 0;  i < 2; i++){
    ts[i] = malloc(sizeof(int)*2);
  }
  ts[0][0] = 1;
  ts[0][1] = 3;
  ts[1][0] = 2;
  ts[1][1] = 3;
  int ans = findJudge(3, ts, 2, trustColSize);
  printf("judge is %d\n",ans);

  int** ts2 = malloc(sizeof(int*)*3);
  for(int i = 0;  i < 3; i++){
    ts2[i] = malloc(sizeof(int)*2);
  }
  
  
  ts2[0][0] = 1;
  ts2[0][1] = 3;
  ts2[1][0] = 2;
  ts2[1][1] = 3;
  ts2[2][0] = 3;
  ts2[2][1] = 1;
  int ans2 = findJudge(3, ts2, 3, trustColSize);
  printf("judge is %d\n",ans2);
  return 0;
}
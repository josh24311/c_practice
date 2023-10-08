/*
graphic

886. Possible Bipartition
We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

Example 1:

Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: The first group has [1,4], and the second group has [2,3].
Example 2:

Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Explanation: We need at least 3 groups to divide them. We cannot put them in two groups.
 

Constraints:

1 <= n <= 2000
0 <= dislikes.length <= 104
dislikes[i].length == 2
1 <= ai < bi <= n
All the pairs of dislikes are unique.
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
bool possibleBipartition(int n, int** dislikes, int dislikesSize, int* dislikesColSize){
  if(dislikesSize == 0)return true;
  int label[n+1];// label[i] 表示第i個人所在隊伍，第一隊值為-1，第二隊值為1
  //題目及轉化為，是否有一組label填入方式使其滿足dislikes 關係式
  for(int i = 0; i <= n; i++){
    label[i] = 0;// i = 1~n label[i]表示i所在隊伍, default 0表示尚未被分隊
  }
  
  bool ischecked[dislikesSize];
  for(int i = 0; i < dislikesSize; i++){//所有關係式尚未被檢查
    ischecked[i] = false;
  }
  
  int x = dislikes[0][0];
  int y = dislikes[0][1];
  label[x] = -1;  //將x分隊
  label[y] = 1;   //將y分隊 (x的另一隊)
  ischecked[0] = true;//第一組關係已被檢查

  while(1){
    bool isUpdated = false;//此輪是否有人被分隊
    for(int i = 1; i < dislikesSize; i++){
      if(ischecked[i] == true){//第i組關係已被檢查
        continue;
      }
      x = dislikes[i][0];//關係主角1
      y = dislikes[i][1];//關係主角2
      if(label[x] == 0 && label[y] == 0){
        continue;//x , y 的隊伍都尚未被先前的關係式決定 , 此時先尋找其他關係式
      }
      else if (label[x] != 0 && label[y] != 0){//x , y 兩者的隊伍都已被先前的關係式決定
        if(label[x] == label[y]){
          //若先前x , y 已被分在同一隊, 此時又要滿足 x 討厭 y的關係式 return false
          return false;
        }
        else{//x , y 不同隊
          ischecked[i] = true;// 第i組關係式被決定
        }
      }
      else if (label[x] != 0 && label[y] == 0){//x 已被分隊 y未被分隊
        label[y] = -label[x];//將y分到  x的另一隊
        ischecked[i] = true;
        isUpdated = true;//此輪有人被分隊
      }
      else if (label[x] == 0 && label[y] != 0){//y 已被分隊 x未被分隊
        label[x] = -label[y];//將x分到  y的另一隊
        ischecked[i] = true;
        isUpdated = true;//此輪有人被分隊
      } 
    }//for
  
    bool isAllChecked = true;//是否所有關係式都被檢查過?
    for(int i  = 1; i < dislikesSize; i++){
      if(ischecked[i] == false){
        isAllChecked = false;
        break;
      }
    }
    if(isAllChecked) return true;// 所有關係式都被檢查過且所有label[] 都被for安排完了
    if(isAllChecked == false && isUpdated == false){//尚有關係式未被檢查 且 此輪 沒有人被分隊
      //往下找其他未被檢查的關係式 , 再行分隊
      for(int i = 1; i < dislikesSize; i++){
        if(ischecked[i] == false){
          x = dislikes[i][0];
          y = dislikes[i][1];
          label[x] = -1;
          label[y] = 1;
          ischecked[i] = true;
          break;//找到一組即break
        }
      }
    }
  }//while
  
  return false;
}//func

/***************************************************************/
int main() {
  int a = 2;
  int* dislikesColSize = &a;
  int** gr1 = malloc(sizeof(int*)*3);
  for(int i = 0; i < 3; i++){
    gr1[i] = malloc(sizeof(int)*2); 
  }
  gr1[0][0] = 1;
  gr1[0][1] = 2;
  gr1[1][0] = 1;
  gr1[1][1] = 3;
  gr1[2][0] = 2;
  gr1[2][1] = 4;
  printf("ans1 = %s\n",possibleBipartition(4, gr1, 3, dislikesColSize)?"True":"False");
  int** gr2 = malloc(sizeof(int*)*3);
  for(int i = 0; i < 3; i++){
    gr2[i] = malloc(sizeof(int)*2); 
  }
  gr2[0][0] = 1;
  gr2[0][1] = 2;
  gr2[1][0] = 1;
  gr2[1][1] = 3;
  gr2[2][0] = 2;
  gr2[2][1] = 3;
  printf("ans2 = %s\n",possibleBipartition(3, gr2, 3, dislikesColSize)?"True":"False");
  return 0;
}
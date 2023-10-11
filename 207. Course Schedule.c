/*
#Topological Sorting
#graphic

207. Course Schedule
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.

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
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
  /*
  ex: 
  numCourses = 3;
  prerequisites = [[0,1], [1,0], [0,2]]
  */
  int preCourse[numCourses];
  for(int i = 0; i < numCourses; i++){
    preCourse[i] = 0;
  }
  for(int i = 0; i < prerequisitesSize; i++){
    preCourse[prerequisites[i][0]]++;
  }
  int tmp;
  
  while(1){
    for(tmp = 0; tmp < numCourses; tmp++){
      if(preCourse[tmp] == 0){
        preCourse[tmp] = -1;
        for(int j = 0; j < prerequisitesSize; j++){
          if(prerequisites[j][1] == tmp){
            preCourse[prerequisites[j][0]]--;
          }
        }
      }
    }
    bool allChecked = true;
    for(int i = 0; i < numCourses; i++){
      if(preCourse[i] != -1){
        allChecked = false;
      }
    }
    if(allChecked)return true;

    bool hasZero = false;
    for(int i = 0 ; i < numCourses; i++){
      if(preCourse[i] == 0){
        hasZero = true;
      }
    }
    if(hasZero == false)return false;
  }
  
}

/***************************************************************/

int main() {
  int s = 1;
  int *p = &s;
  int** arr1 = malloc(sizeof(int*));
  arr1[0] = malloc(sizeof(int)*2);
  arr1[0][0] = 0;
  arr1[0][1] = 1;
  printf("%s\n",canFinish(2, arr1, 1, p)?"True":"False");
  int** arr2 = malloc(sizeof(int*)*2);
  arr2[0] = malloc(sizeof(int)*2);
  arr2[1] = malloc(sizeof(int)*2);
  arr2[0][0] = 1;
  arr2[0][1] = 0;
  arr2[1][0] = 0;
  arr2[1][1] = 1;
  s = 2;
  printf("%s\n",canFinish(2, arr2, 2, p)?"True":"False");
  return 0;
}
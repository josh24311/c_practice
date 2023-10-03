/*
#stack
#string
#strtok
71. Simplify Path

Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

The canonical path should have the following format:

The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
Return the simplified canonical path.

 

Example 1:

Input: path = "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
Example 2:

Input: path = "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
Example 3:

Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
 

Constraints:

1 <= path.length <= 3000
path consists of English letters, digits, period '.', slash '/' or '_'.
path is a valid absolute Unix path.

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
/***************************************************************************/
char * simplifyPath(char * path){
  char *stack[100];
  int size = 0;
  for(char *s = strtok(path, "/"); s; s = strtok(NULL, "/")){
    if(strcmp(s,".") == 0){
      
    }
    else if (strcmp(s, "..") == 0){
      size = fmax(0, size-1);
    }
    else{
      stack[size++] = s;
    }
  }
  if(size == 0) return "/";
  char* res = calloc(1000, sizeof(char));
  for(int i = 0; i < size; i++){
    strcat(res, "/");
    strcat(res, stack[i]);
  }
  return res;
}


/***************************************************************************/
int main() {
  char* a1 = malloc(sizeof(char)*6);
  char* a2 = malloc(sizeof(char)*4);
  char* a3 = malloc(sizeof(char)*11);
  char* a4 = malloc(sizeof(char)*18);
  char* ans = malloc(sizeof(char)*5);
  /*
  a1[0] = '/';
  a1[1] = 'h';
  a1[2] = 'o';
  a1[3] = 'm';
  a1[4] = 'e';
  a1[5] = '/';
  ans = simplifyPath(a1);
  for(int i = 0; i < 5 ; i++){
    printf("%c",ans[i]);
  }
  printf("\n");
  a2[0] = '/';
  a2[1] = '.';
  a2[2] = '.';
  a2[3] = '/';
  ans = realloc(ans, sizeof(char)*1);
  ans = simplifyPath(a2);
  for(int i = 0; i < 1 ; i++){
    printf("%c",ans[i]);
  }
  printf("\n");
  a3[0] = '/';
  a3[1] = 'h';
  a3[2] = 'o';
  a3[3] = 'm';
  a3[4] = 'e';
  a3[5] = '/';
  a3[6] = '/';
  a3[7] = 'f';
  a3[8] = 'o';
  a3[9] = 'o';
  a3[10] = '/';
  ans = realloc(ans, sizeof(char)*9);
  ans = simplifyPath(a3);
  for(int i = 0; i < 9 ; i++){
    printf("%c",ans[i]);
  }
  */
  printf("\n");
  a4[0] = '/';
  a4[1] = 'a';
  a4[2] = '/';
  a4[3] = 's';
  a4[4] = '/';
  a4[5] = '.';
  a4[6] = '.';
  a4[7] = '/';
  a4[8] = '.';
  a4[9] = '/';
  a4[10] = 'j';
  a4[11] = 'a';
  a4[12] = 'v';
  a4[13] = 'a';
  a4[14] = '.';
  a4[15] = 't';
  a4[16] = 'x';
  a4[17] = 't';
  
  ///a/s/.././java.txt
  
  printf("%s\n",simplifyPath(a4));
  printf("\n");
  return 0;
}
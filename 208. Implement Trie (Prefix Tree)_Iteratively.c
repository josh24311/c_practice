/*
208. Implement Trie (Prefix Tree)_Iteratively
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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
/****************************************************************************************/
//new struct ,consist only of lowercase English letters.
typedef struct Node_ {
  struct Node_* children['z'-'a'+1];
  bool isEnd;
} Node;

typedef struct {
  Node* root;
} Trie;


Trie* trieCreate() {
  Trie* trie = calloc(1,sizeof(Trie));
  trie->root = calloc(1,sizeof(Node));
  return trie;
}

void trieInsert(Trie* obj, char * word) {
    Node* curr = obj->root;
    for(int i = 0; word[i] != '\0'; i++){
        int index = word[i]-'a';
        if(curr->children[index] == NULL){
            curr->children[index] = calloc(1, sizeof(Node));
        }  
        curr = curr->children[index];
    }
    curr->isEnd = true;
}


bool trieSearch(Trie* obj, char * word) {
    Node* curr = obj->root;
    int i;
    for(i = 0; word[i] != '\0'; i++){
        int index = word[i]-'a';
        if(curr->children[index] == NULL){
            //找不到對應index的children表示沒有對應字串
            return false;
        }
        curr = curr->children[index];
    }
    return curr->isEnd;
}

bool trieStartsWith(Trie* obj, char * prefix) {
    Node* curr = obj->root;
    for(int i = 0; prefix[i] != '\0'; i++){
        int index = prefix[i]-'a';
        if(curr->children[index] == NULL){
             return false;
        }
        curr = curr->children[index];
    }
    return true;
}
void nodeFree(Node* root){
  if(root == NULL)return;
  
  for(char c = 'a'; c <= 'z'; c++){
    int index = c-'a';
    nodeFree(root->children[index]);
  }
  free(root);
  
}
void trieFree(Trie* obj) {
  
  nodeFree(obj->root);
  free(obj);
}

/****************************************************************************************/
int main() {
  
  
  return 0;
}
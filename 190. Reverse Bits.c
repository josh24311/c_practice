/*
190. Reverse Bits
Reverse bits of a given 32 bits unsigned integer.

Note:
Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.
 
Example 1:

Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.
Example 2:

Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.
 
Constraints:

The input must be a binary string of length 32
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
/*
1.
假設n = ab   兩bit
對調ab操作為:
a >> 1 | b << 1
精確來說為
(n&0b10) >> 1 | (n&0b01) << 1 

2.
假設 n = abcd
使用上述操作(改為移動2bit)後
n = cdab , 此時將n看成左右兩半cd 和 ab 各自再去做1. 的操作，即為本題所求 => dcba

3.
在32bit下，左右兩bit互換的mask為
// ((n & 0b10101010101010101010101010101010) >> 1) | ((n&01010101010101010101010101010101)<<1)
*/
int32_t reverseBits(uint32_t n) {
  n = (n>> 16) | (n<<16);
  n = ( ((n&0xff00ff00) >> 8) | ((n&0x00ff00ff)<<8) );
  // ((n & 0b11111111000000001111111100000000) >> 8) | ((n&00000000111111110000000011111111)<<8)
  n = ( ((n&0xf0f0f0f0) >> 4) | ((n&0x0f0f0f0f)<<4) );
  // ((n & 0b11110000111100001111000011110000) >> 4) | ((n&00001111000011110000111100001111)<<4)
  n = ( ((n&0xcccccccc) >> 2) | ((n&0x33333333)<<2) );
  // ((n & 0b11001100110011001100110011001100) >> 2) | ((n&00110011001100110011001100110011)<<2)
  n = ( ((n&0xaaaaaaaa) >> 1) | ((n&0x55555555)<<1) );
  // ((n & 0b10101010101010101010101010101010) >> 1) | ((n&01010101010101010101010101010101)<<1)
  return n;
}


/****************************************************************************************/
int main() {
  uint32_t a;
  a = 43261596;
  //printf("%d",a);
  printf("%d",reverseBits(a));
  
  return 0;
}
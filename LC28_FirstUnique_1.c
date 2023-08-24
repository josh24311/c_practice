/*
LC28_First Unique Number(Method1 TLE)
LeetCode] 1429. First Unique Number
You have a queue of integers, you need to retrieve the first unique integer in the queue.

Implement the FirstUnique class:

FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
int showFirstUnique() returns the value of the first unique integer of the queue, and returns -1 if there is no such integer.
void add(int value) insert value to the queue.
Example 1:

Input: 
["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]
[[[2,3,5]],[],[5],[],[2],[],[3],[]]
Output: 
[null,2,null,2,null,3,null,-1]
Explanation: 
FirstUnique firstUnique = new FirstUnique([2,3,5]);
firstUnique.showFirstUnique(); // return 2
firstUnique.add(5);            // the queue is now [2,3,5,5]
firstUnique.showFirstUnique(); // return 2
firstUnique.add(2);            // the queue is now [2,3,5,5,2]
firstUnique.showFirstUnique(); // return 3
firstUnique.add(3);            // the queue is now [2,3,5,5,2,3]
firstUnique.showFirstUnique(); // return -1


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
  if(a >= b) return a;
  else return b;
}
int min3(int a, int b, int c){
  int m = a;
  if(b < m){
    m = b;
  }
  if(c < m){
    m = c;
  }
  return m;
}

#define CAPACITY (100000+50000)

typedef struct{
  int data[CAPACITY];
  int size;

} FirstUnique;
void firstUniqueAdd(FirstUnique* obj, int value){
  obj->data[obj->size] = value; //obj->size 代表可以新增的位置編號
  obj->size++;
}
FirstUnique* firstUniqueCreate(int* nums, int numsSize){
  // 配置1 obj
  FirstUnique* obj = calloc(1, sizeof(FirstUnique));
  for(int i = 0; i < numsSize; i++){
    firstUniqueAdd(obj, nums[i]);
  }
  return obj;
}

int firstUniqueShowFirstUnique(FirstUnique* obj){
  for(int i = 0; i < obj->size; i++){
    bool isUnique = true;
    for(int j = 0; j < obj->size; j++){
      if(i != j && obj->data[i] == obj->data[j]){
        // index 不同,值相同, 此時該值不唯一
        isUnique = false;
        break;
      }
    }
    if(isUnique){
      // 皆無重複
      return obj->data[i];
    }
  }
  
  
  return -1;
}

void firstUniqueFree(FirstUnique* obj){
  free(obj);
}


int main() {
  int nums[3] = {2, 3, 5};
  FirstUnique* obj = firstUniqueCreate(nums, 3);
  printf("%d\n",firstUniqueShowFirstUnique(obj));
  firstUniqueAdd(obj, 5);
  printf("%d\n",firstUniqueShowFirstUnique(obj));
  firstUniqueAdd(obj, 2);
  printf("%d\n",firstUniqueShowFirstUnique(obj));
  firstUniqueAdd(obj, 3);
  printf("%d\n",firstUniqueShowFirstUnique(obj));


  
  return 0;
}
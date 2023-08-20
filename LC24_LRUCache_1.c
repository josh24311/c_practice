/*
LC24_LRU Cache

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example 1:
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int min(int a, int b){
  if(a<b) return a;
  else return b;
}

struct Entry{
  int key;
  int value;
  int priority;
};

typedef struct {
  struct Entry* entries;
  int capacity;
  int currentPriority;
    
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* obj = malloc(sizeof(LRUCache));
    obj->entries = calloc(capacity, sizeof(struct Entry));
    obj->capacity = capacity;
    obj->currentPriority = 0;
    for(int i = 0; i < capacity; i++){
      obj->entries[i].key = -1;
    }
    return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
  //有
  for(int i = 0; i < obj->capacity; i++){
    if(obj->entries[i].key == key){
      obj->currentPriority++;
      obj->entries[i].priority = obj->currentPriority;
      return obj->entries[i].value;
    }
  }
  //沒有
  return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
  // 原本就有該key : 覆蓋其value做取代
  for(int i = 0; i < obj->capacity; i++){
    if(obj->entries[i].key == key){
      obj->entries[i].value = value;
      obj->currentPriority++;
      obj->entries[i].priority = obj->currentPriority;
      return;
    }
  }
  // 原本沒有該key : 
  //  capacity還沒滿 : 該鍵值組新增在空格(原key為-1者)
  for(int i = 0; i < obj->capacity; i++){
    if(obj->entries[i].key == -1){
      obj->entries[i].key = key;
      obj->entries[i].value = value;
      obj->currentPriority++;
      obj->entries[i].priority = obj->currentPriority;
      return;
    }
  }
  
  //  capacity已經滿 : 取代priority較低的鍵值組(代表較舊)
  int minI = 0;
  for(int i = 1; i < obj->capacity; i++){
    if(obj->entries[i].priority < obj->entries[minI].priority){
      minI = i;
    }
  }
  obj->entries[minI].key = key;
  obj->entries[minI].value = value;
  obj->currentPriority++;
  obj->entries[minI].priority = obj->currentPriority;
  return;
  
}

void lRUCacheFree(LRUCache* obj) {
    free(obj->entries);
    free(obj);
}



int main() {
  LRUCache *lruCache = lRUCacheCreate(2);
  lRUCachePut(lruCache,1,1);
  lRUCachePut(lruCache,2,2);
  printf("%d \n",lRUCacheGet(lruCache,1));
  lRUCachePut(lruCache,3,3);
  printf("%d \n",lRUCacheGet(lruCache,2));
  lRUCachePut(lruCache,4,4);
  printf("%d \n",lRUCacheGet(lruCache,1));
  printf("%d \n",lRUCacheGet(lruCache,3));
  printf("%d \n",lRUCacheGet(lruCache,4));
 

  
  
  
  return 0;
}
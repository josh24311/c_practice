/*
380. Insert Delete GetRandom O(1)
Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). 
Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.

 

Example 1:

Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output
[null, true, false, true, 2, true, false, 2]

Explanation
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
randomizedSet.insert(2); // 2 was already in the set, so return false.
randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.
 

Constraints:

-2^31 <= val <= 2^31 - 1
At most 2 * 10^5 calls will be made to insert, remove, and getRandom.
There will be at least one element in the data structure when getRandom is called.
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>

using namespace std;

int cmp(const void* pa, const void* pb )// need include cstdlib
{
    const int *a = (int*)pa;
    const int *b = (int*)pb;
    if (*a > *b) 
        return 1;
    else if (*a < *b)
        return -1;

    return 0;
}

class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        auto res = h.emplace(val, arr.size());
        if (!res.second) return false;//iterater res 的 second 為true表示真的有插入新資料
        arr.push_back(val);
        return true;
    }
    
    bool remove(int val) {//重點, 換, 把最後一個元素搬到被刪除的位置: 先更新 map 中它的 index, 再 erase val
        int index, last;
        auto it = h.find(val);
        if (it == h.end()) return false;
        index = it->second;//{8:0, 5:1, 4:2, 6:3} , 假設要刪除 val = 5 , 則index = 1
        last = arr.back();//6
        h[last] = index;//更新 map {8:0, 5:1, 4:2, 6:1} 
        h.erase(val);//{8:0, 4:2, 6:1}
        arr[index] = last;//更新vector
        arr.pop_back();
        return true;
    }
    
    int getRandom() {
        int pick = rand()%(arr.size());
        return arr[pick];
    }
private:
    unordered_map<int, int> h;
    vector<int> arr;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() 
{
    
    //vector<int> a = {1,2,3,0,0,0};
    //int r = 0;
    RandomizedSet *obj = new RandomizedSet();
    bool f;
    int num;
    f = obj->insert(1);
    cout << "f = " << f << endl;
    f = obj->remove(2);
    cout << "f = " << f << endl;
    f = obj->insert(2);
    cout << "f = " << f << endl;
    num = obj->getRandom();
    cout << "num = " << num << endl;
    f = obj->remove(1);
    cout << "f = " << f << endl;
    f = obj->insert(2);
    cout << "f = " << f << endl;
    num = obj->getRandom();
    cout << "num = " << num << endl;
    //for(int element:a){
     //   cout<<element<<" ";
    //}
    return 0;
}

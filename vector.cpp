#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


int main() {
  int xx[] = {1974, 94, 689, 92};
  vector<int> fuc (xx, xx+sizeof(xx)/sizeof(int));
  for(int x: fuc){
    cout << x << endl;
  }
  cout << "---" << endl;
  vector<int> v1 = {1, 2, 3, 4, 5};
  vector<int> v2(v1.begin()+2, v1.end()-1); // {3, 4}
  cout << "v2 begin: " << *v2.begin() << endl;
  cout << "v2 end: " << *v2.end() << endl;
  cout << "v2 end-1: " << *(v2.end()-1) << endl;
  cout << "---" << endl;
  for(int x: v2){
    cout << x << endl;
  }
  cout << "---" << endl;
  vector<int> v = {1, 2, 3};
  v.push_back(4); // {1, 2, 3, 4}
  v.push_back(5); // {1, 2, 3, 4, 5}
  for(int x: v){
    cout << x << endl;
  }
  cout << "---" << endl;

  //定义一个普通数组
  int arr[] = { 7,8,9,10,11 };
  //创建一个空 vector 容器
  vector<int> myvector;
  //将数组中的元素添加到 myvector 容器中存储
  for (int *it = begin(arr); it != end(arr); ++it)
      myvector.push_back(*it);
  //输出 myvector 容器中存储的元素
  for (auto it = myvector.begin(); it != myvector.end(); ++it)
      cout << *it << ' ';
  cout <<"\n---" <<"\n";
  vector<int> vec({1, 2, 3});
  for (auto &v : vec) {
      cout << v << " ";
  }
  cout <<"\n---" <<"\n";
  cout << "size=" << vec.size() << ", capacity=" << vec.capacity() << "\n";
  int n = 3;
  int m = 4;
  vector<int> row;
  row.assign(n, 0);
  vector<vector<int>> x;
  x.assign(m, row);
  
  return 0;
  
  
}
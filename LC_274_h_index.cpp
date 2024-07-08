#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution
{
public:
  int hIndex (vector < int >&citations) {
    int n = citations.size();
    /*
    // method 1 O: nlogn
    int h = 0;
    //cout << "n: " << n <<endl;
    sort(citations.begin(), citations.end(), greater<int>());//6 5 3 1 0
    for(int i = 0; i < n; i++) {
        if (citations[i] > i) {
            h++;
        }
    }
    return h;
    */
    // method 2  O:n
    vector<int> bucket(n+1, 0);//n篇paper中有某篇被引用洽min(i, n)次
    int h = 0;
    bucket[0] = 0;
    for(int citation: citations) {// 3 0 6 1 5
      bucket[min(citation, n)]++; //  b[1] = 1, b[2] = 0, b[3] = 1, b[4] = 0, b[5] = 2
    }

    cout << endl;
    for(int i = n; i >= 0; i--) {
      h += bucket[i];
      if(h >= i) {
        return i;
      }
    }
    return 0;
  }

   
};

/***************************************************************/

int
main ()
{
  Solution s;
  vector < int >input1 = { 3, 0, 6, 1, 5 };// 0 1 3 5 6
  cout << "ans1 " << s.hIndex (input1) << endl;
  vector < int >input2 = { 1, 3, 1 }; // 1 1 3
  cout << "ans2 " << s.hIndex (input2) << endl;
  return 0;
}
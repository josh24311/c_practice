/*
Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper,
return the researcher's h-index.
According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that 
the given researcher has published at least h papers that have each been cited at least h times.
Example 1:

Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.
*/
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
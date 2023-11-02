/*
#Sieve of Eratosthenes
204. Count Primes
Given an integer n, return the number of prime numbers that are strictly less than n.

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0

Constraints:

0 <= n <= 5 * 106

时间复杂度：

在构建布尔向量 isPrime 时，我们将所有元素初始化为 true，这需要 O(n) 的时间。
在筛选非质数时，我们从 2 开始，逐步标记非质数，如果某个数字 i 被标记为非质数，那么从 i^2 开始的所有倍数都会被标记，因此标记非质数的操作需要 O(n/2 + n/3 + n/4 + ...) 的时间。这等于 O(n * (1/2 + 1/3 + 1/4 + ...))，而级数 1/2 + 1/3 + 1/4 + ... 是调和级数，它大致接近于 ln(n)。因此，筛选非质数的操作需要 O(n * ln(n)) 的时间。
统计质数的数量需要遍历 isPrime 向量，这需要 O(n) 的时间。
综上所述，总的时间复杂度为 O(n * ln(n))。

空间复杂度：

使用一个布尔向量 isPrime 来存储每个数字是否为质数，它占用 O(n) 的额外空间。
其他变量和迭代变量所占用的空间很小，可以忽略不计。
综上所述，总的空间复杂度为 O(n)。
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <numeric>
#include <string>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// ---------------------------------------

class Solution {
public:
    int countPrimes(int n) {
      if(n <= 2) return 0;
      vector<bool> isPrime(n, true);//預設n個都是質數
      isPrime[0] = false;
      isPrime[1] = false;
      for(int i = 2; i*i < n; i++){// i試到根號n為止
        if(isPrime[i]){// 若為質數
          for(int j = i * i; j < n; j+=i){// j 從 i平方開始, 每個i的倍數都不是質數
            /*
            j = i*i
            j = i*i + i
            j = i*i + 2i
            */
            isPrime[j] = false;
          }
        }
      }

      int count = 0;
      for(int i = 2; i < n; i++){
        if(isPrime[i]){
          count++;
        }
      }
      return count;
    }
};


// ---------------------------------------
int main() {
  Solution s;
  int n = 10;
  int result = s.countPrimes(n);
  cout << "Prime num less than "<< n << "\tis\t:\t"<< result << endl;
  n = 100;
  result = s.countPrimes(n);
  cout << "Prime num less than "<< n << "\tis\t:\t"<< result << endl;
  return 0;
  
  
}
/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

Constraints:
-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/
#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;
class MinStack {
public:
    MinStack() {
      min = INT_MAX;
    }
    //多push 和 多pop 一次的情況只發生在當前最小值需要更動時
    void push(int val) {
      if (val <= min) {
        stk.push(min);//再push一次當前最小值
        min = val;//更新當前最小值
      }
      stk.push(val);
    }
    
    void pop() {
      if (stk.top() == min) {//若當前top恰好為min
        stk.pop();//先pop 
        min = stk.top();  //更新當前最小值
        stk.pop();//則再pop一次
      } else {
        stk.pop();//pop一次
      }
    }
    
    int top() {
      return stk.top();
    }
    
    int getMin() {
      return min;
    }
private:
    stack<int> stk;
    int min;    
};
int main() 
{
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    int p1 = obj->getMin();
    obj->pop();
    int p2 = obj->top();
    int p3 = obj->getMin();
    cout << p1 << " " << p2 << "" << p3 << endl;
    return 0;
}
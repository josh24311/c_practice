#include <iostream>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> stackData;

public:
    // 推入元素到堆疊
    void push(const T& item) {
        stackData.push_back(item);
    }

    // 彈出堆疊頂部元素
    void pop() {
        if (!isEmpty()) {
            stackData.pop_back();
        } else {
            std::cerr << "Stack is empty. Cannot pop." << std::endl;
        }
    }

    // 獲取堆疊頂部元素
    T top() {
        if (!isEmpty()) {
            return stackData.back();
        } else {
            std::cerr << "Stack is empty. No top element." << std::endl;
            return T(); // 返回默認值，這取決於T的類型
        }
    }

    // 檢查堆疊是否為空
    bool isEmpty() const {
        return stackData.empty();
    }
};

int main() {
    Stack<int> myStack;

    // 推入元素到堆疊
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // 彈出堆疊頂部元素
    myStack.pop();

    // 獲取和輸出堆疊頂部元素
    if (!myStack.isEmpty()) {
        int topElement = myStack.top();
        std::cout << "Top element: " << topElement << std::endl;
    } else {
        std::cout << "Stack is empty." << std::endl;
    }

    return 0;
}
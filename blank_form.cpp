#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

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



int main() 
{
    Solution s;
    vector<int> a = {1,2,3,0,0,0};
    int r = 0;
    cout << "r = " << r << endl;
    for(int element:a){
        cout<<element<<" ";
    }
    return 0;
}

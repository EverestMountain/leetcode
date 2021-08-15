#include<iostream>
#include<queue>

using namespace std;

//c++中的priority_queue是一个大顶堆
int main() {
    std::priority_queue<int> mypq;
    int sum(0);
    for (int i = 1; i <= 10; i++) mypq.push(i);
    while (!mypq.empty()) {
        sum += mypq.top();
        cout << sum << endl;
        mypq.pop();
    }
    std::cout << "total: " << sum << '\n';
    return 0;
}

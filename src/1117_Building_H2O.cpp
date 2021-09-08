#include<functional>
#include<iostream>
#include<thread>
#include<condition_variable>
#include<mutex>
#include<vector>

using namespace std;

class H2O {
    int count = 0;

public:
    H2O() {

    }

    void hydrogen(function<void()> releaseHydrogen) {

        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
    }

    void oxygen(function<void()> releaseOxygen) {

        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
    }
};

//题目链接:https://leetcode.com/problems/building-h2o/
void releaseH() {
    std::cout << "H" << std::endl;
}

void releaseO() {
    std::cout << "O" << std::endl;
}

int main() {
    H2O h2o;
    vector<thread> ts;
    string water = "HOH";
    for (auto &ele:water) {
        if (ele == 'H') {
            ts.push_back(thread(&H2O::hydrogen, h2o, releaseH));
        } else {
            ts.push_back(thread(&H2O::oxygen, h2o, releaseO));
        }
    }
    for (auto &t:ts) {
        t.join();
    }
//    h2o.hydrogen(releaseH);
//    h2o.hydrogen(releaseO);
//    h2o.hydrogen(releaseH);
    return 0;
}
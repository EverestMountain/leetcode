#include<functional>
#include<thread>
#include<vector>
#include<iostream>
#include<mutex>

using namespace std;

class DiningPhilosophers {
    mutex forks[5];
public:
    DiningPhilosophers() {
    }

    void wantsToEat(int i,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        if (i % 2 == 0) {
            forks[i].lock();
            forks[(i + 1) % 5].lock();
            pickLeftFork();
            pickRightFork();
        } else {
            forks[(i + 1) % 5].lock();
            forks[i].lock();
            pickLeftFork();
            pickRightFork();
        }
//        printf("%d eat...\n", i);
        eat();
        putLeftFork();
        putRightFork();
        forks[i].unlock();
        forks[(i+1)%5].unlock();
    }
};

void pickLeftFork() {}

void pickRightFork() {}

void eat() {}

void putLeftFork() {}

void putRightFork() {}
//[题目🔗](https://leetcode.com/problems/the-dining-philosophers/)
int main() {
    DiningPhilosophers dp;
    vector<thread> ts;
    for (int i = 0; i < 5; i++) {
        ts.emplace_back(&DiningPhilosophers::wantsToEat, &dp, i, pickLeftFork, pickRightFork, eat, putLeftFork,
                        putRightFork);
    }
    for (auto &t:ts)
        t.join();

    return 0;
}
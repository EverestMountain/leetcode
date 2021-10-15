#include<vector>
#include<iostream>

using namespace std;

class MyCircularQueue {
    vector<int> a;
    int f, r, N, n;
public:
    MyCircularQueue(int k) {
        a = vector<int>(k);
        f = 0, r = 0, N = k, n = 0;
    }

    bool enQueue(int value) {
        if (n == N) return false;
        a[r] = value;
        r = (r + 1) % N;
        n++;
        return true;
    }

    bool deQueue() {
        if (n == 0) return false;
        f = (f + 1) % N;
        n--;
        return true;
    }

    int Front() {
        if (n == 0) return -1;
        return a[f];
    }

    int Rear() {
        if (n == 0) return -1;
        return a[(r - 1 + N) % N];
    }

    bool isEmpty() {
        return n == 0;
    }

    bool isFull() {
        return n == N;
    }
};

int main() {
    MyCircularQueue circularQueue = MyCircularQueue(3);
    cout << circularQueue.enQueue(1) << endl;
    cout << circularQueue.enQueue(2) << endl;
    cout << circularQueue.enQueue(3) << endl;
    cout << circularQueue.enQueue(4) << endl;
    cout << circularQueue.Rear() << endl;
    cout << circularQueue.isFull() << endl;
    cout << circularQueue.deQueue() << endl;
    cout << circularQueue.enQueue(4) << endl;
    cout << circularQueue.Rear() << endl;
    return 0;
}

/// **
//*
//Your
//        MyCircularQueue
//object
//        will
//be
//        instantiated
//and
//called as
//such:
//*
//MyCircularQueue *obj = new
//        MyCircularQueue(k);
//*
//bool
//        param_1 = obj->enQueue(value);
//*
//bool
//        param_2 = obj->deQueue();
//*
//int
//        param_3 = obj->Front();
//*
//int
//        param_4 = obj->Rear();
//*
//bool
//        param_5 = obj->isEmpty();
//*
//bool
//        param_6 = obj->isFull();
//* /
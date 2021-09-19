#include<vector>
#include<iostream>

using namespace std;

template<typename T>
void print_vector(vector<T> &v) {
    size_t n = v.size();
    for (auto x: v)
        cout << x << " ";
    cout << endl;
}

template<typename T>
void print_matrix(vector<T> &m) {
    for (auto &r: m)
        print_vector(r);
}

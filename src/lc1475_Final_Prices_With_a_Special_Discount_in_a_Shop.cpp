#include<vector>
#include<stack>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int> &a) {
        stack<int> st;
        int n = a.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            while ((!st.empty()) and (a[st.top()] >= a[i])) {
                res[st.top()] = a[st.top()] - a[i];
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            res[st.top()] = a[st.top()];
            st.pop();
        }
        return res;
    }
};

int main() {
    vector<int> prices = {8, 4, 6, 2, 3};
    Solution sol;
    vector<int> res = sol.finalPrices(prices);
    for (auto &x: res)
        cout << x << endl;
    return 0;
}
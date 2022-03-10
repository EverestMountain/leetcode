#include "header/common.h"

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals) {
        map<int, int> m;
        int n = intervals.size();
        for (int i = 0; i < n; i++)
            m[intervals[i][0]] = i;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            auto lb = m.lower_bound(intervals[i][1]);
            ans[i] = ((lb == m.end()) ? -1 : (lb->second));
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{3, 4},
                                     {2, 3},
                                     {1, 2}};
    auto ret = sol.findRightInterval(intervals);
    cout << "-----------------" << endl;
    for (auto &x: ret) cout << x << " ";
    cout << endl << "-----------------" << endl;
    return 0;
}
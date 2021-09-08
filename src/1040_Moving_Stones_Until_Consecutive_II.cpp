#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> numMovesStonesII(vector<int> &A) {
        sort(A.begin(), A.end());
        int n = A.size();
        int low = n;
        for (int i = 0, j = 0; j < n; j++) {
            while (A[j] - A[i] + 1 > n) i++;
            int a = A[j] - A[i] + 1;
            int b = j - i + 1;
            if (a == n - 1 && b == n - 1) {
                low = min(low, 2);
            } else {
                low=min(n-b,low);
            }
        }
        int high=max(A[n-2]-A[0]-n+2,A[n-1]-A[1]-n+2);
        return {low,high};
    }
};

//problem: https://leetcode.com/problems/moving-stones-until-consecutive-ii/
//discuss refered：https://leetcode.com/problems/moving-stones-until-consecutive-ii/discuss/289357/c%2B%2B-with-picture
int main() {
    Solution sol;
    vector<tuple<vector<int>, vector<int>>> test_cases;
    test_cases.push_back({{7, 4, 9},
                          {1, 2}});
    test_cases.push_back({{6, 5, 4, 3, 10},
                          {2, 3}});
    for (auto &test_case:test_cases) {
        vector<int> res = sol.numMovesStonesII(std::get<0>(test_case));
        cout << res[0] << " " << res[1] << endl;
    }
    return 0;
}
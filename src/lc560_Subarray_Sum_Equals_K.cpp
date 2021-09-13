#include<vector>
#include<iostream>
#include<tuple>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        int res = 0;
        int s = 0;
        mp[0] = 1;
        for (auto &x:nums) {
            s += x;
//            if (mp.find(s - k) != mp.end()) {
            res += mp[s - k];
//            }
//            if (mp.find(s) == mp.end())
//                mp[s] = 1;
//            else
            mp[s] += 1;
        }
        return res;
    }
};
//[题目链接](https://leetcode.com/problems/subarray-sum-equals-k/)
int main() {
    vector<
            tuple<vector<int>, int>
    > test_cases;
    Solution sol;
    test_cases.push_back({{1, 1, 1}, 2});
    test_cases.push_back({{1, 2, 3}, 3});
    for (auto &test_case:test_cases) {
        cout << sol.subarraySum(std::get<0>(test_case), std::get<1>(test_case)) << endl;
    }
    return 0;
}

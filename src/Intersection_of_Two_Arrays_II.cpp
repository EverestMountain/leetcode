#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        vector<int> res;
        for (auto &x: nums1)
            mp1[x] += 1;
        for (auto &x: nums2)
            mp2[x] += 1;
        for (auto x: mp1) {
            if (mp2.find(x.first) != mp2.end()) {
                int n1 = mp1[x.first];
                int n2 = mp2[x.first];
                for (int i = 0; i < min(n1, n2); i++) {
                    res.push_back(x.first);
                }
            }
        }
        return res;
    }
};

//[题目链接](https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/638/week-3-september-15th-september-21st/3978)
int main() {
    vector<tuple<vector<int>, vector<int>, vector<int>>> test_cases;
    test_cases.emplace_back(make_tuple<vector<int>, vector<int>, vector<int>>({1, 2, 2, 1}, {2, 2}, {2, 2}));
    test_cases.emplace_back(make_tuple<vector<int>, vector<int>, vector<int>>({4, 9, 5}, {9, 4, 9, 8, 4}, {9, 4}));
    Solution sol;
    for (auto &test_case: test_cases) {
        assert(sol.intersect(std::get<0>(test_case), std::get<1>(test_case)) == std::get<2>(test_case));
    }
    return 0;
}
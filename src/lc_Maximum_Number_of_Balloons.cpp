#include<string>
#include<vector>
#include<utility>
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string b = "balloon";
        unordered_map<char, int> cnt;
        for (const auto &c:b)
            cnt[c] = 0;
        for (const auto &c:text)
            if (cnt.find(c) != cnt.end())
                cnt[c] += 1;
        int mi = INT_MAX;
        for (const auto &x:cnt) {
//            cout << x.first << ":" << x.second << endl;
            if (x.first == 'l' or x.first == 'o')
                mi = min(mi, x.second / 2);
            else
                mi = min(mi, x.second);
        }

        return mi;
    }
};

//[题目链接](https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/637/week-2-september-8th-september-14th/3973/)
int main() {
    Solution sol;
    vector<pair<string, int>> test_cases;
    test_cases.push_back({"nlaebolko", 1});
    test_cases.push_back({"loonbalxballpoon", 2});
    test_cases.push_back({"leetcode", 0});
    test_cases.push_back({"balon", 0});
    for (auto &test_case:test_cases)
        assert(sol.maxNumberOfBalloons(std::get<0>(test_case)) == std::get<1>(test_case));
    return 0;
}
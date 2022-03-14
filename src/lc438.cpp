#include "header/common.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        if (n < m) return {};
        unordered_map<char, int> cnt;
        unordered_map<char, int> need;
        for (auto &c: p) {
            need[c]++;
        }
        int total_cnt = 0;
        vector<int> ans;
        for (int i = 0; i < m; i++) {
            cnt[s[i]]++;
            if (cnt[s[i]] <= need[s[i]]) {
                total_cnt += 1;
            }
        }
        if (total_cnt == m) ans.push_back(0);
        for (int i = m; i < n; i++) {
            cnt[s[i]]++;
            if (cnt[s[i]] <= need[s[i]]) {
                total_cnt += 1;
            }
            cnt[s[i - m]]--;
            if (cnt[s[i - m]] < need[s[i - m]]) {
                total_cnt -= 1;
            }
            if (total_cnt == m) {
                ans.push_back(i - m + 1);
            }
        }
        return ans;
    }
};

int main() {
//    string s = "cbaebabacd";
//    string p = "abc";
    string s = "abab";
    string p = "ab";
    Solution sol;
    auto ans = sol.findAnagrams(s, p);
    for (auto &x: ans)
        cout << x << " ";
    cout << endl;
    return 0;
}
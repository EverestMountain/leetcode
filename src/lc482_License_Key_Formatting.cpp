#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        vector<char> s1;
        for (auto &c: s)
            if (c != '-') s1.push_back(c);
        int n = s1.size();
        string res;
        for (int i = 0; i < n; i++) {
            if (i >= 0 and i != (n - 1) and (i + 1) % k == 0) {
                res.push_back(s1[n - 1 - i]);
                res.push_back('-');
            } else {
                res.push_back(s1[n - 1 - i]);
            }
        }
        std::reverse(res.begin(), res.end());
        for (auto &c: res)
            if (c >= 'a' and c <= 'z')
                c = c - 'a' + 'A';
        return res;
    }
};

int main() {
    Solution sol;
    assert(sol.licenseKeyFormatting("5F3Z-2e-9-w", 4) == "5F3Z-2E9W");
    assert(sol.licenseKeyFormatting("2-5g-3-J", 2) == "2-5G-3J");
    cout << sol.licenseKeyFormatting("a-a-a-a-", 1) << endl;
    return 0;
}
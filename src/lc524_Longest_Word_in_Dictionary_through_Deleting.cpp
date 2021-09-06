/*
 * Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.
Example 1:
Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output: "apple"
Example 2:
Input: s = "abpcplea", dictionary = ["a","b","c"]
Output: "a"
Constraints:
1 <= s.length <= 1000
1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 1000
s and dictionary[i] consist of lowercase English letters.
 */
#include<string>
#include<cassert>
#include<vector>
#include<cstring>
#include<algorithm>
#include<tuple>

using namespace std;

bool comp(const string &a, const string &b) {
    unsigned long m = a.size();
    unsigned long n = b.size();
    if (m == n) return a < b;
    return m > n;
}
/*
Runtime: 56 ms, faster than 84.43% of C++ online submissions for Longest Word in Dictionary through Deleting.
Memory Usage: 15 MB, less than 86.05% of C++ online submissions for Longest Word in Dictionary through Deleting.
 */
class Solution {
public:
    string findLongestWord(string s, vector<string> &dictionary) {
        sort(dictionary.begin(), dictionary.end(), comp);
        for (auto const &t: dictionary) {
            int n = t.size();
            if (n == 0) return t;
            int j = 0;
            for (auto &c:s) {
                if (c == t[j]) {
                    j++;
                }
                if (j == n) {
                    return t;
                }
            }
        }
        return "";
    }
};
int main() {
    string s = "abpcplea";
    //tuple's usage: https://en.cppreference.com/w/cpp/utility/tuple
    vector<tuple<string, vector<string>, string>> test_cases{
            make_tuple<string, vector<string>, string>("abpcplea", {"apple", "ale", "monkey", "plea"}, "apple"),
            make_tuple<string, vector<string>, string>("abpcplea", {"a", "b", "c"}, "a")
    };
    Solution sol;
    for (const auto &test_case:test_cases) {
        auto s = std::get<0>(test_case);
        auto dictionary = std::get<1>(test_case);
        auto t = std::get<2>(test_case);
        auto r = sol.findLongestWord(s, dictionary);
        fprintf(stdout, "result: %s\n", r.c_str());
        fprintf(stdout, "target: %s\n", t.c_str());
        assert(r == t);
        assert(strcmp(r.c_str(), t.c_str()) == 0);
    }
}



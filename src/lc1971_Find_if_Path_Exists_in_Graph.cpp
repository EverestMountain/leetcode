#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define  vi vector<int>
#define m_i_vi unordered_map<int,vi>
#define si unordered_set<int>

class Solution {
    bool dfs(int s, int t, si &visited, m_i_vi &g) {
        for (auto &n: g[s]) {
            if (visited.find(n) != visited.end()) {
                continue;
            } else if (n == t) {
                return true;
            } else {
                visited.insert(n);
                if (dfs(n, t, visited, g)) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool validPath(int n, vector<vi > &edges, int s, int t) {
        if(s==t) return True;
        m_i_vi g;
        si visited;
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        visited.insert(s);
        return dfs(s, t, visited, g);
    }
};

class TestCase {
public:
    int n;
    vector<vi > edges;
    int s;
    int t;
    bool res;
public:
    TestCase(int n_, vector<vi > edges_, int s_, int t_, bool res_) {
        n = n_;
        edges = edges_;
        s = s_;
        t = t_;
        res = res_;
    };
};

int main() {
    vector<TestCase> test_cases;
    test_cases.push_back(TestCase(3, {{0, 1},
                                      {1, 2},
                                      {2, 0}}, 0, 2, true));
    test_cases.push_back(TestCase(
            6, {{0, 1},
                {0, 2},
                {3, 5},
                {5, 4},
                {4, 3}},
            0, 5, false
    ));
    Solution sol;
    for (auto &test_case: test_cases) {
        cout << sol.validPath(test_case.n,
                              test_case.edges,
                              test_case.s,
                              test_case.t) << endl;
    }
    return 0;
}
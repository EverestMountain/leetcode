#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<utility>
#include<iostream>

using namespace std;

#define gt unordered_map<int, unordered_set<int>>

template<typename T>
void print_vector(vector<T> &v) {
    size_t n = v.size();
    for (auto x: v)
        cout << x << " ";
    cout << endl;
}

class Solution {
public:
    vector<string> node2Name;

    bool isConnect(const string &s1, const string &s2) {
        int n = s1.size();
        int diff_cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) diff_cnt += 1;
        }
        return diff_cnt == 1;
    }

    void get_paths(int to, unordered_map<int, unordered_set<int>> &froms,
                   vector<string> &node2Name, vector<string> &path,
                   vector<vector<string>> &res) {
        path.push_back(node2Name[to]);
        if (to == 0) {
            res.push_back(path);
        } else {
            for (auto &from: froms[to]) {
                get_paths(from, froms, node2Name, path, res);
            }
        }
        path.pop_back();
    }


    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end())
            return {};
        node2Name.push_back(beginWord);
        for (auto &word: wordList)
            node2Name.push_back(word);
        node2Name.push_back(endWord);
        gt g;
        int N = node2Name.size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (isConnect(node2Name[i], node2Name[j])) {
                    g[i].insert(j);
                    g[j].insert(i);
                }
            }
        }
        //0节点是source节点，n-1节点是destination节点
        vector<int> d(N, INT_MAX);
        unordered_map<int, unordered_set<int>> from;
        d[0] = 0;
        auto compare = [](const pair<int, int> &a,
                          const pair<int, int> &b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>,
                vector<pair<int, int>>,
                decltype(compare)> candidates(compare);
        candidates.push({0, 0});
        //确定的
        unordered_set<int> determined = {0};
        while (not candidates.empty()) {
            auto candidate = candidates.top();
            candidates.pop();
            int c = candidate.first;
            for (auto &n: g[c]) {
                if (determined.find(n) == determined.end()) {
                    if (d[c] + 1 < d[n]) {
                        d[n] = d[c] + 1;
                        from[n] = {c};
                        candidates.push({n, d[n]});
                    } else if (d[c] + 1 == d[n]) {
                        from[n].insert(c);
                    }
                }
            }
        }
//        cout<<"from------------------"<<endl;
//        for (int i = 0; i < N; i++) {
//            auto x = from[i];
//            cout<<node2Name[i]<<"<-";
//            for (auto &y: x)
//                cout << node2Name[y] << " ";
//            cout << endl;
//        }
//        cout<<"graph-------------------"<<endl;
//        for(int i=0;i<N;i++){
//            cout<<node2Name[i]<<": ";
//            for(auto& n:g[i])
//                cout<<node2Name[n]<<" ";
//            cout<<endl;
//        }
        vector<string> path = {};
        vector<vector<string>> res = {};
        get_paths(N - 1, from, node2Name, path, res);
        for (auto &x: res) {
            reverse(x.begin(), x.end());
        }
        return res;
    }
};
//[题目链接](https://leetcode.com/problems/word-ladder-ii/)
int main() {
//    Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
//    Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
//    beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
//    string beginWord = "hit";
//    string endWord = "cog";
//    vector<string> wordList = {"hot", "dot", "dog", "lot", "log"};
    vector<vector<string>> paths = sol.findLadders(beginWord, endWord, wordList);
    cout<<"paths.size() "<<paths.size()<<endl;

    for (auto &path: paths) {
        for (auto &t: path)
            cout << t << " ";
        cout << endl;
    }
    return 0;
}
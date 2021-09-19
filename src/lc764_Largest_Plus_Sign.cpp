#include<vector>
#include<iostream>
#include<unordered_map>
#include<tuple>
#include"../header/vector_utils.h"

using namespace std;

class Solution {
public:
    int calSpan(int l, int r, int i) {
        if (l == i or r == i) return 0;
        else {
            return min(i - l, r - i);
        }
    }

    void calSpanForVec(vector<int> &M, vector<int> &a) {
        int n = a.size();
        //加入两个位置
        M.insert(M.begin(), -1);
        M.push_back(n); // m+2 0~m+1
        int m = M.size();
        for (int i = 1; i <= m - 1; i++) {
            for (int j = M[i - 1]; j <= M[i] - 1; j++) {
                if (j == -1) continue;
                else a[j] = M[i - 1];
            }
        }
//        print_vector(a);
        for (int i = 0; i <= m - 2; i++) {
            for (int j = M[i] + 1; j <= M[i + 1]; j++)
                if (j == n) continue;
                else a[j] = calSpan(a[j], M[i + 1], j);
        }
//        print_vector(a);
    }

    vector<vector<int>> calSpanForMat(int n, unordered_map<int, vector<int>> &Ms) {
        vector<vector<int>> row_span(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            if (Ms.find(i) == Ms.end()) {
                vector<int> M;
                calSpanForVec(M, row_span[i]);
            } else
                calSpanForVec(Ms[i], row_span[i]);
        }
        return row_span;
    }

public:
    int orderOfLargestPlusSign(int n, vector<vector<int>> &mines) {
        unordered_map<int, vector<int>> row_mines, col_mines;
        for (auto &mine: mines) {
            int r = mine[0], c = mine[1];
            row_mines[r].push_back(c);
            col_mines[c].push_back(r);
        }
        vector<vector<int>> row_span = calSpanForMat(n, row_mines);
        vector<vector<int>> col_span_t = calSpanForMat(n, col_mines);
        cout << "--------------------" << endl;
        print_matrix(row_span);
        cout << "--------------------" << endl;
        print_matrix(col_span_t);
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = max(min(row_span[i][j], col_span_t[j][i]), res);
            }
        }
        return res;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> mines{{4, 2}};
    cout << sol.orderOfLargestPlusSign(5, mines) << endl;
    return 0;
}
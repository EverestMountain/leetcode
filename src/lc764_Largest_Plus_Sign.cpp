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

//[最高票解法](https://leetcode.com/problems/largest-plus-sign/discuss/113314/JavaC%2B%2BPython-O(N2)-solution-using-only-one-grid-matrix)
class Solution1 {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>> &mines) {
        vector<vector<int>> a(n, vector<int>(n, n));
        for (auto &mine: mines) {
            a[mine[0]][mine[1]] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0, k = n - 1, l = 0, r = 0, u = 0, d = 0; j < n;
                 j++, k--) {
                a[i][j] = min(a[i][j], l = (a[i][j] == 0 ? 0 : l + 1));
                a[i][k] = min(a[i][k], r = (a[i][k] == 0 ? 0 : r + 1));
                a[j][i] = min(a[j][i], u = (a[j][i] == 0 ? 0 : u + 1));
                a[k][i] = min(a[k][i], d = (a[k][i] == 0 ? 0 : d + 1));
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = max(a[i][j], res);
            }
        }
        return res;
    }
};

int main() {
    Solution1 sol;
    vector<vector<int>> mines{{0, 0},
                              {1, 1}};
    cout << sol.orderOfLargestPlusSign(2, mines) << endl;
    return 0;
}
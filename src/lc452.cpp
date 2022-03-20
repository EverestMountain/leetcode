#include "header/common.h"

class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        sort(points.begin(), points.end(), [](vector<int> &lhs, vector<int> &rhs) {
            return lhs[1] < rhs[1];
        });
        int n = points.size();
        int i = 0;
        int p = points[i][1];
        int need = 1;
        while (i < n) {
            int j = i + 1;
            while (j < n) {
                if (points[j][0] > p) {
                    need += 1;
                    break;
                }
                j++;
            }
            i = j;
            if (j < n) {
                p = points[j][1];
            }
        }
        return need;
    }
};

void read_input(string &input_file, vector<vector<int>> &points) {
    ifstream in(input_file);
    string s;
    int cnt = 0;
    vector<int> point;
    while (std::getline(in, s, ',')) {
        int val = stoi(s);
        point.push_back(val);
        if (cnt++ % 2 == 1) {
            points.push_back(point);
            point.clear();
        }
    }
}

int main() {
    vector<vector<int>> points;
    string input_file = "input/lc452_input.txt";
    read_input(input_file, points);
    cout << "read done " << endl;
    cout<<"size of points "<<points.size()<<endl;
    Solution sol;
    cout<<sol.findMinArrowShots(points)<<endl;
    return 0;
}

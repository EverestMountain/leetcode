/*
 * You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.



Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:

Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [[1,3],[2,3]]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]


Constraints:

1 <= nums1.length, nums2.length <= 105
-109 <= nums1[i], nums2[i] <= 109
nums1 and nums2 both are sorted in ascending order.
1 <= k <= 1000
 */
#include <queue>
//#include <pair>
#include<unordered_set>
#include<iostream>
#include<tuple>

using namespace std;
typedef pair<int, long> pd;

struct myCompare {
    constexpr bool operator()(
            pd const &a,
            pd const &b
    ) const noexcept {
        return a.first >= b.first;
    }
};


class Solution {
    void push_neighbor(std::priority_queue<pd, vector<pd>, myCompare> &pq,
                       vector<int> &nums1, vector<int> &nums2, int i, int j, unordered_set<long> &visited) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dirs = {{1, 0},
                                    {0, 1}};
        for (auto &dir:dirs) {
            long x = i + dir[0], y = j + dir[1];
            long idx = x * n + y;
            if (x < m and y < n) {
                if (visited.find(idx) == visited.end()) {
                    visited.insert(idx);
                    pq.push(make_pair(nums1[x] + nums2[y], idx));
                }
            }
        }
    }

public:

    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        // 矩阵大小 m*n
        //pair第一个位置存和，第二个位置存i*n+j
        std::priority_queue<pd, vector<pd>, myCompare> pq;
        unordered_set<long> visited;
        int i, j;
        vector<vector<int>> result;
        while (k > 0) {
            if (pq.empty()) {
                //所有的元素已经访问完了
                if (visited.size() == long(m) * long(n)) {
                    break;
                } else {
                    pq.push(make_pair(nums1[0] + nums2[0], 0));
                    visited.insert(0);
                }
            }
            i = int(pq.top().second / n);
            j = int(pq.top().second % n);
            pq.pop();
            result.push_back({nums1[i], nums2[j]});
            push_neighbor(pq, nums1, nums2, i, j, visited);
            k--;
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    vector<
            tuple<
                    vector<int>, vector<int>, int, vector<vector<int>>
            >
    > test_cases;
    test_cases.push_back(make_tuple<vector<int>, vector<int>, int, vector<vector<int>>>({1, 7, 11}, {2, 4, 6}, 3,
                                                                                        {{1, 2},
                                                                                         {1, 4},
                                                                                         {1, 6}}));
    test_cases.push_back(make_tuple<vector<int>, vector<int>, int, vector<vector<int>>>({1, 1, 2}, {1, 2, 3}, 2,
                                                                                        {{1, 1},
                                                                                         {1, 1}}));
    test_cases.push_back(make_tuple<vector<int>, vector<int>, int, vector<vector<int>>>({1, 2}, {3}, 3, {{1, 3},
                                                                                                         {2, 3}}));
    for (auto &test_case: test_cases) {
        vector<vector<int>> res = sol.kSmallestPairs(std::get<0>(test_case), std::get<1>(test_case),
                                                     std::get<2>(test_case));
        vector<vector<int>> tgt = std::get<3>(test_case);
        assert(res.size() == tgt.size());
        int n = tgt.size();
        for (int i = 0; i < n; i++) {
            assert(res[i] == tgt[i]);
        }
    }
    cout << "PASSED" << endl;
    return 0;
}
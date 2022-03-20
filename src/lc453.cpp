#include "header/common.h"
#include <numeric>

class Solution {
public:
    int minMoves(vector<int> &nums) {
        int mi = *min_element(nums.begin(), nums.end());
        long sum = 0;
        for (auto &num: nums) {
            sum += long(num);
        }
        return int(sum - long(mi) * long(nums.size()));
    }
};

int main() {
    return 0;
}
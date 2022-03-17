#include "header/common.h"
#include "header/common.h"
#include "header/tree_utils.h"

class Solution {
    void dfs(TreeNode *root, const int &targetSum, int &cumsum, multiset<int> &prefix_sum, int &ans) {
        if (root == nullptr) return;
        cumsum += root->val;
        ans += prefix_sum.count(cumsum - targetSum);
        prefix_sum.insert(cumsum);
        dfs(root->left, targetSum, cumsum, prefix_sum, ans);
        dfs(root->right, targetSum, cumsum, prefix_sum, ans);
        prefix_sum.erase(prefix_sum.find(cumsum));
        cumsum -= root->val;
    }

public:
    int pathSum(TreeNode *root, int targetSum) {
        int cumsum = 0;
        multiset<int> prefix_sum = {0};
        int ans = 0;
        dfs(root, targetSum, cumsum, prefix_sum, ans);
        return ans;
    }
};

int main() {
    string tree_str = "10,5,-3,3,2,null,11,3,-2,null,1";
    vector<string> tree_vec = string_split(tree_str);
    Solution sol;
    TreeNode *root = build_tree(tree_vec);
    cout << sol.pathSum(root, 8) << endl;
    return 0;
}
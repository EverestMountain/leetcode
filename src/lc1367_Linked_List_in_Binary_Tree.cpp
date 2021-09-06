/*
Given a binary tree root and a linked list with head as the first node.
Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.
In this context downward path means a path that starts at some node and goes downwards.
 */

//Definition for singly-linked list.
#include<utility>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool checkPath(ListNode *head, TreeNode *root) {
        if (head == nullptr) return true;
        if (root == nullptr) return false;
        if (head->val != root->val) return false;
        return checkPath(head->next, root->left) or checkPath(head->next, root->right);
    }

    bool isSubPath(ListNode *head, TreeNode *root) {
        if (head == nullptr) return true;
        queue<TreeNode *> q;
        q.push(root);
        while (not q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur == nullptr) continue;
            else {
                if (cur->val == head->val) {
                    if (checkPath(head, cur)) {
                        return true;
                    }
                }
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return false;
    }
};

// 题目链接: https://leetcode.com/problems/linked-list-in-binary-tree/

vector<string> string_split(string &s) {
    if (s.size() == 0) return {};
    vector<string> res;
    size_t start = 0;
    size_t pos;
    do {
        pos = s.find(',', start);
        if (pos == string::npos) {
            res.push_back(s.substr(start));
            break;
        } else {
            res.push_back(s.substr(start, pos - start));
        }
        start = pos + 1;
    } while (true);
    return res;
}

TreeNode *str2node(const string &s) {
    if (s == "null") return nullptr;
    else return new TreeNode(atoi(s.c_str()));
}

TreeNode *build_tree(vector<string> &v) {
    queue<TreeNode *> q;
    if (v.empty()) {
        return nullptr;
    }
    if (v[0] == "null") {
        return nullptr;
    }
    int n = v.size();
    int i = 1;
    TreeNode *root = str2node(v[0]);
    q.push(root);
    while (i < n) {
        TreeNode *p = q.front();
        q.pop();
        p->left = str2node(v[i]);
        p->right = str2node(v[i + 1]);
        if (p->left != nullptr) q.push(p->left);
        if (p->right != nullptr) q.push(p->right);
        i += 2;
    }
    return root;
}

ListNode *build_list(const vector<string> &v) {
    if (v.empty()) return nullptr;
    ListNode *head = new ListNode(atoi(v[0].c_str()));
    ListNode *cur = head;
    for (int i = 1; i < v.size(); i++) {
        cur->next = new ListNode(stoi(v[i].c_str()));
        cur = cur->next;
    }
    return head;
}

// 树的前序遍历
void preorder_traversal(TreeNode *root) {
    if (root == nullptr) return;
    cout << root->val << endl;
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void level_traversal(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    while (not q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur == nullptr) {
                cout << "null" << ",";
            } else {
                cout << cur->val << ",";
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        cout << "\n";
    }
}

void print_list(ListNode *head) {
    ListNode *cur = head;
    while (cur) {
        cout << cur->val << ",";
        cur = cur->next;
    }
    cout << "\n";
}
void test_case(tuple<string,string,bool>& x){
    vector<string> tree_vec = string_split(std::get<0>(x));
    TreeNode *root = build_tree(tree_vec);
    vector<string> list_vec = string_split(std::get<1>(x));
    ListNode *head = build_list(list_vec);
    Solution sol;
    cout<<"----------------list-----------------\n";
    print_list(head);
    cout<<"----------------tree-----------------\n";
    level_traversal(root);
    assert(sol.isSubPath(head, root)==std::get<2>(x));
}
int main() {
    vector<tuple<string, string, bool>> test_cases;
    test_cases.push_back(
            make_tuple<string, string, bool>("1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3", "4,2,8", true)
    );
    test_cases.push_back(
            make_tuple<string, string, bool>("1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3", "1,4,2,6", true)
    );
    test_cases.push_back(
            make_tuple<string,string,bool>("1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3","1,4,2,6,8",false)
            );
    int cnt=0;
    for(auto& x:test_cases){
        cout<<cnt++<<endl;
        test_case(x);
    }
    return 0;
}

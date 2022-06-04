#include <bits/stdc++.h>

using namespace std;

// SOLUTION
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> ans{};
    stack<pair<TreeNode *, string>> s{};
    s.push({root, to_string(root->val)});

    while (!s.empty())
    {
        auto curr = s.top();
        s.pop();

        if (!curr.first->left && !curr.first->right)
            ans.push_back(curr.second);

        if (curr.first->left)
            s.push({curr.first->left, curr.second + "->" + to_string(curr.first->left->val)});

        if (curr.first->right)
            s.push({curr.first->right, curr.second + "->" + to_string(curr.first->right->val)});
    }

    return ans;
}
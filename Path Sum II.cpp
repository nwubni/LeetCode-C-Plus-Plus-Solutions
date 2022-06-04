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

vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    if (!root)
        return {};

    vector<vector<int>> ans{};
    stack<pair<pair<TreeNode *, vector<int>>, int>> s{}; // pair<pair<node, vector>, sum of nodes>
    s.push({{root, {root->val}}, root->val});

    while (!s.empty())
    {
        auto curr = s.top();
        s.pop();

        if (!curr.first.first->left && !curr.first.first->right && curr.second == targetSum) // Push the whole vector in curr.first.second into ans
            ans.push_back(curr.first.second);

        if (curr.first.first->left)
        {
            curr.first.second.push_back(curr.first.first->left->val);                                         // Add left node value to vector and push the vector and the total sum of nodes in the left path unto stack
            s.push({{curr.first.first->left, curr.first.second}, curr.second + curr.first.first->left->val}); // pair<pair<left node, updated vector>, sum of previous nodes in path plus the left node val>
            curr.first.second.pop_back();                                                                     // Remove the last item so it doesn't form part of the vector for the right braches
        }

        if (curr.first.first->right)
        { // Add right node value to vector and push the vector and the total sum of nodes in the right path unto stack
            curr.first.second.push_back(curr.first.first->right->val);
            s.push({{curr.first.first->right, curr.first.second}, curr.second + curr.first.first->right->val}); // pair<pair<right node, updated vector>, sum of previous nodes in path plus the right node val>
        }
    }

    return ans;
}
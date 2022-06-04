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

string smallestFromLeaf(TreeNode *root)
{
    string ans{};
    stack<pair<TreeNode *, string>> s{};
    s.push({root, string(1, root->val + 'a')}); // pair<node, store the string that results from traversing the tree>. string(1, root->val + 'a') converts a number between from 0 to 25 to an alphabet string: a->0, b->1, c->2 .... z->25

    while (!s.empty())
    {
        auto curr = s.top();
        s.pop();

        if (!curr.first->left && !curr.first->right)
        { // Leaf node reached. Update the ans variable with the smallest of ans and curr.second
            if (ans.empty())
                ans = curr.second;
            else
                ans = min(ans, curr.second);
        }

        if (curr.first->left) // Convert node value to a string alphabet and prepend it to the string that has been formed through traversing the tree from the root to the node
            s.push({curr.first->left, string(1, curr.first->left->val + 'a') + curr.second});
        if (curr.first->right) // Convert node value to a string alphabet and prepend it to the string that has been formed through traversing the tree from the root to the node
            s.push({curr.first->right, string(1, curr.first->right->val + 'a') + curr.second});
    }

    return ans;
}
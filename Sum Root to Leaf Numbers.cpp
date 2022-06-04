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

int sumNumbers(TreeNode *root)
{
    if (!root)
        return 0;

    int ans{0};

    stack<pair<TreeNode *, int>> s{}; // Stores a node and the number value formed from traversing the root to the node
    s.push({root, root->val});        // Push the root and its value onto the stack s

    while (!s.empty())
    {
        auto curr = s.top();
        s.pop();

        if (!curr.first->left && !curr.first->right) // Only add numbers when you reach a leaf node. A leaf node does not have a left and right child.
            ans += curr.second;

        if (curr.first->left)                                                     // Multiply second value in the curr pair by 10 and add the val in the left node of curr. This is a necessary step to form a number value from the root to a left leaf node. Finally, push the result and the left node onto the stack to pass the result down to lower nodes : 1 -> 2 ==> 1 * 10 + 2 = 12
            s.push({curr.first->left, curr.second * 10 + curr.first->left->val}); // Pair<left node, new number value after performing the calculation above>

        if (curr.first->right)                                                      // Multiply second value in the curr pair by 10 and add the val in the right node of curr. This is a necessary step to form a number value from the root to a right leaf node. Finally, push the result and the right node onto the stack to pass the result down to lower nodes: 1 -> 3 ==> 1 * 10 + 3 = 13
            s.push({curr.first->right, curr.second * 10 + curr.first->right->val}); // Pair<right node, new number value after performing the calculation above>
    }

    return ans;
}
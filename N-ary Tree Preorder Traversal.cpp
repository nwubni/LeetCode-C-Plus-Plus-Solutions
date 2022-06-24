#include <bits/stdc++.h>

using namespace std;

// SOLUTION
// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

vector<int> preorder(Node *root)
{
    if (!root)
        return {};

    vector<int> ans{};
    stack<Node *> s{};
    s.push(root);

    while (!s.empty())
    {
        Node *curr = s.top();
        s.pop();
        ans.push_back(curr->val);

        while (!curr->children.empty())
        {
            s.push(curr->children.back());
            curr->children.pop_back();
        }
    }

    return ans;
}
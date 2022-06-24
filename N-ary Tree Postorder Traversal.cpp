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

vector<int> postorder(Node *root)
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

        for (auto &child : curr->children)
            s.push(child);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}
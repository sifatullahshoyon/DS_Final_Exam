#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int v)
    {
        val = v;
        left = NULL;
        right = NULL;
    }
};

int main()
{
    vector<int> arr;
    int x;
    while (cin >> x)
    {
        arr.push_back(x);
    }

    int X = arr.back();
    arr.pop_back();

    if (arr.size() == 0 || arr[0] == -1)
    {
        cout << "Invalid\n";
        return 0;
    }

    Node *root = new Node(arr[0]);
    queue<Node *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size())
    {
        Node *cur = q.front();
        q.pop();

        if (i < arr.size() && arr[i] != -1)
        {
            cur->left = new Node(arr[i]);
            q.push(cur->left);
        }
        i++;

        if (i < arr.size() && arr[i] != -1)
        {
            cur->right = new Node(arr[i]);
            q.push(cur->right);
        }
        i++;
    }

    queue<pair<Node *, int>> bfs;
    bfs.push({root, 0});

    bool found = false;

    while (!bfs.empty())
    {
        auto cur = bfs.front();
        bfs.pop();

        Node *node = cur.first;
        int level = cur.second;

        if (level == X)
        {
            cout << node->val << " ";
            found = true;
        }

        if (node->left)
            bfs.push({node->left, level + 1});
        if (node->right)
            bfs.push({node->right, level + 1});
    }

    if (!found)
        cout << "Invalid";

    cout << "\n";
    return 0;
}

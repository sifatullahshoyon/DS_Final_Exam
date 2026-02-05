#include <bits/stdc++.h>
using namespace std;

// Tree Node
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

    if (arr.size() == 0 || arr[0] == -1)
    {
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

    vector<int> leafs;
    queue<Node *> bfs;
    bfs.push(root);

    while (!bfs.empty())
    {
        Node *cur = bfs.front();
        bfs.pop();

        if (cur->left == NULL && cur->right == NULL)
        {
            leafs.push_back(cur->val);
        }

        if (cur->left)
            bfs.push(cur->left);
        if (cur->right)
            bfs.push(cur->right);
    }

    sort(leafs.begin(), leafs.end(), greater<int>());

    for (int v : leafs)
    {
        cout << v << " ";
    }

    return 0;
}

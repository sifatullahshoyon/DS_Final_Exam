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

int height(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

int countNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

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
        cout << "NO\n";
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

    int h = height(root);
    int totalNodes = countNodes(root);

    int expectedNodes = (1 << h) - 1;

    if (totalNodes == expectedNodes)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}

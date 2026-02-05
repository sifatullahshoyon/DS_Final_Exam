#include <bits/stdc++.h>
using namespace std;

struct Node
{
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> level;
    int x;

    while (cin >> x)
    {
        level.push_back(x);
    }

    if (level.size() == 0 || level[0] == -1)
    {
        cout << 0 << "\n";
        return 0;
    }

    Node *root = new Node(level[0]);
    queue<Node *> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < level.size())
    {
        Node *curr = q.front();
        q.pop();

        if (i < level.size() && level[i] != -1)
        {
            curr->left = new Node(level[i]);
            q.push(curr->left);
        }
        i++;

        if (i < level.size() && level[i] != -1)
        {
            curr->right = new Node(level[i]);
            q.push(curr->right);
        }
        i++;
    }

    long long sum = 0;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr->left != NULL || curr->right != NULL)
        {
            sum += curr->val;
        }

        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }

    cout << sum << "\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *createTree(vector<int> arr)
{
    if (arr.empty() || arr[0] == -1)
        return NULL;

    Node *root = new Node(arr[0]);
    queue<Node *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size())
    {
        Node *curr = q.front();
        q.pop();

        if (i < arr.size() && arr[i] != -1)
        {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i < arr.size() && arr[i] != -1)
        {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int findLeftMostLeafValue(Node *root)
{
    while (root->left != NULL || root->right != NULL)
    {
        if (root->left != NULL)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return root->data;
}

int findRightMostLeafValue(Node *root)
{
    while (root->left != NULL || root->right != NULL)
    {
        if (root->right != NULL)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return root->data;
}

vector<int> findPath(Node *root, int target)
{
    vector<int> path;

    while (root != NULL)
    {
        path.push_back(root->data);

        if (root->data == target)
        {
            break;
        }
        else if (target < root->data && root->left != NULL)
        {
            root = root->left;
        }
        else if (root->right != NULL)
        {
            root = root->right;
        }
        else
        {
            // Not found
            path.clear();
            break;
        }
    }
    return path;
}

int main()
{
    vector<int> treeData;
    int value;

    while (cin >> value)
    {
        treeData.push_back(value);
    }

    Node *root = createTree(treeData);

    if (root == NULL)
    {
        return 0;
    }

    int leftLeaf = findLeftMostLeafValue(root);

    int rightLeaf = findRightMostLeafValue(root);

    vector<int> result;

    vector<int> leftEdge;
    Node *temp = root;

    while (temp != NULL && (temp->left != NULL || temp->right != NULL))
    {
        leftEdge.push_back(temp->data);
        if (temp->left != NULL)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    leftEdge.push_back(temp->data);

    for (int i = leftEdge.size() - 1; i >= 0; i--)
    {
        result.push_back(leftEdge[i]);
    }

    vector<int> rightEdge;
    temp = root;
    if (temp->right != NULL)
    {
        temp = temp->right;
        while (temp != NULL && (temp->left != NULL || temp->right != NULL))
        {
            rightEdge.push_back(temp->data);
            if (temp->right != NULL)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        rightEdge.push_back(temp->data);

        for (int i = 0; i < rightEdge.size(); i++)
        {
            result.push_back(rightEdge[i]);
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i != result.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
#include <vector>
void zigZagOrder(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return;
    vector<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push_back(root);
    int level = 1;
    while (pendingNodes.size() != 0)
    {
        int n = pendingNodes.size();
        if (level % 2 == 0)
        {
            for (int i = n - 1; i >= 0; i--)
                cout << pendingNodes[i]->data << " ";
        }
        else
        {
            for (auto i : pendingNodes)
                cout << i->data << " ";
        }
        for (int i = 0; i < n; i++)
        {
            BinaryTreeNode<int> *front = pendingNodes[i];
            if (front->left != NULL)
                pendingNodes.push_back(front->left);
            if (front->right != NULL)
                pendingNodes.push_back(front->right);
        }
        pendingNodes.erase(pendingNodes.begin(), pendingNodes.begin() + n);
        cout << "\n";
        level++;
    }
}
BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}
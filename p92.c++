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

void heightMax(BinaryTreeNode<int> *root, int height, int *max)
{
    if (root == NULL)
        return;
    if ((*max) < height)
        *max = height;
    if (root->left != NULL)
        heightMax(root->left, 1 + height, max);
    if (root->right != NULL)
        heightMax(root->right, 1 + height, max);
}
int height(BinaryTreeNode<int> *root)
{
    // Write our code here
    if (root == NULL)
        return 0;
    int height = 1, max = 1;
    heightMax(root, height, &max);
    return max;
}
bool isBalanced(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return true;
    bool val1 = isBalanced(root->left);
    bool val2 = isBalanced(root->right);
    if (val1 && val2)
    {
        if (abs(height(root->left) - height(root->right)) <= 1)
            return true;
        else
            return false;
    }
    else
        return false;
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
    cout << (isBalanced(root) ? "true" : "false");
}
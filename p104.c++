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
void isBSTHelperLeft(BinaryTreeNode<int> *root, int *leftmax)
{
    if (root->left != NULL && root->left->data > *leftmax)
        *leftmax = root->left->data;
    if (root->right != NULL && root->right->data > *leftmax)
        *leftmax = root->right->data;
}
void isBSTHelperRight(BinaryTreeNode<int> *root, int *rightmin)
{
    if (root->left != NULL && root->left->data < *rightmin)
        *rightmin = root->left->data;
    if (root->right != NULL && root->right->data < *rightmin)
        *rightmin = root->right->data;
}
bool isBST(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return false;
    int leftmax, rightmin;
    bool val1, val2;
    if (root->left != NULL)
    {
        val1 = isBST(root->left);
        leftmax = root->left->data;
        isBSTHelperLeft(root->left, &leftmax);
    }
    if (root->right != NULL)
    {
        val2 = isBST(root->right);
        rightmin = root->right->data;
        isBSTHelperRight(root->right, &rightmin);
    }
    if (root->left == NULL && root->right == NULL)
        return true;
    else if (root->left != NULL && root->right == NULL)
    {
        if ((leftmax < root->data) && (root->left->data < root->data) && val1)
            return true;
        else
            return false;
    }
    else if (root->left == NULL && root->right != NULL)
    {
        if ((rightmin >= root->data) && (root->right->data >= root->data) && val2)
            return true;
        else
            return false;
    }
    else
    {
        if ((leftmax < root->data) && (rightmin >= root->data) && (root->left->data) < (root->data) && (root->right->data >= root->data) && val1 && val2)
            return true;
        else
            return false;
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
    cout << (isBST(root) ? "true" : "false");
}
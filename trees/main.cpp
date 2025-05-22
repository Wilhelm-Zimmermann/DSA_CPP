// binary tree
#include <iostream>

using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int valueData) : TreeNode(valueData, nullptr, nullptr) {}

    TreeNode(int valueData, TreeNode *leftNode, TreeNode *rightNode)
    {
        value = valueData;
        left = leftNode;
        right = rightNode;
    }
};

class BinarySearchTree
{
public:
    TreeNode *root;
    BinarySearchTree()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        TreeNode *newNode = new TreeNode(value);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }
        bool foundParent = false;
        TreeNode *currNode = root;
        while (!foundParent)
        {
            if(value == currNode->value) foundParent = true;
            if (value < currNode->value)
            {
                if (currNode->left != nullptr)
                {
                    currNode = currNode->left;
                }
                else
                {
                    currNode->left = newNode;
                    foundParent = true;
                }
            }
            else
            {
                if (currNode->right != nullptr)
                {
                    currNode = currNode->right;
                }
                else
                {
                    currNode->right = newNode;
                    foundParent = true;
                }
            }
        }
    }
};

int main()
{
    BinarySearchTree *bst = new BinarySearchTree();
    bst->insert(10);
    bst->insert(20);
    bst->insert(11);
    bst->insert(30);
    bst->insert(40);
    bst->insert(35);

    cout << "Root: " << bst->root << endl;
    return 0;
}
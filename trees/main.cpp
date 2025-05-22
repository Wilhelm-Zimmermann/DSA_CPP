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

    bool insert(int value)
    {
        TreeNode *newNode = new TreeNode(value);
        if (root == nullptr)
        {
            root = newNode;
            return true;
        }
        TreeNode *currNode = root;
        while (true)
        {
            if (value == currNode->value)
                return false;
            if (value < currNode->value)
            {
                if (currNode->left == nullptr)
                {
                    currNode->left = newNode;
                    return true;
                }
                currNode = currNode->left;
            }
            else
            {
                if (currNode->right == nullptr)
                {
                    currNode->right = newNode;
                    return true;
                }
                currNode = currNode->right;
            }
        }
    }

    bool contains(int value) {
        if(root == nullptr) return false;

        TreeNode *currNode = root;
        while(currNode != nullptr) {
            if(currNode->value == value) return true;

            if(value < currNode->value) {
                currNode = currNode->left;
                continue;
            }

            if(value > currNode->value) {
                currNode = currNode->right;
                continue;
            }
        }

        return false;
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

    cout << "Root: " << bst->root->value << endl;
    cout << "Has: " << bst->contains(35) << endl;
    cout << "Has: " << bst->contains(23) << endl;
    return 0;
}
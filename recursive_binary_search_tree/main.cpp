#include <iostream>
#include <queue>

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

class RBinarySearchTree
{
public:
    TreeNode *root;

    RBinarySearchTree()
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

    bool contains(int value)
    {
        if (root == nullptr)
            return false;

        TreeNode *currNode = root;
        while (currNode != nullptr)
        {
            if (currNode->value == value)
                return true;

            if (value < currNode->value)
            {
                currNode = currNode->left;
                continue;
            }

            if (value > currNode->value)
            {
                currNode = currNode->right;
                continue;
            }
        }

        return false;
    }

    TreeNode *rInsert(TreeNode *currentNode, int value)
    {
        if (currentNode == nullptr)
            return new TreeNode(value);

        if (value < currentNode->value)
        {
            currentNode->left = rInsert(currentNode->left, value);
        }
        else if (value > currentNode->value)
        {
            currentNode->right = rInsert(currentNode->right, value);
        }

        return currentNode;
    }

    void rInsert(int value)
    {
        if (root == nullptr)
            root = new TreeNode(value);
        rInsert(root, value);
    }

    bool rContains(TreeNode *currentNode, int value)
    {
        if (currentNode == nullptr)
            return false;

        if (currentNode->value == value)
            return true;

        if (value < currentNode->value)
        {
            return rContains(currentNode->left, value);
        }
        else
        {
            return rContains(currentNode->right, value);
        }
    }

    bool rContains(int value)
    {
        return rContains(root, value);
    }

    TreeNode *deleteNode(TreeNode *currentNode, int value)
    {
        if (currentNode == nullptr)
            return nullptr;

        if (value < currentNode->value)
        {
            currentNode->left = deleteNode(currentNode->left, value);
        }
        else if (value > currentNode->value)
        {
            currentNode->right = deleteNode(currentNode->right, value);
        }
        else
        {
            if (currentNode->left == nullptr && currentNode->right == nullptr)
            {
                delete (currentNode);
                return nullptr;
            }
            else if (currentNode->left == nullptr)
            {
                TreeNode *temp = currentNode->right;
                delete (currentNode);
                return temp;
            }
            else if (currentNode->right == nullptr)
            {
                TreeNode *temp = currentNode->left;
                delete (currentNode);
                return temp;
            }
            else
            {
                int subTreeMin = minValue(currentNode->right);
                currentNode->value = subTreeMin;
                currentNode->right = deleteNode(currentNode->right, subTreeMin);
            }
        }

        return currentNode;
    }

    void deleteNode(int value)
    {
        root = deleteNode(root, value);
    }

    int minValue(TreeNode *currentNode)
    {
        while (currentNode->left != nullptr)
        {
            currentNode = currentNode->left;
        }

        return currentNode->value;
    }

    void BFS()
    {
        queue<TreeNode *> queue;
        queue.push(root);

        while (queue.size() > 0)
        {
            TreeNode *currentNode = queue.front();
            queue.pop();
            cout << currentNode->value << " ";
            if (currentNode->left != nullptr)
            {
                queue.push(currentNode->left);
            }
            if (currentNode->right != nullptr)
            {
                queue.push(currentNode->right);
            }
        }
    }

    void DFSPreOrder(TreeNode *currentNode)
    {
        cout << currentNode->value << " ";
        if (currentNode->left)
        {
            DFSPreOrder(currentNode->left);
        }
        if (currentNode->right)
        {
            DFSPreOrder(currentNode->right);
        }
    }

    void DFSPreOrder()
    {
        DFSPreOrder(root);
    }
};

int main()
{
    RBinarySearchTree *rbst = new RBinarySearchTree();

    // rbst->rContains(10);
    // rbst->rInsert(2);
    // rbst->rInsert(1);
    // rbst->rInsert(3);

    // cout << "\nRoot: " << rbst->root->value;
    // cout << "\n\nRoot->Left: " << rbst->root->left->value;
    // cout << "\n\nRoot->Right: " << rbst->root->right->value;
    // cout << "\n";

    // rbst->deleteNode(2);

    // cout << "\nRoot: " << rbst->root->value;
    // cout << "\n\nRoot->Left: " << rbst->root->left->value;
    // cout << "\n\nRoot->Right: " << rbst->root->right;
    // cout << "\n";

    rbst->rInsert(47);
    rbst->rInsert(76);
    rbst->rInsert(21);
    rbst->rInsert(18);
    rbst->rInsert(27);
    rbst->rInsert(52);
    rbst->rInsert(82);
    rbst->BFS();
    cout << endl;
    rbst->DFSPreOrder();
    cout << endl;
    return 0;
}
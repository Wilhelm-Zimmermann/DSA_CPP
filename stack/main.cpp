#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node() : Node(0, nullptr)
    {
    }

    Node(int valueData) : Node(valueData, nullptr)
    {
    }

    Node(int valueData, Node *nodeData) : value(valueData), next(nodeData) {}
};

class Stack
{
private:
    Node *top;
    int height;

public:
    Stack()
    {
        height = 0;
        top = nullptr;
    }

    void push(int value)
    {
        Node *newNode = new Node(value);

        newNode->next = top;
        top = newNode;
        height++;
    }

    int pop() {
        if(height == 0) return INT64_MIN;
        Node* prevTop = top;
        int value = top->value;
        top = top->next;
        delete prevTop;
        height --;

        return value;
    }

    void printStack()
    {
        Node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getTop()
    {
        cout << "Top: " << top->value << endl;
    }

    void getHeight()
    {
        cout << "Height: " << height << endl;
    }
};

int main()
{
    Stack *stack = new Stack();
    stack->push(10);
    stack->push(20);
    stack->push(30);
    stack->push(40);
    stack->printStack();
    return 0;
}
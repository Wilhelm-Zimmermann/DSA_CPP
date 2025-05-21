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

class Queue
{
private:
    Node *first;
    Node *last;
    int length;

public:
    Queue()
    {
        length = 0;
    }

    void printQueue()
    {
        Node *temp = first;
        while (temp != nullptr)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void enqueue(int value)
    {
        Node *node = new Node(value);
        if (length == 0)
        {
            last = node;
            first = node;
            length++;
            return;
        }

        last->next = node;
        last = node;
        length++;
    }

    void dequeue()
    {
        if (length <= 0)
            return;

        if (length == 1)
        {
            last = nullptr;
            delete first;
            first = nullptr;
            length--;
            return;
        }

        Node *temp = first;
        first = first->next;
        delete temp;
        length--;
        return;
    }

    void printFirst()
    {
        cout << "First: " << first << endl;
    }

    void printLast()
    {
        cout << "Last: " << last << endl;
    }

    void getLength()
    {
        cout << "Length: " << length << endl;
    }
};

int main()
{
    Queue *queue = new Queue();
    queue->enqueue(10);
    queue->enqueue(20);
    queue->printQueue();
    return 0;
}
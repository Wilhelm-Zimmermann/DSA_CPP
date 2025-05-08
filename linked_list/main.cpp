#include <iostream>
#include <memory>

using namespace std;

class Node
{
public:
    int value;
    Node *next = nullptr;

    Node(int value)
    {
        this->value = value;
    }

    Node(int value, Node *next)
    {
        this->value = value;
        this->next = next;
    }
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    LinkedList(): head(nullptr), tail(nullptr), length(0)
    {
    }

    LinkedList(int value)
    {
        Node *node = new Node(value);
        head = node;
        tail = node;
        length = 1;
    }

    ~LinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }


    // List manupulation functions
    void append(int value)
    {
        Node *node = new Node(value);
        if (length == 0) {
            tail = node;
            head = node;
            length += 1;
            return;
        }

        tail->next = node;
        tail = node;
        length += 1;
    }

    void prepend(int value) {
        Node *node = new Node(value);
        if(length == 0){
            head = node;
            tail = node;
            length ++;
            return;
        }

        node->next = head;
        head = node;
        length ++;
    }

    void deleteLast() {
        if(length == 0) return;
        if(length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            length --;
            return;
        }

        Node *oneBeforeLast = head;
        for(int i = 1; i < length - 1; i++) {
            oneBeforeLast = oneBeforeLast->next;
        }

        delete oneBeforeLast->next;
        oneBeforeLast->next = nullptr;
        tail = oneBeforeLast;
        length --;
    }

    void deleteFirst() {
        if(length == 0) return;
        if(length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            length --;
            return;
        }
        Node *nextHead = head->next;
        delete head;
        head = nextHead;
        length --;
    }

    Node* get(int index) {
        Node* emptyNode = new Node(-1);
        if(length == 0) return emptyNode;
        if(index >= length) return emptyNode;

        if(index == 0) return head;
        if(index == length - 1) return tail;

        Node* nodeToReturn = nullptr;
        Node* temp = head;
        for(int i = 0; i < index; i++) {
            temp = temp->next;
            nodeToReturn = temp;
        }

        return nodeToReturn;
    }

    // Print out functions
    void printHead()
    {
        cout << "Head: " << head->value << endl;
    }

    void printTail()
    {
        cout << "Tail: " << tail->value << endl;
    }

    void printLength()
    {
        cout << "Length: " << length << endl;
    }

    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    LinkedList *myLinked = new LinkedList(2);

    // myLinked->append(2);
    // myLinked->append(12);
    // myLinked->append(24);
    // myLinked->append(32);
    // myLinked->printList();
    // myLinked->deleteLast();
    // myLinked->printTail();
    // myLinked->prepend(144);
    // cout << "------------------" << endl;
    // myLinked->printList();
    // myLinked->printHead();
    // cout << "------------------" << endl;
    // myLinked->deleteFirst();
    // myLinked->printList();
    // myLinked->printHead();
    myLinked->append(4);
    myLinked->append(6);
    myLinked->append(8);
    myLinked->append(10);
    myLinked->append(12);
    myLinked->append(14);
    myLinked->append(16);
    myLinked->append(18);
    myLinked->append(20);

    Node* returnNode = myLinked->get(4);

    cout << "Found this node boss: " << returnNode->value << endl;
    delete myLinked;
    return 0;
}
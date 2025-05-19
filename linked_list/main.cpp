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
    LinkedList() : head(nullptr), tail(nullptr), length(0)
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
    // --- Insertion
    void insert(int index, int value)
    {
        if (index < 0 || index >= length)
            return;

        if (index == length - 1)
        {
            append(value);
            return;
        }

        if (index == 0)
        {
            prepend(value);
            return;
        }

        Node *prev = get(index - 1);
        if (!prev) 
            return;
        Node *newNode = new Node(value);
        newNode->next = prev->next;
        prev->next = newNode;
        length++;
    }

    void prepend(int value)
    {
        Node *node = new Node(value);
        if (length == 0)
        {
            head = node;
            tail = node;
            length++;
            return;
        }

        node->next = head;
        head = node;
        length++;
    }

    void append(int value)
    {
        Node *node = new Node(value);
        if (length == 0)
        {
            tail = node;
            head = node;
            length += 1;
            return;
        }

        tail->next = node;
        tail = node;
        length += 1;
    }

    // --- Deletion
    void deleteFirst()
    {
        if (length == 0)
            return;
        if (length == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            length--;
            return;
        }
        Node *nextHead = head->next;
        delete head;
        head = nextHead;
        length--;
    }

    void deleteLast()
    {
        if (length == 0)
            return;
        if (length == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            length--;
            return;
        }

        Node *oneBeforeLast = head;
        for (int i = 1; i < length - 1; i++)
        {
            oneBeforeLast = oneBeforeLast->next;
        }

        delete oneBeforeLast->next;
        oneBeforeLast->next = nullptr;
        tail = oneBeforeLast;
        length--;
    }

    void deleteAt(int index)
    {
        if (index < 0 || index >= length)
            return;

        if (index == length - 1)
        {
            return deleteLast();
        }

        if (index == 0)
        {
            return deleteFirst();
        }

        Node *nodeParent = get(index - 1);
        Node *nodeToDelete = nodeParent->next;

        nodeParent->next = nodeToDelete->next;
        delete nodeToDelete;
        length --;
    }

    // --- Get
    Node *get(int index)
    {
        if (length == 0 || index < 0 || index >= length)
            return nullptr;

        Node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }

        return temp;
    }

    void set(int index, int value)
    {
        Node *temp = get(index);
        if(!temp) return;
        temp->value = value;
    }

    // Reverse
    void reverse() {
        Node *temp = head;
        head = tail;
        tail = temp;

        Node *after = temp->next;
        Node *before = nullptr;

        for(int i = 0; i < length; i++) {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
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
        cout << "----- Printing the entire list ----" << endl;
        while (temp != nullptr)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
        cout << "----- End of list print ----" << endl;
    }
};

int main()
{
    LinkedList *myLinked = new LinkedList();
    
    myLinked->append(1);
    myLinked->append(2);
    myLinked->append(3);
    myLinked->append(4);
    myLinked->append(5);
    myLinked->append(6);
    myLinked->append(7);
    myLinked->append(8);
    myLinked->append(9);
    myLinked->append(10);
    myLinked->printList();
    myLinked->reverse();
    myLinked->printList();
    delete myLinked;
    return 0;
}
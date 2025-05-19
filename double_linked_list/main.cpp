#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next = nullptr;
    Node *prev = nullptr;

    Node(int value)
    {
        this->value = value;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

    ~DoublyLinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Add or modify item
    void prepend(int value) {
        Node* newNode = new Node(value);
        if(length == 0) {
            head = newNode;
            tail = newNode;
            length ++;
            return;
        }

        Node* temp = head;
        newNode->next = temp;
        head = newNode;
        temp->prev = newNode;
        length ++;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if(length == 0) {
            head = newNode;
            tail = newNode;
            length ++;
            return;
        }
        
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        length ++;
    }

    void set(int index, int value)
    {
        Node *temp = get(index);
        if(!temp) return;
        temp->value = value;
    }


    // Delete item
    void deleteFirst() {
        if(length == 0) return;
        if(length == 1) {
            delete tail;
            head = nullptr;
            tail = nullptr;
            length --;
            return;
        }
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        temp->next = nullptr;
        delete temp;
        length --;
    }

    void deleteLast() {
        if(length == 0) return;
        if(length == 1) {
            delete tail;
            head = nullptr;
            tail = nullptr;
            length --;
            return;
        }

        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
        length --;
    }

    // --- Get
    Node *get(int index)
    {
        if (length == 0 || index < 0 || index >= length)
            return nullptr;

        Node *temp = head;
        if(index < length / 2) {
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
        } else {
            temp = tail;
            for (int i = length - 1; i > index; i--)
            {
                temp = temp->prev;
            }
        }

        return temp;
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
    DoublyLinkedList* dll = new DoublyLinkedList();
    dll->append(2);
    dll->append(4);
    dll->append(6);
    dll->prepend(6);
    // dll->deleteLast();
    // dll->deleteFirst();
    cout << "Number: " << dll->get(2)->value << endl;
    cout << "Number: " << dll->get(1)->value << endl;
    dll->set(1, 1);
    dll->printList();
    return 0;
}
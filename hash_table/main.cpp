#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int value;
    string key;
    Node *next = nullptr;

    Node(int value)
    {
        this->value = value;
    }

    Node(string key, int value) : Node(key, value, nullptr)
    {
    }

    Node(string key, int value, Node *next)
    {
        this->key = key;
        this->value = value;
        this->next = next;
    }
};

class HashTable
{
private:
    static const int SIZE = 7;
    Node *dataMap[SIZE];

public:
    HashTable()
    {
    }

    int hash(string key)
    {
        int hash = 0;
        for (int i = 0; i < key.length(); i++)
        {
            int asciiValue = int(key[i]);
            hash = (hash + asciiValue * 23) % SIZE;
        }
        return hash;
    }

    void set(string key, int value)
    {
        int index = hash(key);
        Node *newNode = new Node(key, value);

        if (dataMap[index] == nullptr)
        {
            dataMap[index] = newNode;
        }
        else
        {
            Node *parentNode = dataMap[index];
            while (parentNode->next)
            {
                parentNode = parentNode->next;
            }

            parentNode->next = newNode;
        }
    }

    int get(string key)
    {
        int index = hash(key);
        Node *parentNode = dataMap[index];
        while (parentNode)
        {
            if (parentNode->key == key)
            {
                return parentNode->value;
            }

            parentNode = parentNode->next;
        }

        return -1;
    }

    vector<string> keys() {
        vector<string> allKeys;
        for (int i = 0; i < SIZE; i++) {
            Node *temp = dataMap[i];
            while(temp) {
                allKeys.push_back(temp->key);
                temp = temp->next;
            }
        }

        return allKeys;
    }

    void printTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << i << ":" << endl;
            if (dataMap[i])
            {
                Node *temp = dataMap[i];
                while (temp)
                {
                    cout << "   {" << temp->key << ", " << temp->value << "}" << endl;
                    temp = temp->next;
                }
            }
        }
    }
};

int main()
{
    HashTable *hst = new HashTable();
    hst->set("nails", 1000);
    hst->set("nuts", 1340);
    hst->set("lumber", 1400);
    hst->set("tile", 1200);
    hst->set("commander", 1200);
    vector<string> keys = hst->keys();
    cout << "Lumber: " << hst->get("lumber") << endl;
    cout << "Test: " << hst->get("Test") << endl;
    hst->printTable();
    return 0;
}
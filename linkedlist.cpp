
#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class LinkedList {
    Node* head;
    Node* tail; //using a tail pointer to make insertions easier
    // could also implement using while loop like in print function

    public:
    LinkedList() {
        head = nullptr;
    }

    void addNode(int data) {
        Node* node = new Node(data);
        if (head == nullptr) {
            head = node;
            tail = head;
        }
        else {
            tail->next = node;
            tail = node;
        }
    }

    void printList() {
        Node* curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << endl;
            curr = curr->next;
        }
    }

    bool findNode(int data) {
        Node* curr = head;
        while (curr != nullptr)
        {
            if (curr->data == data) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    bool deleteNode(int data) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr)
        {
            if (curr->data == data) {
                // delete
                if (prev == nullptr) {
                    head = curr->next;
                }
                else {
                    prev->next = curr->next;
                }

                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

};

int main(int argc, char* argv[]) {
    LinkedList linkedList = LinkedList();
    linkedList.addNode(2);
    linkedList.addNode(28);
    linkedList.addNode(-3);
    linkedList.addNode(-32);

    linkedList.printList();

    cout << "Find data 2: " << (linkedList.findNode(2) ? "found" : "not found") << endl;
    cout << "Find data -21: " << (linkedList.findNode(-21) ? "found" : "not found") << endl;

    cout << "Delete data 2: " << (linkedList.deleteNode(2) ? "deleted!" : "not found") << endl;
    linkedList.printList();

    cout << "Delete data -21: " << (linkedList.deleteNode(-21) ? "deleted!" : "not found") << endl;
    linkedList.printList();

    cout << "Delete data -3: " << (linkedList.deleteNode(-3) ? "deleted!" : "not found") << endl;
    linkedList.printList();

}

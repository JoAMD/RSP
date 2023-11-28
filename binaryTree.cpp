#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

    Node* addChild(int data, bool isLeft) {
        Node* node = new Node(data);
        if (isLeft) {
            this->left = node;
        }
        else {
            this->right = node;
        }
        return node;
    }
};

class BinaryTree {
    Node* root;

    public:
    BinaryTree(Node* root) {
        this->root = root;
    }

    void traversalInOrder() {
        if (root == NULL) {
            cout << "EMPTY\n";
            return;
        }
        traversalInOrder(root);
        cout << endl;
    }

    void traversalInOrder(Node* curr) {
        if (curr == NULL) {
            return;
        }

        traversalInOrder(curr->left);
        cout << curr->data << " ";
        traversalInOrder(curr->right);
    }

    bool search(int data) {
        if (root == NULL) {
            return false;
        }
        return searchInOrder(root, data);
    }

    bool searchInOrder(Node* curr, int data) {
        if (curr == NULL) {
            return false;
        }

        bool result = searchInOrder(curr->left, data);
        if (result) {
            return true;
        }
        if (curr->data == data) {
            return true;
        }
        return searchInOrder(curr->right, data);
    }

    // bool deleteNode(int data) {
    //     Node* prev = nullptr;
    //     Node* curr = head;
    //     while (curr != nullptr)
    //     {
    //         if (curr->data == data) {
    //             // delete
    //             if (prev == nullptr) {
    //                 head = curr->next;
    //             }
    //             else {
    //                 prev->next = curr->next;
    //             }

    //             delete curr;
    //             return true;
    //         }
    //         prev = curr;
    //         curr = curr->next;
    //     }
    //     return false;
    // }

};

int main(int argc, char* argv[]) {
    Node* root = new Node(10);
    BinaryTree* binaryTree = new BinaryTree(root);
    Node* l2 = root->addChild(22, true);
    l2->addChild(4, true)->addChild(5, false);
    l2->addChild(44, false)->addChild(11, false);
    root->addChild(212, false)->addChild(1, true);

    binaryTree->traversalInOrder();
    cout << "Searching -1: " << binaryTree->search(-1) << endl;
    cout << "Searching 10: " << binaryTree->search(10) << endl;
    cout << "Searching 22: " << binaryTree->search(22) << endl;
    cout << "Searching 5: " << binaryTree->search(5) << endl;
    cout << "Searching 212: " << binaryTree->search(212) << endl;
    cout << "Searching 4: " << binaryTree->search(4) << endl;
    cout << "Searching 44: " << binaryTree->search(44) << endl;
    cout << "Searching 11: " << binaryTree->search(11) << endl;
    cout << "Searching 1: " << binaryTree->search(1) << endl;
    cout << "Searching 555: " << binaryTree->search(555) << endl;
}
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* leftChild;
    Node* rightChild;

    Node(int data) {
        this->data = data;
        leftChild = nullptr;
        rightChild = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;
public:
    
    BinarySearchTree() {
		root = nullptr;
	}

    Node* insert(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }

        if (data < node->data) {
            node->leftChild = insert(node->leftChild, data);
        }
        else if (data > node->data) {
            node->rightChild = insert(node->rightChild, data);
        }

        return node;
    }


};

int main()
{
    cout << "Hello World!\n";
}


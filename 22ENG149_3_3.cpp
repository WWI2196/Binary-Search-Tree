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

    void insert(int data) {
		if (root == nullptr) {
			root = new Node(data);
			return;
		}
		
		Node* current = root;
		Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (data < current->data) {
                current = current->leftChild;
            }
            else if (data > current->data) {
                current = current->rightChild;
            }
            else return; // value already exists
        }

        if (data < parent->data) {
			parent->leftChild = new Node(data);
		}
		else {
			parent->rightChild = new Node(data);
		}
	}

    void remove(int data) {
        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr && current->data != data) {
			parent = current;
			if (data < current->data) {
				current = current->leftChild;
			}
			else {
				current = current->rightChild;
			}
		}

        if (current == nullptr) return; // value not found

        if (current->leftChild != nullptr && current->rightChild != nullptr) { // if the node has two children
            Node* replaceParent = current;
			Node* replace = current->rightChild;

			while (replace->leftChild != nullptr) { // find the minimum value in the right subtree
				replaceParent = replace;
				replace = replace->leftChild;
			}

			current->data = replace->data; // replace the current node with the minimum value
			parent = replaceParent; // set the parent to the parent of the minimum value
            current = replace; // set the current node to the minimum value

            if (replaceParent->leftChild == replace) { // remove the minimum value node
                replaceParent->leftChild = replace->rightChild;
            }
            else {
                replaceParent->rightChild = replace->rightChild;
            }

            delete replace;
            return;
        }

        // If the node has only one child or no children
        Node* child = (current->leftChild != nullptr) ? current->leftChild : current->rightChild;

        if (parent == nullptr) { // if the node to be deleted is the root node
            root = child;
        }
        else if (parent->leftChild == current) {
            parent->leftChild = child;
        }
        else {
            parent->rightChild = child;
        }

        delete current;
    }

    void printPreOrder() {
        Node* current = root;

        while (current != nullptr) {
            if (current->leftChild == nullptr) {
                cout << current->data << " ";
                current = current->rightChild;
            }
            else {
                Node* predecessor = current->leftChild;
                while (predecessor->rightChild != nullptr && predecessor->rightChild != current) {
                    predecessor = predecessor->rightChild;
                }

                if (predecessor->rightChild == nullptr) {
                    cout << current->data << " ";
                    predecessor->rightChild = current;
                    current = current->leftChild;
                }
                else {
                    predecessor->rightChild = nullptr;
                    current = current->rightChild;
                }
            }
        }
    }

};

int main()
{
    cout << "Hello World!\n";
}


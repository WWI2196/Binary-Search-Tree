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

    void insert(Node*& current, int data) {
        if (current == nullptr) {
            Node* node = new Node(data);
            current = node;
            return;
        }

        if (data < current->data) {
            insert(current->leftChild, data);
        }
        else if (data > current->data) {
            insert(current->rightChild, data);
        }
    }

    void insert(int data) {
		insert(root, data);
	}

    void remove(Node*& current, int data) {
        if (current == nullptr) {
            return;
        }

        if (data < current->data) {
            remove(current->leftChild, data);
        }
        else if (data > current->data) {
            remove(current->rightChild, data);
        }
        else {
            // Node to be deleted found
            if (current->leftChild == nullptr) {
                Node* rightSubtree = current->rightChild;
                delete current;
                current = rightSubtree;
            }
            else if (current->rightChild == nullptr) {
                Node* leftSubtree = current->leftChild;
                delete current;
                current = leftSubtree;
            }
            else {
                // Node with two children: Get the in-order successor (smallest in the right subtree)
                Node* successor = current->rightChild;
                while (successor->leftChild != nullptr) {
                    successor = successor->leftChild;
                }

                // Copy the in-order successor's data to this node
                current->data = successor->data;

                // Remove the in-order successor
                remove(current->rightChild, successor->data);
            }
        }
    }

    void remove(int data) {
        remove(root, data);
    }


    void printPreOrder(Node* current) {
        if (current == nullptr) {
            return;
        }

        cout << current->data << " ";
        printPreOrder(current->leftChild);
        printPreOrder(current->rightChild);
    }

    void printPreOrder() {
		printPreOrder(root);
	}

    void printInOrder(Node* current) {
        if (current == nullptr) {
            return;
        }
        printInOrder(current->leftChild);
        cout << current->data << " ";
        printInOrder(current->rightChild);
    }

    void printInOrder() {
		printInOrder(root);
	}

    void printPostOrder(Node* current) {
        if (current == nullptr) {
            return;
        }

        // Recursively print left subtree
        printPostOrder(current->leftChild);
        // Recursively print right subtree
        printPostOrder(current->rightChild);
        // Print the current node's value
        cout << current->data << " ";
    }

    void printPostOrder() {
        printPostOrder(root);
    }

    void search(int data) {
        Node* current = root;
        while (current != nullptr) {
            if (data < current->data) {
                current = current->leftChild;
            }
            else if (data > current->data) {
                current = current->rightChild;
            }
            else {
                cout << data << " exist in the tree." << endl;
            }
        }
        cout << data << " do not exist in the tree."<< endl;
    }

    int countNodes(Node* current) {
        if (current == nullptr) {
            return 0;
        }

        int leftCount = countNodes(current->leftChild);
        int rightCount = countNodes(current->rightChild);

        return 1 + leftCount + rightCount;
    }

    int countNodes() {
		return countNodes(root);
	}

    int getHeight(Node* current) {
        if (current == nullptr) {
            return 0; //  height 0 for an empty tree
        }

        int leftHeight = getHeight(current->leftChild);
        int rightHeight = getHeight(current->rightChild);

        int height;
        if (leftHeight > rightHeight) {
            height = leftHeight + 1;
        }
        else {
            height = rightHeight + 1;
        }

        return height;
    }

    int getHeight() {
        return getHeight(root);
    }

    int findSmallestValue() {
        Node* current = root;
        if (current == nullptr) {
            return -1; // Return -1 if tree is empty
        }

        // Traverse to the leftmost node
        while (current->leftChild != nullptr) {
            current = current->leftChild;
        }

        return current->data;
    }

    int findLargestValue() {
        Node* current = root;
        if (current == nullptr) {
            return -1; // Return -1 if tree is empty
        }

        // Traverse to the rightmost node
        while (current->rightChild != nullptr) {
            current = current->rightChild;
        }

        return current->data;
    }

    void deleteTree(Node* current) {
        if (current == nullptr) {
            return;
        }
        deleteTree(current->leftChild);
        deleteTree(current->rightChild);
        delete current;
    }

    void deleteTree() {
        deleteTree(root);
    }
};

int main()
{
    
}


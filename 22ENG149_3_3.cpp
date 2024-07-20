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

    Node* insert(Node* root, int data) {
        if (root == nullptr) {
            Node* node = new Node(data);
            return root = node;
        }

        if (data < root->data) {
            root->leftChild = insert(root->leftChild, data);
        }
        else if (data > root->data) {
            root->rightChild = insert(root->rightChild, data);
        }

        return root;
    }

    void insert(int data) {
		insert(root, data);
	}

    Node* remove(Node* root, int data) {
        if (root == nullptr) {
            return nullptr;
        }

        if (data < root->data) {
            root->leftChild = remove(root->leftChild, data);
        }
        else if (data > root->data) {
            root->rightChild = remove(root->rightChild, data);
        }
        else {
            // Node to be deleted found
            if (root->leftChild == nullptr) {
                Node* rightSubtree = root->rightChild;
                delete root;
                return rightSubtree;
            }
            else if (root->rightChild == nullptr) {
                Node* leftSubtree = root->leftChild;
                delete root;
                return leftSubtree;
            }

            // Node with two children: Get the in-order successor (smallest in the right subtree)
            Node* successor = root->rightChild;
            while (successor->leftChild != nullptr) {
                successor = successor->leftChild;
            }

            // Copy the in-order successor's data to this node
            root->data = successor->data;

            // Remove the in-order successor
            root->rightChild = remove(root->rightChild, successor->data);
        }

        return root;
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

    int getHeight(Node* root) {
        if (root == nullptr) {
            return 0; //  height 0 for an empty tree
        }

        int leftHeight = getHeight(root->leftChild);
        int rightHeight = getHeight(root->rightChild);

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

    void deleteTree(Node* root) {
        if (root == nullptr) {
            return;
        }
        deleteTree(root->leftChild);
        deleteTree(root->rightChild);
        delete root;
    }

    void deleteTree() {
        deleteTree(root);
    }

    bool search(int data) {
        Node* current = root;
        while (current != nullptr) {
            if (data < current->data) {
                current = current->leftChild;
            }
            else if (data > current->data) {
                current = current->rightChild;
            }
            else {
                return true;
            }
        }
        return false;
    }

    int findMinValue() {
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

    int findMaxValue() {
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

};

int main()
{
    cout << "Hello World!\n";
}


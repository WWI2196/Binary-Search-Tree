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
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
        }
        else {
            remove(root, data);
        }
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
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
        }
        else {
            cout << "Pre-order: ";
            printPreOrder(root);
            cout << endl;
        }
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
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
        }
        else {
            cout << "In-order: ";
            printInOrder(root);
            cout << endl;
        }
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
        if (root == nullptr) {
			cout << "Tree is empty." << endl;
		}
		else {
            cout << "Post-order: ";
			printPostOrder(root);
            cout << endl;
		}
    }

    void print() {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
        }
        else {
            printPreOrder();
            printInOrder();
            printPostOrder();
            
        }
    }

    void search(int data) {
        Node* current = root;

        if(root == nullptr) {
			cout << "Tree is empty." << endl;
			return;
		}

        while (current != nullptr) {
            if (data < current->data) {
                current = current->leftChild;
            }
            else if (data > current->data) {
                current = current->rightChild;
            }
            else {
                cout << data << " exists in the tree." << endl;
                return;
            }
        }
        cout << data << " do not exists in the tree."<< endl;
    }

    int countNodes(Node* current) {
        if (current == nullptr) {
            return 0;
        }

        int leftCount = countNodes(current->leftChild);
        int rightCount = countNodes(current->rightChild);

        return 1 + leftCount + rightCount;
    }

    void countNodes() {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
        }
        else {
			cout << "Number of nodes in the tree: "<<countNodes(root);
            cout << endl;
		}
	}

    int getHeight(Node* current) {
        if (current == nullptr) {
            return -1; // Height of an empty tree is -1
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

    void printHeight() {
        if(root == nullptr) {
			cout << "Tree is empty." << endl;
		} else {
			cout << "Height of the tree is " << getHeight(root) << endl;
		}
    }

    void findSmallestValue() {
        if (root == nullptr) {
            cout << "Tree is empty" << endl; // Return -1 if tree is empty
            return;
        }

        Node* current = root;
        // Traverse to the leftmost node
        while (current->leftChild != nullptr) {
            current = current->leftChild;
        }

        cout << "Smallest value is " << current->data << endl;
    }

    void findLargestValue() {
        if (root == nullptr) {
            cout << "Tree is empty" << endl; // Return -1 if tree is empty
            return;
        }
        Node* current = root;
       

        // Traverse to the rightmost node
        while (current->rightChild != nullptr) {
            current = current->rightChild;
        }

        cout << "Largest value is " << current->data << endl;
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
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
        }
        else {
            deleteTree(root);
        }
    }
};

int main()
{
    BinarySearchTree tree;

    int values[] = { 4 ,8 ,10, 2, 7 };
    //int values[] = { 349, 825, 492, 190, 746, 312, 591, 837, 664, 280, 174, 954, 723, 565, 198, 407, 951, 621, 379, 503, 714, 276, 832, 468, 902, 134, 579, 215};
    int size = sizeof(values) / sizeof(values[0]);

    for(int value: values) {
		tree.insert(value);
	}

    tree.print();

    tree.printHeight();
    tree.findSmallestValue();
    tree.findLargestValue();
    tree.search(11);
    tree.countNodes();

    tree.remove(8);
  
    tree.printPreOrder();
    tree.printInOrder();
    tree.printPostOrder();
    tree.search(2);
    tree.deleteTree();


    return 0;
}


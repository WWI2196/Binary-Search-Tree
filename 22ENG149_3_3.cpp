#include <iostream>
using namespace std;

class Node { // Node class to represent each node in the binary search tree
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
    
    BinarySearchTree() { // Constructor to initialize the root node
		root = nullptr;
	}

    void insert(Node*& current, int data) { // Recursive function to insert a new node in the tree
        if (current == nullptr) { // If the tree is empty, create a new node and assign it to the root
            Node* node = new Node(data);
            current = node;
            return;
        }

        if (data < current->data) { // If the data is less than the current node's data, insert it in the left subtree
            insert(current->leftChild, data);
        }
        else if (data > current->data) { // If the data is greater than the current node's data, insert it in the right subtree
            insert(current->rightChild, data);
        }
    }

    void insert(int data) { // Function to call the recursive insert function
		insert(root, data); 
	}

    void remove(Node*& current, int data) { // Recursive function to remove a node from the tree
        if (current == nullptr) {
            return;
        }

        if (data < current->data) { 
            remove(current->leftChild, data);
        }
        else if (data > current->data) {
            remove(current->rightChild, data);
        }
        else { // Node to be deleted found
            if (current->leftChild == nullptr) { // Node with one child or no child
                Node* rightSubtree = current->rightChild;
                delete current;
                current = rightSubtree;
            }
            else if (current->rightChild == nullptr) { // Node with one child or no child
                Node* leftSubtree = current->leftChild;
                delete current;
                current = leftSubtree;
            }
            else { // Node with two children: Get the in-order successor (smallest in the right subtree)
                Node* successor = current->rightChild;
                while (successor->leftChild != nullptr) {
                    successor = successor->leftChild;
                }

                current->data = successor->data; // Copy the in-order successor's data to the node

                remove(current->rightChild, successor->data); // Remove the in-order successor
            }
        }
    }

    void remove(int data) { // Function to call the recursive remove function
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
        }
        else {
            remove(root, data);
        }
    }


    void printPreOrder(Node* current) { // Recursive function to print the tree in pre-order
        if (current == nullptr) {
            return;
        }

        cout << current->data << " ";
        printPreOrder(current->leftChild);
        printPreOrder(current->rightChild);
    }

    void printPreOrder() { // Function to call the recursive printPreOrder function
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
        }
        else {
            cout << "Pre-order: ";
            printPreOrder(root);
            cout << endl;
        }
	}

    void printInOrder(Node* current) { // Recursive function to print the tree in in-order
        if (current == nullptr) {
            return;
        }
        printInOrder(current->leftChild);
        cout << current->data << " ";
        printInOrder(current->rightChild);
    }

    void printInOrder() { // Function to call the recursive printInOrder function
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
        }
        else {
            cout << "In-order: ";
            printInOrder(root);
            cout << endl;
        }
	}

    void printPostOrder(Node* current) { // Recursive function to print the tree in post-order
        if (current == nullptr) {
            return;
        }
        printPostOrder(current->leftChild); // Recursively print left subtree
        printPostOrder(current->rightChild);  // Recursively print right subtree
        cout << current->data << " "; // Print the current node's value
    }

    void printPostOrder() { // Function to call the recursive printPostOrder function
        if (root == nullptr) {
			cout << "Tree is empty." << endl;
		}
		else {
            cout << "Post-order: ";
			printPostOrder(root);
            cout << endl;
		}
    }

    void print() { // Function to print the tree in pre-order, in-order, and post-order
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
        }
        else {
            printPreOrder();
            printInOrder();
            printPostOrder();
            
        }
    }

    void search(int data) { // Function to search for a value in the tree and print whether it exists or not
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

    int countNodes(Node* current) { // Recursive function to count the number of nodes in the tree
        if (current == nullptr) {
            return 0;
        }

        int leftCount = countNodes(current->leftChild);
        int rightCount = countNodes(current->rightChild);

        return 1 + leftCount + rightCount;
    }

    void countNodes() { // Function to call the recursive countNodes function
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
        }
        else {
			cout << "Number of nodes in the tree: "<<countNodes(root);
            cout << endl;
		}
	}

    int getHeight(Node* current) { // Recursive function to get the height of the tree
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

    void printHeight() { // Function to call the recursive getHeight function
        if(root == nullptr) {
			cout << "Tree is empty." << endl;
		} else {
			cout << "Height of the tree is " << getHeight(root) << endl;
		}
    }

    void findSmallestValue() { // Function to find the smallest value in the tree
        if (root == nullptr) { // If the tree is empty, print the message
            cout << "Tree is empty" << endl; 
            return;
        }
        Node* current = root;

        while (current->leftChild != nullptr) { // Traverse to the leftmost node
            current = current->leftChild;
        }

        cout << "Smallest value is " << current->data << endl;
    }

    void findLargestValue() { // Function to find the largest value in the tree
        if (root == nullptr) {
            cout << "Tree is empty" << endl; 
            return;
        }
        Node* current = root;
       
        while (current->rightChild != nullptr) { // Traverse to the rightmost node
            current = current->rightChild;
        }

        cout << "Largest value is " << current->data << endl;
    }

    void deleteTree(Node* current) { // Recursive function to delete the tree
        if (current == nullptr) {
            return;
        }
        deleteTree(current->leftChild);
        deleteTree(current->rightChild);
        delete current;
    }

    void deleteTree() { // Function to call the recursive deleteTree function
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


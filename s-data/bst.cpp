#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}

Node* findMax(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    
    while (root->right != nullptr) {
        root = root->right;
    }
    
    return root;
}

Node* findMin(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    
    while (root->left != nullptr) {
        root = root->left;
    }
    
    return root;
}

int main() {
    Node* root = nullptr;

    int choice;
    do {
        std::cout << "Choose an option:\n"
                  << "1. Insert a value\n"
                  << "2. Find maximum\n"
                  << "3. Find minimum\n"
                  << "4. Display tree\n"
                  << "0. Exit\n";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                root = insertNode(root, value);
                break;
            }
            case 2: {
                Node* maxNode = findMax(root);
                if (maxNode != nullptr) {
                    std::cout << "Maximum value: " << maxNode->data << std::endl;
                } else {
                    std::cout << "Tree is empty." << std::endl;
                }
                break;
            }
            case 3: {
                Node* minNode = findMin(root);
                if (minNode != nullptr) {
                    std::cout << "Minimum value: " << minNode->data << std::endl;
                } else {
                    std::cout << "Tree is empty." << std::endl;
                }
                break;
            }
            case 4:
                std::cout << "Inorder traversal: ";
                inorderTraversal(root);
                std::cout << std::endl;
                break;
            case 0:
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}

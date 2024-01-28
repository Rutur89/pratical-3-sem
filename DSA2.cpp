#include <iostream>
using namespace std;

const int MAX_NAME_SIZE = 20;
const int MAX_CHILDREN = 20;

struct Node {
    char name[MAX_NAME_SIZE];
    int count;
    struct Node* child[MAX_CHILDREN];
};

class BookTree {
private:
    Node* root;

public:
    BookTree() {
        root = NULL;
    }

    void createNode(Node*& currentNode) {
        currentNode = new Node();
        cout << "Enter " << currentNode->name << " name: ";
        cin.ignore();
        cin.getline(currentNode->name, MAX_NAME_SIZE);

        do {
            cout << "Enter the number of " << currentNode->name << " children: ";
            cin >> currentNode->count;

            if (currentNode->count < 0 || currentNode->count > MAX_CHILDREN) {
                cout << "Invalid input. Number of children should be between 0 and " << MAX_CHILDREN << ". Try again." << endl;
            }
        } while (currentNode->count < 0 || currentNode->count > MAX_CHILDREN);

        for (int i = 0; i < currentNode->count; i++) {
            createNode(currentNode->child[i]);
        }
    }

    void displayNode(Node* currentNode, int depth = 0) {
        if (currentNode) {
            for (int i = 0; i < depth; i++) {
                cout << "  "; // Adjusted spacing for better hierarchy
            }
            cout << "|-- " << currentNode->name << endl;

            for (int i = 0; i < currentNode->count; i++) {
                displayNode(currentNode->child[i], depth + 1);
            }
        }
    }

    void create() {
        cout << "Let's create the book structure." << endl;
        createNode(root);
    }

    void display() {
        cout << "**********************BOOK INFORMATION**********************" << endl;
        displayNode(root);
    }
};

int main() {
    BookTree book;
    book.create();
    cout << "\nYour book structure:\n";
    book.display();

    return 0;
}

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* create(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void preorder(Node* root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void insert(Node* root, int value) {
    char dir;
    cout << "Insert " << value << " to left or right of " << root->data << "? (l/r): ";
    cin >> dir;

    if (dir == 'l') {
        if (root->left == nullptr)
            root->left = create(value);
        else
            insert(root->left, value);
    } 
    else {
        if (root->right == nullptr)
            root->right = create(value);
        else
            insert(root->right, value);
    }
}

bool search(Node* root, int key) {
    if (root == nullptr)
        return false;
    if (root->data == key)
        return true;
    return search(root->left, key) || search(root->right, key);
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return nullptr;

    if (root->left != nullptr && root->left->data == key) {
        delete root->left;
        root->left = nullptr;
        cout << "Deleted " << key << endl;
        return root;
    }

    if (root->right != nullptr && root->right->data == key) {
        delete root->right;
        root->right = nullptr;
        cout << "Deleted " << key << endl;
        return root;
    }

    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);

    return root;
}

int main() {
    Node* root = nullptr;
    int choice, val;

    do {
        cout << "\n\n--- Binary Tree Menu ---\n";
        cout << "1. Create Root\n";
        cout << "2. Insert Node\n";
        cout << "3. Search Node\n";
        cout << "4. Delete Node\n";
        cout << "5. Display Preorder Traversal\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (root == nullptr) {
                cout << "Enter root value: ";
                cin >> val;
                root = create(val);
            } else {
                cout << "Root already created.\n";
            }
            break;

        case 2:
            if (root == nullptr) {
                cout << "Create root first!\n";
            } else {
                cout << "Enter value to insert: ";
                cin >> val;
                insert(root, val);
            }
            break;

        case 3:
            if (root == nullptr)
                cout << "Tree empty.\n";
            else {
                cout << "Enter value to search: ";
                cin >> val;
                if (search(root, val))
                    cout << val << " found in tree.\n";
                else
                    cout << val << " not found.\n";
            }
            break;

        case 4:
            if (root == nullptr)
                cout << "Tree empty.\n";
            else {
                cout << "Enter value to delete (only leaf deletion supported): ";
                cin >> val;
                root = deleteNode(root, val);
            }
            break;

        case 5:
            cout << "Preorder Traversal: ";
            preorder(root);
            cout << endl;
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}

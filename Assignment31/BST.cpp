#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root_rrl, int value_rrl) {
    if (root_rrl == NULL)
        return createNode(value_rrl);
    if (value_rrl < root_rrl->data)
        root_rrl->left = insert(root_rrl->left, value_rrl);
    else if (value_rrl > root_rrl->data)
        root_rrl->right = insert(root_rrl->right, value_rrl);
    return root_rrl;
}

Node* findMin(Node* root_rrl) {
    while (root_rrl && root_rrl->left != NULL)
        root_rrl = root_rrl->left;
    return root_rrl;
}

Node* deleteNode(Node* root_rrl, int key_rrl) {
    if (root_rrl == NULL)
        return root_rrl;
    if (key_rrl < root_rrl->data)
        root_rrl->left = deleteNode(root_rrl->left, key_rrl);
    else if (key_rrl > root_rrl->data)
        root_rrl->right = deleteNode(root_rrl->right, key_rrl);
    else {
        if (root_rrl->left == NULL && root_rrl->right == NULL) {
            delete root_rrl;
            return NULL;
        } else if (root_rrl->left == NULL) {
            Node* temp_rrl = root_rrl->right;
            delete root_rrl;
            return temp_rrl;
        } else if (root_rrl->right == NULL) {
            Node* temp_rrl = root_rrl->left;
            delete root_rrl;
            return temp_rrl;
        } else {
            Node* temp_rrl = findMin(root_rrl->right);
            root_rrl->data = temp_rrl->data;
            root_rrl->right = deleteNode(root_rrl->right, temp_rrl->data);
        }
    }
    return root_rrl;
}

void levelwiseDisplay(Node* root_rrl) {
    if (root_rrl == NULL) return;
    queue<Node*> q_rrl;
    q_rrl.push(root_rrl);
    while (!q_rrl.empty()) {
        Node* curr_rrl = q_rrl.front();
        q_rrl.pop();
        cout << curr_rrl->data << " ";
        if (curr_rrl->left) q_rrl.push(curr_rrl->left);
        if (curr_rrl->right) q_rrl.push(curr_rrl->right);
    }
}

int main() {
    Node* root_rrl = NULL;
    int choice_rrl, val_rrl;
    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Levelwise Display\n4. Exit\nEnter choice: ";
        cin >> choice_rrl;
        switch (choice_rrl) {
            case 1:
                cout << "Enter value: ";
                cin >> val_rrl;
                root_rrl = insert(root_rrl, val_rrl);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> val_rrl;
                root_rrl = deleteNode(root_rrl, val_rrl);
                break;
            case 3:
                cout << "Levelwise display: ";
                levelwiseDisplay(root_rrl);
                cout << endl;
                break;
            case 4:
                return 0;
        }
    }
}

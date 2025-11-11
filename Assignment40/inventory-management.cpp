#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Product {
    int code;
    string name;
    float price;
    int quantity;
    string dateReceived;
    string expirationDate;
    Product *left, *right;
};

bool isExpired(const string &expiry, const string &current) {
    return expiry < current;
}

Product* createProduct() {
    Product* newProd = new Product();
    cout << "\nEnter Product Code: ";
    cin >> newProd->code;
    cin.ignore();

    cout << "Enter Product Name: ";
    getline(cin, newProd->name);

    cout << "Enter Price: ";
    cin >> newProd->price;

    cout << "Enter Quantity in Stock: ";
    cin >> newProd->quantity;
    cin.ignore();

    cout << "Enter Date Received (YYYY-MM-DD): ";
    getline(cin, newProd->dateReceived);

    cout << "Enter Expiration Date (YYYY-MM-DD): ";
    getline(cin, newProd->expirationDate);

    newProd->left = newProd->right = nullptr;
    return newProd;
}

Product* insert(Product* root, Product* newProd) {
    if (!root)
        return newProd;
    if (newProd->name < root->name)
        root->left = insert(root->left, newProd);
    else if (newProd->name > root->name)
        root->right = insert(root->right, newProd);
    else
        cout << "Duplicate product name not allowed.\n";
    return root;
}


void inorder(Product* root) {
    if (root) {
        inorder(root->left);
        cout << "Code: " << root->code << ", Name: " << root->name
             << ", Price: " << root->price << ", Quantity: " << root->quantity
             << ", Expiry: " << root->expirationDate << endl;
        inorder(root->right);
    }
}

Product* findMin(Product* node) {
    while (node && node->left)
        node = node->left;
    return node;
}

Product* deleteByCode(Product* root, int code) {
    if (!root) return nullptr;

    if (code < root->code)
        root->left = deleteByCode(root->left, code);
    else if (code > root->code)
        root->right = deleteByCode(root->right, code);
    else {
        if (!root->left) {
            Product* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Product* temp = root->left;
            delete root;
            return temp;
        }
        Product* temp = findMin(root->right);
        root->code = temp->code;
        root->name = temp->name;
        root->price = temp->price;
        root->quantity = temp->quantity;
        root->dateReceived = temp->dateReceived;
        root->expirationDate = temp->expirationDate;
        root->right = deleteByCode(root->right, temp->code);
    }
    return root;
}

Product* deleteExpired(Product* root, const string &currentDate) {
    if (!root) return nullptr;

    root->left = deleteExpired(root->left, currentDate);
    root->right = deleteExpired(root->right, currentDate);

    if (isExpired(root->expirationDate, currentDate)) {
        cout << "Deleting expired product: " << root->name << endl;
        root = deleteByCode(root, root->code);
    }
    return root;
}

int main() {
    Product* root = nullptr;
    int choice;

    while (true) {
        cout << "\n--- Product Inventory Management ---\n";
        cout << "1. Insert Product\n";
        cout << "2. Display All Products (Inorder)\n";
        cout << "3. Delete Product by Code\n";
        cout << "4. Delete All Expired Products\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Product* p = createProduct();
                root = insert(root, p);
                break;
            }
            case 2:
                cout << "\nAll Products:\n";
                inorder(root);
                break;

            case 3: {
                int code;
                cout << "\nEnter Product Code to Delete: ";
                cin >> code;
                root = deleteByCode(root, code);
                break;
            }

            case 4: {
                string currentDate;
                cout << "\nEnter Current Date (YYYY-MM-DD): ";
                cin.ignore();
                getline(cin, currentDate);
                root = deleteExpired(root, currentDate);
                break;
            }

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }
    return 0;
}

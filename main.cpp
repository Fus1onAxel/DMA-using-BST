#include <iostream>
#include <string>
using namespace std;

class Iphone {
public:
    string serialNumber;
    string name;
    string color;
    string model;

    Iphone(string sn, string n, string c, string m)
        : serialNumber(sn), name(n), color(c), model(m) {}

    // Comparison operators
    bool operator<(const Iphone& other) const {
        return serialNumber < other.serialNumber;
    }

    bool operator>(const Iphone& other) const {
        return serialNumber > other.serialNumber;
    }

    bool operator==(const Iphone& other) const {
        return serialNumber == other.serialNumber;
    }
};


struct TreeNode {
    Iphone data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(Iphone val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    // Helper function for insertion
    TreeNode* insert(TreeNode* node, Iphone iphone) {
        if (node == nullptr)
            return new TreeNode(iphone);

        if (iphone < node->data)  // Uses the < operator
            node->left = insert(node->left, iphone);
        else if (iphone > node->data)  // Uses the > operator
            node->right = insert(node->right, iphone);

        return node;
    }

    // Helper function for searching
    TreeNode* search(TreeNode* node, string serialNumber) {
        if (node == nullptr || node->data.serialNumber == serialNumber)
            return node;

        if (serialNumber < node->data.serialNumber)
            return search(node->left, serialNumber);

        return search(node->right, serialNumber);
    }

    // Helper function for removal
    TreeNode* remove(TreeNode* node, string serialNumber) {
        if (node == nullptr) return node;

        if (serialNumber < node->data.serialNumber)
            node->left = remove(node->left, serialNumber);
        else if (serialNumber > node->data.serialNumber)
            node->right = remove(node->right, serialNumber);
        else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data.serialNumber);
        }

        return node;
    }

    // Helper function to find the minimum value node
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    // Helper function to print the tree in-order
    void inorder(TreeNode* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data.serialNumber << " - " << root->data.name << " - " << root->data.color << " - " << root->data.model << endl;
            inorder(root->right);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(Iphone iphone) {
        root = insert(root, iphone);
    }

    TreeNode* search(string serialNumber) {
        return search(root, serialNumber);
    }

    void remove(string serialNumber) {
        root = remove(root, serialNumber);
    }

    void printTree() {
        inorder(root);
    }
};
/*
int main() {
    BST bst;

    Iphone iphone1("SN123", "iPhone 12", "Black", "A2172");
    Iphone iphone2("SN456", "iPhone 13", "Blue", "A2633");
    Iphone iphone3("SN789", "iPhone 14", "Red", "A2634");
    Iphone iphone4("SN101", "iPhone 11", "White", "A2223");

    bst.insert(iphone1);
    bst.insert(iphone2);
    bst.insert(iphone3);
    bst.insert(iphone4);

    cout << "BST In-Order Traversal (Before Removal):" << endl;
    bst.printTree();

    cout << "\nSearching for iPhone with Serial Number SN456:" << endl;
    TreeNode* result = bst.search("SN456");
    if (result != nullptr) {
        cout << "Found: " << result->data.name << " " << result->data.color << endl;
    } else {
        cout << "Not found!" << endl;
    }

    cout << "\nRemoving iPhone with Serial Number SN123:" << endl;
    bst.remove("SN123");

    cout << "\nBST In-Order Traversal (After Removal):" << endl;
    bst.printTree();

    return 0;
}
*/
int main() 
{
    BST bst;

    Iphone iphone1("SN123", "iPhone 12", "Black", "A2172");
    Iphone iphone2("SN456", "iPhone 13", "Blue", "A2633");
    Iphone iphone3("SN789", "iPhone 14", "Red", "A2634");
    Iphone iphone4("SN101", "iPhone 11", "White", "A2223");

    bst.insert(iphone1);
    bst.insert(iphone2);
    bst.insert(iphone3);
    bst.insert(iphone4);

    while (true) 
    {
        cout << "\nMenu:\n";
        cout << "1. Add Iphone\n";
        cout << "2. Remove Iphone\n";
        cout << "3. search Iphone\n";
        cout << "4. print tree\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;


        if (choice == 5)
            break;

        switch (choice) 
        {
        case 1: 
        {
            string serialNumber, name, color, model;
            cout << "Enter serial number:" << endl;
            cin >> serialNumber;
            cout << "Enter Name:" << endl; 
            cin >> name;
            cout << "Enter color:" << endl;
            cin >> color;
            cout << "Enter model:" << endl;
            cin >> model;
            Iphone iphone1(serialNumber, name, color, model);
            break;
        }
        case 2: 
        {
            string serialNumber;
            cout << "Enter serial number to retrieve: ";
            cin >> serialNumber;
            bst.remove(serialNumber);
            break;
        }
        case 3: 
        {
            string serialNumber;
            cout << "Enter serial number to print: " << endl;
            cin >> serialNumber;
            TreeNode* result = bst.search(serialNumber);
                if (result != nullptr) {
                    cout << "Found: " << result->data.name << " " << result->data.color << endl;
                } else {
                    cout << "Not found!" << endl;
            }
            break;
        }
        case 4: 
        {
            bst.printTree();
            break;
        }

        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
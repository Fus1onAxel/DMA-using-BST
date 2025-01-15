#include <iostream>
#include <string>

struct iPhone {
    std::string model;
    std::string color;
    int storage;

    iPhone(std::string m, std::string c, int s)
        : model(m), color(c), storage(s) {}

    bool operator<(const iPhone& other) const {
        if (model != other.model) return model < other.model;
        if (color != other.color) return color < other.color;
        return storage < other.storage;
    }

    bool operator==(const iPhone& other) const {
        return model == other.model && color == other.color && storage == other.storage;
    }
};

struct Node {
    iPhone data;
    Node* left;
    Node* right;

    Node(iPhone d) : data(d), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, iPhone data) {
        if (!node) return new Node(data);
        if (data < node->data)
            node->left = insert(node->left, data);
        else if (node->data < data)
            node->right = insert(node->right, data);
        return node;
    }

    Node* search(Node* node, const iPhone& target) {
        if (!node || node->data == target)
            return node;
        if (target < node->data)
            return search(node->left, target);
        return search(node->right, target);
    }

    Node* remove(Node* node, const iPhone& target) {
        if (!node) return node;

        if (target < node->data)
            node->left = remove(node->left, target);
        else if (node->data < target)
            node->right = remove(node->right, target);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

    void inOrderTraversal(Node* node) {
        if (!node) return;
        inOrderTraversal(node->left);
        std::cout << "Model: " << node->data.model
                  << ", Color: " << node->data.color
                  << ", Storage: " << node->data.storage << "GB\n";
        inOrderTraversal(node->right);
    }

public:
    BST() : root(nullptr) {}

    void insert(iPhone data) { root = insert(root, data); }
    Node* search(const iPhone& target) { return search(root, target); }
    void remove(const iPhone& target) { root = remove(root, target); }
    void display() { 
        if (!root) std::cout << "No iPhones in the inventory.\n";
        else inOrderTraversal(root); 
    }
};

void displayMenu() {
    std::cout << "\n=== iPhone Inventory Menu ===\n";
    std::cout << "1. Add iPhone\n";
    std::cout << "2. Search for iPhone\n";
    std::cout << "3. Remove iPhone\n";
    std::cout << "4. Display all iPhones\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    BST iphoneTree;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        if (choice == 1) {
            std::string model, color;
            int storage;
            std::cout << "Enter model: ";
            std::cin >> model;
            std::cout << "Enter color: ";
            std::cin >> color;
            std::cout << "Enter storage (GB): ";
            std::cin >> storage;
            iphoneTree.insert({model, color, storage});
            std::cout << "iPhone added successfully!\n";
        } else if (choice == 2) {
            std::string model, color;
            int storage;
            std::cout << "Enter model: ";
            std::cin >> model;
            std::cout << "Enter color: ";
            std::cin >> color;
            std::cout << "Enter storage (GB): ";
            std::cin >> storage;
            Node* found = iphoneTree.search({model, color, storage});
            if (found)
                std::cout << "Found: " << found->data.model << ", " 
                          << found->data.color << ", " 
                          << found->data.storage << "GB\n";
            else
                std::cout << "iPhone not found.\n";
        } else if (choice == 3) {
            std::string model, color;
            int storage;
            std::cout << "Enter model: ";
            std::cin >> model;
            std::cout << "Enter color: ";
            std::cin >> color;
            std::cout << "Enter storage (GB): ";
            std::cin >> storage;
            iphoneTree.remove({model, color, storage});
            std::cout << "iPhone removed (if it existed).\n";
        } else if (choice == 4) {
            std::cout << "Current inventory:\n";
            iphoneTree.display();
        } else if (choice == 5) {
            std::cout << "Exiting program.\n";
        } else {
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
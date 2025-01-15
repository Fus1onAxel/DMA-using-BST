#include "BST.hpp"
#include "utilities.hpp"

int main() {
    BST bst;

    bst.insert(Iphone("SN123", "iPhone 12", "Black", "A2172"));
    bst.insert(Iphone("SN456", "iPhone 13", "Blue", "A2633"));
    bst.insert(Iphone("SN789", "iPhone 14", "Red", "A2634"));
    bst.insert(Iphone("SN101", "iPhone 11", "White", "A2223"));

    while (true) {
        clearScreen(); // Refresh the screen before displaying the menu

        cout << "\nMenu:\n";
        cout << "1. Add iPhone\n";
        cout << "2. Remove iPhone\n";
        cout << "3. Search iPhone\n";
        cout << "4. Print Tree\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number between 1 and 5.";
            waitForEnter();
            continue;
        }

        switch (choice) {
        case 1: {
            string serialNumber, name, color, model;
            cout << "Enter serial number: ";
            cin >> serialNumber;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter color: ";
            cin >> color;
            cout << "Enter model: ";
            cin >> model;
            bst.insert(Iphone(serialNumber, name, color, model));
            cout << "iPhone added successfully!";
            waitForEnter();
            break;
        }
        case 2: {
            string serialNumber;
            cout << "Enter serial number to remove: ";
            cin >> serialNumber;
            bst.remove(serialNumber);
            cout << "iPhone removed (if it existed).";
            waitForEnter();
            break;
        }
        case 3: {
            string serialNumber;
            cout << "Enter serial number to search: ";
            cin >> serialNumber;
            TreeNode* result = bst.search(serialNumber);
            if (result != nullptr) {
                cout << "Found: " << result->data.name << " (" << result->data.color << ", " << result->data.model << ")";
            } else {
                cout << "Not found!";
            }
            waitForEnter();
            break;
        }
        case 4: {
            cout << "Current Inventory:\n";
            bst.printTree();
            waitForEnter();
            break;
        }
        case 5:
            return 0;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 5.";
            waitForEnter();
        }
    }

    return 0;
}

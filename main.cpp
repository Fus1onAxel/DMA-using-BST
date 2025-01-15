#include "BST.hpp"
#include "utilities.hpp"

int main() {
    BST bst;

    while (true) {
        clearScreen(); // Refresh the screen before displaying the menu

        cout << "\nMenu:\n";
        cout << "1. Add iPhone\n";
        cout << "2. Remove iPhone\n";
        cout << "3. Search iPhone\n";
        cout << "4. Print Inventory\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number between 1 and 5.";
            waitForEnter1();
            continue;
        }

        switch (choice) {
        case 1: {
            string serialNumber, name, color, model;
            cin.ignore(); // Clear the input buffer to handle leftover '\n'
            cout << "Enter serial number: ";
            getline(cin, serialNumber);
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter color: ";
            getline(cin, color);
            cout << "Enter model: ";
            getline(cin, model);
            bst.insert(Iphone(serialNumber, name, color, model));
            cout << "iPhone added successfully!";
            waitForEnter1();
            break;
        }
        case 2: {
            string serialNumber;
            cout << "Enter serial number to remove: ";
            cin >> serialNumber;
            bst.remove(serialNumber);
            cout << "iPhone removed (if it existed).";
            waitForEnter1();
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
            waitForEnter1();
            break;
        }
        case 4: {
            cout << "Current Inventory:\n";
            bst.printTree();
            waitForEnter1();
            break;
        }
        case 5:
            return 0;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 5.";
            waitForEnter1();
        }
    }

    return 0;
}

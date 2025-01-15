#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
using namespace std;

void waitForEnter() {
    cout << "\nPress Enter to go back to the menu...";
    cin.ignore(); // Clear the input buffer
    cin.get();    // Wait for Enter key
}

void waitForEnter1() {
    cout << "\nPress Enter to go back to the menu...";
    cin.get();    // Wait for Enter key
}
void clearScreen() {
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Unix/Linux/Mac
#endif
}

#endif // UTILITIES_H

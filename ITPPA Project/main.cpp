#ifndef FILE_FUNCTIONS_H
#define FILE_FUNCTIONS_H

void runQuestion1();
void runQuestion2();
void runQuestion3();
void runQuestion4();

#endif

#include <iostream>
using namespace std;

int main() {

    int choice;
    cout << " Question 1: Cafeteria Order System\n Question 2: Shopping Cart Program\n Question 3: Average Score Students\n Question 4: Bank Account Management System\n" << endl;
    cout << "Enter a number (1-4) to select which Question to run: " << endl;
    cin >> choice;
    switch (choice) {
    case 1:
        runQuestion1();
        break;
    case 2:
        runQuestion2();
        break;
    case 3:
        runQuestion3();
        break;
    case 4:
        runQuestion4();
        break;
    default:
        cout << "Invalid choice.\n" << endl;

    }
    return 0;
}
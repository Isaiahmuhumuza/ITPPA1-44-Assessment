#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
#include <fstream>
using namespace std;


void runQuestion2() {
	//Question 2
	ofstream MyFile("ShoppingList.txt");

	string fullName;
	cout << "Enter your Name and Surname: " << endl;
	getline(cin, fullName);
	string selection;
	int quantity = 0;
	double totalCost = 0;

	string menuItems[8] =
	{
		"coffee",
		"sandwich",
		"salad",
		"juice",
		"muffin",
		"pizza slice",
		"soup",
		"burger",
	};

	int prices[8] =
	{
		15,
		30,
		25,
		10,
		20,
		35,
		18,
		40,
	};

	for (int i = 0; i < 8; i++){
		cout << menuItems[i] << " - " << "R" << prices[i] << ".00\n" << endl;
	}


	while (true) {
		cout << "Select Item from the menu? (Leave empty when done)" << endl;
		getline(cin, selection);
		auto search = find(begin(menuItems), end(menuItems), selection);
		if (selection.empty()) {
			cout << "Thanks for Shopping." << endl;
			break; 
		}
		if (search != end(menuItems)) {
			int index = search - begin(menuItems);
			cout << "How many would you like to buy? " << endl;
			cin >> quantity;
			cin.ignore();
			totalCost = totalCost + (prices[index] * quantity);
		}
		else {
			cout << "\nWe dont serve that here." << endl;

		}
	}

	if (totalCost > 200){
		totalCost *= 0.95;
	}
	else {
		totalCost = totalCost;
	}

	if (MyFile.is_open()) {
		MyFile << "Customer Name: " << fullName << "\nTotal bill: R" << totalCost;
		cout << "You Final Bill will be R" << totalCost << "\n The bill has been written to 'ShoppingList.txt'." << endl;
		MyFile.close();
	}
	else {
		
		cout << "Error: Could not open the file for writing." << endl;
	}
}
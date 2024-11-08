#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
#include <fstream>
using namespace std;


void runQuestion1() {
	int items;
	//Question 1
	// • Prompt the user to enter their name and surname

	ofstream MyFile("CafeteriaBill.txt");


	string fullName;
	cout << "Enter your Name and Surname: " << endl;
	getline(cin, fullName);

	// • Display the menu and prompt the user to select up to 8 items.

	cout << "How many items would you like to order? " << endl;
	cin >> items;
	cin.ignore();

	cout << "Cafertia Menu";
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

	// • For each selection, validate the input and calculate the total bill by summing the prices of the selected items.
	// • Apply a 10% discount if the total bill exceeds R100.
	// • Display the total bill, discount applied (if applicable), and the final bill after discount.

	//string* userSelection = new string[items];
	double bill = 0;

	for (int i = 0; i < items;) {
	
		cout << "Pick "<< items - i << " items from menu : " << endl;
		string entry;
		getline(cin, entry);
		auto search = find(begin(menuItems), end(menuItems), entry);

		if (search != end(menuItems)) {
			//userSelection[i] = entry;
			int index = search - begin(menuItems);
			bill += prices[index];
			i++;
		}
		else {
			cout << "\nWe dont serve that here." << endl;

		}
	}

	//delete[] userSelection;

	if (bill > 100) {
		bill *= 0.9;
	}
	else {
		bill = bill;
	}

	if (MyFile.is_open()) {
		
		MyFile << "Customer Name: " << fullName << "\nTotal bill: R" << bill;
		cout << "The bill has been written to 'CafeteriaBill.txt'." << endl;
		MyFile.close();

	}
	else {
		
		cout << "Error: Could not open the file for writing." << endl;
	}

}
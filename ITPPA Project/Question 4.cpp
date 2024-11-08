#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

void createAccount(string& name, int& accountNumber, double& initialDeposit, double& balance) {
	cout << "Enter your name: " << endl;
	getline(cin, name);
	cout << "Enter your Account Number: " << endl;
	cin >> accountNumber;
	do {
		cout << "Enter your initial deposit (must be greater than 0): ";
		cin >> initialDeposit;

		if (initialDeposit <= 0) {
			cout << "Initial deposit must be greater than 0. Please try again." << endl;
		}
	} while (initialDeposit <= 0);

	balance += initialDeposit;
	cout << "\nAccount created successfully!" << endl; 
}

void depositMoney(double& deposit, double& balance) {
	do {
		cout << "Enter your deposit amount (must be greater than 0): ";
		cin >> deposit;

		if (deposit <= 0) {
			cout << "Deposit must be greater than 0. Please try again." << endl;
		}
	} while (deposit <= 0);
	
	balance += deposit;
	cout << "You have deposited R" << deposit << endl;
}

void withdrawMoney(int& withdrawl,double& balance) {
	do {
		cout << "Enter withdrawl amount (must be greater than 0): ";
		cin >> withdrawl;

		if (withdrawl <= 0 || withdrawl >= balance) {
			cout << "Invalid withdrawl amount. Please try again." << endl;
		}
	} while (withdrawl <= 0 || withdrawl >= balance );
	
	balance -= withdrawl;
	cout << "You have withdrawed R" << withdrawl << endl;
	
}

void checkBalance(const double& balance) {
	cout << "Avaliable Balance: R" << balance << endl;
}

void displayAccountDetails(const string& name, const int& accountNumber, const double& balance) {
	cout <<
		"\n--- Account Details ---"
		"\nAccount Holder: " << name <<
		"\nAccount Number: " << accountNumber <<
		"\nAvailable Balance: R" << balance << endl;
}

void runQuestion4(){
	bool active = true;
	int entry = 0;
	double balance = 0;
	string name = "";
	int accountNumber = 0;
	double initialDeposit = 0;

	do {
		cout << "\n--- Bank Account Management System ---" << endl;
		cout <<
			"1. Create Account"
			"\n2. Deposit Money"
			"\n3. Withdraw Money"
			"\n4. Check Balance"
			"\n5. Display Account Details"
			"\n6. Exit\n" << endl;
		cout << "Enter your choice  (1-6): " << endl;
		cin >> entry;
		cin.ignore();
		switch (entry) {
			case 1: {
				createAccount(name, accountNumber, initialDeposit, balance);
				break;
			}
			case 2: {	
				double deposit;
				depositMoney(deposit, balance);
				break;
			}
			case 3: {
				if (balance <= 0) {
					cout << "You have no money in your account, please first deposit" << endl;
				}
				else {
					int withdrawl;
					withdrawMoney(withdrawl, balance);
				}
				break;
			}
			case 4: {
				checkBalance(balance);
				break;
			}
			case 5: {
				displayAccountDetails(name, accountNumber, balance);
				break;
			}
			case 6: {
				active = false;
				cout << "Exiting the system. Goodbye!" << endl;
				break;
			}
		}

	} while (active);
}
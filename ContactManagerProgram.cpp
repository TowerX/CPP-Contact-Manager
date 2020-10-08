/*
Author: Jay Torres
Date: March 16, 2020
Purpose: The Contact Manager Program: It allows you to create, search, sort, and view contacts on a list similar to a phone book application.
FileName: ContactManagerProgram.cpp
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Constant variable holding the array size for easy access to modifications.
const int SIZE = 3;
// Array declaration and initialized as an empty array
string firstName[SIZE] = { "" };
string lastName[SIZE] = { "" };
string phoneNumber[SIZE] = { "" };
string emailAddress[SIZE] = { "" };
// Variable holding the search input data.
string searchInput = "";

// Functions
////////////

// Get input from the user
void inputData() {
	cout << "Please enter " << SIZE << " contacts." << endl;
	cout << "--------------------------------------------------------------" << endl;

	// Fill the array with data
	for (int index = 0; index < SIZE; index++) {
		cout << "Enter the contact first name:" << endl;
		cin >> firstName[index];
		cout << "Enter " << firstName[index] << ", last name:" << endl;
		cin >> lastName[index];
		cout << "Enter the phone number for: " << firstName[index] << endl;
		cin >> phoneNumber[index];
		cout << "Enter " << firstName[index] << ", " << lastName[index] << " email address:" << endl;
		cin >> emailAddress[index];
	}
}

// Perform a search based on user input
// Search by first name, last name and, phone number. Email is not searchable on this program.
void searchData() {
	// Get user input and store the value on searchInput variable.
	cout << "Enter a name to search" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cin >> searchInput;

	// Search the actual array with provided input.
	for (int index = 0; index < SIZE; index++) {
		if (firstName[index] == searchInput || lastName[index] == searchInput || phoneNumber[index] == searchInput) {
			cout << "\nContact Found! The information is below" << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << setw(2) << "FirstName: " << setw(15) << firstName[index] << " | " << "LastName: " << setw(10) << lastName[index] << " | " << "PhoneNumber: " << setw(13) << phoneNumber[index] << " | " << "EmailAddress: " << setw(15) << emailAddress[index] << endl;
			cout << "\n\n";
			break;
		}
		else {
			// If contact is not found
			cout << "Contact not found!." << endl;
			cout << "\n\n";
		}
	}
}

// Display the data
void printData() {
	// Print the input data after sorting
	cout << "\nPhone Contacts" << endl;
	cout << "--------------------------------------------------------------" << endl;
	for (int index = 0; index < SIZE; index++) {
		cout << setw(2) << "FirstName: " << setw(15) << firstName[index] << " | " << "LastName: " << setw(10) << lastName[index] << " | " << "PhoneNumber: " << setw(13) << phoneNumber[index] << " | " << "EmailAddress: " << setw(15) << emailAddress[index] << endl;
	}
	cout << "\n\n";
}

// Descending sort function using the bubble sort technique. Based on phones array.
void sortDescending(string fNames[], string lNames[], string emails[], string phones[], int size) {
	int maxElement;
	int index;
	for (maxElement = size - 1; maxElement >= 0; maxElement--) {
		for (index = 0; index <= maxElement - 1; index++) {
			if (phones[index] < phones[index + 1]) {
				swap(phones[index], phones[index + 1]);
				swap(fNames[index], fNames[index + 1]);
				swap(lNames[index], lNames[index + 1]);
				swap(emails[index], emails[index + 1]);
			}
		}
	}
}

// Ascending sort function using the bubble sort technique. Based on phones array.
void sortAscending(string fNames[], string lNames[], string emails[], string phones[], int size) {
	int maxElement;
	int index;
	for (maxElement = size - 1; maxElement >= 0; maxElement--) {
		for (index = 0; index <= maxElement - 1; index++) {
			if (phones[index] > phones[index + 1]) {
				swap(phones[index], phones[index + 1]);
				swap(fNames[index], fNames[index + 1]);
				swap(lNames[index], lNames[index + 1]);
				swap(emails[index], emails[index + 1]);
			}
		}
	}
}

// Swap function required for the bubble sort
void swap(string a, string b) {
	string temp;
	temp = a;
	a = b;
	b = temp;
}
////////////////
// End Functions

int main()
{	
	// Store the menu choice selected by the user. This will be used as the switch case number.
	int menuChoice;

	// Main Menu Loop - While return is true => continue otherwise exit the program.
	while (1) {
		cout << "<><>Contact Manager Program<><>" << endl;
		cout << "\n\nPress 1 to Input data:" << endl;
		cout << "Press 2 to Sort data in ASCENDING order:" << endl;
		cout << "Press 3 to Sort data in DESCENDING order:" << endl;
		cout << "Press 4 to Print data:" << endl;
		cout << "Press 5 to Search data:" << endl;
		cout << "Press 6 to Exit the program:" << endl;
		// Prompt the user for the menu choice based on the menu option numbers.
		cin >> menuChoice;
		cout << "\n\n" << endl;

		switch (menuChoice) {
		case 1:
			cin.ignore();
			inputData();
			break;

		case 2:
			//Sort ASCENDING and Print data
			cout << "\nData sorted in Ascending order" << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << "\n\n";
			sortAscending(firstName, lastName, emailAddress, phoneNumber, SIZE);
			printData();
			break;
		case 3:
			// Sort DESCENDING and Print data
			cout << "\nData sorted in Descending order" << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << "\n\n";
			sortDescending(firstName, lastName, emailAddress, phoneNumber, SIZE);
			printData();
			break;
		case 4:
			// Print data
			printData();
			break;
		case 5:
			// Search data
			searchData();
			break;
		case 6:
			// Exit program by returning false to the while loop
			return 0;
			break;
		default:
			cout << "Do nothing" << endl;
			break;
		}
	}
}
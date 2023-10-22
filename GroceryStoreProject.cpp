//Brian Carman, 10.12.23, CS 210

#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <string>
#include <iomanip>
#include "GroceryStore.h"

using namespace std;

int main()
{
	// Variable declarations

	GroceryStore groceryList; //Instance of GroceryStore
	vector<string> groceryItems; //Stores data from input file
	int menuChoice; //Determines what action the user wants the program to do
	string newWord; //Used in menu option 1, as the target word to match
	bool exitFunction = false; //When the user enters 4 in the while loop when prompted for menu input, set to true and exits the while loop

	//Getting input from file groceryList.txt
	groceryItems = groceryList.GetFileInput();
	
	// Displaying menu and getting user input for choice
	groceryList.DisplayMenu();

	cout << endl;
	cout << "Please enter your choice: ";
	cin >> menuChoice;
	cout << endl;


	while (cin.fail()) {

		cin.clear(); // clear input buffer to restore cin to a usable state
		cin.ignore(INT_MAX, '\n'); // ignore last input
		cout << "You can only enter numbers." << endl;
		cout << endl;
		cout << "Please enter a number 1-4: ";
		cin >> menuChoice;
		cout << endl;

	}
	
	//Iterates until the user enters 4 when prompted for menuChoice
	while (!exitFunction) {

		// Prints the frequency of one item in the cart
		if (menuChoice == 1) {
			groceryList.ChoiceOne(groceryItems);
		}

		// Prints the frequency of every item in the cart
		else if (menuChoice == 2) {
			groceryList.ChoiceTwo(groceryItems);
		}

		// Prints the frequency of every item in the cart, with frq represented as asterisks (i can't pronounce that word)
		else if (menuChoice == 3) {
			groceryList.ChoiceThree(groceryItems);
		}

		// Exits the loop
		else if (menuChoice == 4) {
			exitFunction = true;
		}

		else {
			cout << "Invalid entry or item not in cart. Please try again. " << endl;
		}

		//If the user hasn't entered 4, the menu will be displayed again, prompt for more menuChoice input, loop will reiterate
		if (!exitFunction) {
			cout << endl << endl << endl;
			groceryList.DisplayMenu();
			cout << endl;
			cout << "Please enter your next choice: ";
			cin >> menuChoice;
			cout << endl;
		}

		//Re-prompts if input isn't of type int
		while (cin.fail()){
				cin.clear(); // clear input buffer to restore cin to a usable state
				cin.ignore(INT_MAX, '\n'); // ignore last input
				cout << "You can only enter numbers." << endl;
				cout << endl;
				cout << "Please enter a number 1-4: ";
				cin >> menuChoice;
				cout << endl;
		}
	}

	cout << "Thank you for shopping with Corner Grocer! Please come again. " << endl;

	groceryList.CreateOutputFile(groceryItems);

	return 0;
}
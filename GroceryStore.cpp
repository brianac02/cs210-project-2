//Brian Carman, 10.12.23, CS 210

#include "GroceryStore.h"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <utility>

using namespace std;

GroceryStore::GroceryStore() {
	groceryItems.clear();
}

// Function that matches an entered word to one of the ones in vector, returning how many times it was found.
pair<string, int> GroceryStore::countSpecificWord(const vector<string>& groceryItems, const string& targetWord) {
	int count = 0;
	this->targetWord = targetWord; //private variable assinged w value of paramter
	this->groceryItems = groceryItems; //private vector assigned w values of parameter

	//increments count of count each time word matches targetWord in groceryItems
	for (const string& word : this-> groceryItems) {
		if (word == this-> targetWord) {
			++count;
		}
	}
	return make_pair(this-> targetWord, count);
}



// Function that outputs all items bought with their respective quantities
unordered_map<string, int> GroceryStore::countOccurrences(const vector<string>& groceryItems) {
	unordered_map<string, int> wordCount; //stores each item and its frq
	this->groceryItems = groceryItems; //private vector assigned w paramter values

	//each time word matches / repeats in groceryItems, increase wordCount at [word]
	for (const string& word : this->groceryItems) {
		++wordCount[word];
	}
	return wordCount;
}

// Displays choice menu
void GroceryStore::DisplayMenu() {
	cout << "====================================" << endl;
	cout << "        *** Corner Grocer ***       " << endl;
	cout << "====================================" << endl;
	cout << "(1)  Check Number Bought of One Item" << endl;
	cout << "(2)  Check Your Full Receipt" << endl;
	cout << "(3)  Print a Histogram (Graph)" << endl;
	cout << "(4)  Exit" << endl;
}

void GroceryStore::ChoiceOne(vector<string> groceryItems) {
	vector<string> newVector;
	string newWord;

	newVector = groceryItems;

	cout << "Please enter the item you're looking to find, with both capitalization and pluralization. " << endl;
	cout << "Options are: " << endl << endl << "-Spinach" << endl << "-Radishes" << endl << "-Potatoes" << endl << "-Pears" << endl;
	cout << "-Peas" << endl << "-Broccoli" << endl << "-Cranberries" << endl << "-Cucumbers" << endl << "-Peaches" << endl;
	cout << "-Zucchini" << endl << "-Cantaloupe" << endl << "-Beets" << endl << "-Pumpkins" << endl << "-Apples" << endl;
	cout << "-Cauliflower" << endl << "-Onions" << endl << "-Yams" << endl << "-Celery" << endl << "-Limes" << endl << "-Garlic" << endl << endl;

	cin >> newWord;
	cout << endl;

	// Checks to make sure that string newWord exists in vector groceryItems
	if (find(newVector.begin(), newVector.end(), newWord) != newVector.end()) {

		pair<string, int> result = countSpecificWord(newVector, newWord);

		cout << "Number of " << result.first << " in cart: " << result.second << endl;
	}
	else {
		cout << "Invalid entry. Please try again. " << endl;
	}
}

void GroceryStore::ChoiceTwo(vector<string> groceryItems){
	vector<string> newVector;

	newVector = groceryItems;

	unordered_map<string, int> newResult = countOccurrences(newVector);

	cout << "ITEM        | QUANTITY" << endl;
	cout << "----------------------" << endl;
	for (const auto& pair : newResult) {
		cout << setw(11) << left << pair.first << " |" << pair.second << endl;

	}
}

void GroceryStore::ChoiceThree(vector<string> groceryItems){
	vector<string> newVector;

	newVector = groceryItems;

	unordered_map<string, int> newResult = countOccurrences(newVector);

	cout << "ITEM        | QUANTITY" << endl;
	cout << "----------------------" << endl;
	for (const auto& pair : newResult) {
		cout << setw(11) << left << pair.first << " |";
		for (int i = 0; i < pair.second; i++) {
			cout << "*";
		}
		cout << endl;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~";
}

void GroceryStore::CreateOutputFile(vector<string> groceryItems) {
	//Create output stream
	ofstream outFS;

	//Opening file frequency.dat
	outFS.open("frequency.dat");
	if (!outFS.is_open()) {
		cout << "Could not open file frequency.dat. " << endl;
	}

	//Call countOccurrences once more to write its data to the file, which stores each item and its frequency
	unordered_map<string, int> newResult = countOccurrences(groceryItems);
	for (const auto& pair : newResult) {
		outFS << pair.first << " " << pair.second << endl;
	}
	//Close output stream
	outFS.close();
}

vector<string> GroceryStore::GetFileInput() {
	// Opening file groceryList.txt to store the vector of grocery items
	vector<string> groceryItems;

	ifstream inFS;
	inFS.open("groceryList.txt");
	if (!inFS.is_open()) {
		cout << "Unable to open file. Please try again." << endl;
	}

	else {
		string item;

		// Gets input from the file until end of file is reached, stores it in vector groceryItems
		while (!inFS.eof()) {
			getline(inFS, item);
			groceryItems.push_back(item);
		}
		inFS.close();
	}
	return groceryItems;
}
#ifndef GROCERY_STORE_H
#define GROCERY_STORE_H

//Brian Carman, 10.12.23, CS 210

#include <string>
#include <vector>
#include <map>

#include <unordered_map>

using namespace std;

class GroceryStore
{
public:
	// Default constructor
	GroceryStore();

	// Function that matches an entered word to one of the ones in vector, returning how many times it was found
	pair<string, int> countSpecificWord(const vector<string>& groceryItems, const string& targetWord);

	// Function that outputs all items bought with their respective quantities
	unordered_map<string, int> countOccurrences(const vector<string>& groceryItems);

	// Function that displays menu
	void DisplayMenu();

	// Governs actions for choosing "1" from display menu
	void ChoiceOne(vector<string> groceryItems);

	// Governs actions for choosing "2" from display menu
	void ChoiceTwo(vector<string> groceryItems);

	// Governs actions for choosing "3" from display menu
	void ChoiceThree(vector<string> groceryItems);

	// Creates a backup file for data in vector groceryItems (data in input file) store as frequency.dat
	void CreateOutputFile(vector<string> groceryItems);

	// Gets input from file groceryList.txt
	vector<string> GetFileInput();


private:
	// Vector that stores the foods in the file
	vector<string> groceryItems;

	//Stores a user-entered word in Menu Option 1
	string targetWord;
	

};

#endif

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "ShopList.h"
#define FILENAME "ShopList/ShopList.txt"

using namespace std;

class ShopList {
public:
	ShopList();
	void LineModifyDelete(int, const string);
	int ViewShopList();
	void ModifyShopList();
};

ShopList::ShopList() {
	ifstream file(FILENAME);
	if (!file) {
		cout << "Unable to find ShopList.\n" << endl;
		ofstream file(FILENAME);
		file << "Shopping list\n" << "--------------------------------------\n" << endl;
		file.close();
		cout << "ShopList created.\n" << endl;
	}
	else {
		file.close();
		cout << "ShopList found.\n" << endl;
	}
}

void ShopList::LineModifyDelete(int lineNum, const string newContent = "") {
	ifstream inFile(FILENAME);

	ofstream outFile("ShopList/temp.txt");
	if (!outFile.is_open()) {
		cout << "Error creating temp file." << endl;
		inFile.close();
		return;
	}
	lineNum += 2;
	string line;
	int lineNumber = 1;
	bool lineFound = false;

	while (getline(inFile, line)) {
		if (lineNumber == lineNum) {
			lineFound = true;
			if (!newContent.empty()) {
				outFile << newContent << endl;
			}
		}
		else {
			outFile << line << endl;
		}
		lineNumber++;
	}
	if (!lineFound && newContent.empty()) {
		cout << "Line " << lineNum - 2 << " not found." << endl;
		remove("temp.txt");
		return;
	}
	else if (!lineFound && !newContent.empty()) {
		outFile << newContent << std::endl;
	}

	inFile.close();
	outFile.close();

	remove(FILENAME);
	rename("ShopList/temp.txt", FILENAME);

	if (newContent.empty()) {
		cout << "Line deleted successfully.\n" << endl;
	}
	else {
		cout << "Line modified/added successfully.\n" << endl;
	}
}

int ShopList::ViewShopList() {
	ifstream file(FILENAME);

	string line;
	int lineNumber = 1;

	for (int i = 0; i < 2; ++i) {
		if (!getline(file, line)) {
			file.close();
			return 0;
		}
	}
	lineNumber = 1;
	while (getline(file, line)) {
		cout << lineNumber << ": " << line << endl;
		lineNumber++;
	}
	file.close();
	cout << "\n";
	return 1;
}

void ShopList::ModifyShopList() {
	while (true) {
		if (ShopList::ViewShopList() == 0) {
			cout << "The list is empty!\n" << endl;
			return;
		}

		int lineNum;
		char operation;
		cout << "Which line do you want to modify?(or cancel = 0): ";
		cin >> lineNum;
		if (lineNum == 0)
		{
			cout << "Returning...\n" << endl;
			return;
		}
		while (true)
		{
			cout << "What operation to do, [d]elete or [m]odify?(or cancel = 0): ";
			cin >> operation;
			if (operation != 'd' && operation != 'm' && operation != '0') {
				cout << "Unknown operation!\n" << endl;
				continue;
			}
			else {
				break;
			}
		}

		if (operation == '0')
		{
			cout << "Returning...\n" << endl;
			return;
		}
		else if (operation == 'd') {
			ShopList::LineModifyDelete(lineNum);
			break;
		}
		else if (operation == 'm') {
			string newContent;
			cout << "Enter the new content for the line: ";
			cin >> newContent;
			ShopList::LineModifyDelete(lineNum, newContent);
			break;
		}

	}
}

void shopList() {
	int menu;
	ShopList shp = ShopList();

	while (true) {
		cout << "Please select what do you want to do.\n" << "1. View shop list\n" << "2. Configure shop list\n" << "3. Exit shop list\n" << endl;
		cin >> menu;
		system("cls");
		switch (menu) {
		case 1:
			if (shp.ViewShopList() == 0) {
				cout << "The list is empty!\n" << endl;
			};
			break;
		case 2:
			shp.ModifyShopList();
			break;
		case 3:
			cout << "Returning to main menu...\n";
			return;
			break;
		default:
			cout << "Unknown command! Please try again!\n";
			break;
		}
	}
}
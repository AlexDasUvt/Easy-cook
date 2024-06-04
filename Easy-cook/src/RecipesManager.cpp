#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <nlohmann/json.hpp>
#include "RecipesManager.h"
#include "MyList.h"

#define RECIPEDB "RecipesDB/RecipesDB.json"
using namespace std;
using json = nlohmann::json;

RecipeManager::RecipeManager() {
	loadRecipes();
}

void RecipeManager::loadRecipes() {
	ifstream file(RECIPEDB);
	if (file.is_open()) {
		file >> data;
		file.close();
		fileLoaded = true;
		countTags();
	}
	else {
		fileLoaded = false;
		cout << "Could not open the file!" << endl;
	}
}

void RecipeManager::countTags() {
	if (!data.contains("recipes") || !data["recipes"].is_array()) {
		cout << "The JSON structure is not as expected!" << endl;
		return;
	}

	for (const auto& recipe : data["recipes"]) {
		if (recipe.contains("tags") && recipe["tags"].is_array()) {
			for (const auto& tag : recipe["tags"]) {
				tag_count[tag.get<string>()]++;
			}
		}
	}
}

void RecipeManager::displayTags() {
	cout << "Possible tags for search:" << endl;
	for (const auto& entry : tag_count) {
		cout << entry.first << ": " << entry.second << endl;
	}
}

vector<string> RecipeManager::getInputTags() {
	cout << "Enter up to 3 tags to search for (separated by spaces): ";
	vector<string> input_tags;
	string tag;
	while (cin >> tag && input_tags.size() < 3) {
		input_tags.push_back(tag);
		if (cin.peek() == '\n') break;
	}
	return input_tags;
}

void RecipeManager::searchRecipes(const vector<string>& input_tags) {
	unordered_set<string> search_tags(input_tags.begin(), input_tags.end());

	cout << "\nSearch results:" << endl;
	bool found = false;
	for (const auto& recipe : data["recipes"]) {
		if (recipe.contains("tags") && recipe["tags"].is_array()) {
			for (const auto& tag : recipe["tags"]) {
				if (search_tags.count(tag.get<string>()) > 0) {
					cout << "Name: " << recipe["name"].get<string>()
						<< ", ID: " << recipe["id"].get<int>()
						<< ", Tags: ";
					for (const auto& t : recipe["tags"]) {
						cout << t.get<string>() << " ";
					}
					cout << endl;
					found = true;
					break;
				}
			}
		}
	}

	if (!found) {
		cout << "No recipes found with the given tags." << endl;
	}
}

bool RecipeManager::searchAgain() {
	while (true) {
		cout << "Do you want to search again? (y/n): ";
		char choice;
		cin >> choice;
		if (choice == 'n' || choice == 'N') {
			return false;
		}
		else if (choice == 'y' || choice == 'Y') {
			cout << "\n";
			return true;
		}
		else {
			cout << "Unknown command! Please retry!" << endl;
		}
	}
}

void RecipeManager::ViewRecipe(int id) {
	ofstream csvFile("MyList.csv", ios::app);
	if (!csvFile.is_open()) {
		cout << "Could not open the CSV file!" << endl;
		return;
	}

	for (const auto& recipe : data["recipes"]) {
		if (recipe["id"].get<int>() == id) {
			csvFile << recipe["id"].get<int>() << "," << recipe["name"].get<string>() << "\n";
			cout << "Recipe saved to My List" << endl;
			break;
		}
	}

	csvFile.close();
}

void RecipeManager::run() {
	if (!fileLoaded) {
		cout << "Could not open the file!" << endl;
		return;
	}

	while (true) {
		system("cls");
		displayTags();

		vector<string> input_tags = getInputTags();

		searchRecipes(input_tags);

		cout << "Do you want to save any recipe? Enter ID (or 'n' to skip): ";
		string input;
		cin >> input;
		if (input != "n" && input != "N") {
			int id = stoi(input);
			ViewRecipe(id);
		}
		if (!searchAgain()) {
			cout << "Returning to main menu..." << "\n" << endl;
			break;
		}
	}
}
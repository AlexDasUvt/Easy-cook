#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <stdlib.h>
#include <nlohmann/json.hpp>
#include "RecipesFunc.h"

#define RECIPEDB "RecipesDB/RecipesDB.json"
using namespace std;
using json = nlohmann::json;


void RecipesFunc() {
	ifstream file(RECIPEDB);
	unordered_map<string, int> tag_count;

	if (!file.is_open()) {
		cout << "Could not open the file!" << endl;
		return;
	}
	json data;
	file >> data;
	file.close();

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

	while (true)
	{
		// UNDONE search function
		cout << "Possible tags for search:" << endl;
		for (const auto& entry : tag_count) {
			cout << entry.first << ": " << entry.second << endl;
		}

	}
}
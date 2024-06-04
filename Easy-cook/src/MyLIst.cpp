#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "MyList.h"
#define MY_LIST "MyList.csv"

using namespace std;
using json = nlohmann::json;

void MyList::ShowMyList() {
    ifstream file(MY_LIST);
    if (!file.is_open()) {
        cout << "Unable to open file recipes.csv" << endl;
        return;
    }

    string line;
    bool isEmpty = true;
    cout << "\n";
    while (getline(file, line)) {
        if (isEmpty && !line.empty()) {
            isEmpty = false;
        }
        cout << line << endl;
    }
    if (isEmpty) {
        cout << "My list is empty" << endl;
    }
    cout << "\n";
    file.close();
}

void MyList::ViewRecipe(int id) {
    ifstream file("RecipesDB/RecipesDB.json");
    if (!file.is_open()) {
        cout << "Unable to open recipes database file" << endl;
        return;
    }

    json recipes;
    file >> recipes;
    file.close();

    if (!recipes.contains("recipes") || !recipes["recipes"].is_array()) {
        cout << "The JSON structure is not as expected!" << endl;
        return;
    }
    system("cls");
    bool found = false;
    for (const auto& recipe : recipes["recipes"]) {
        if (recipe["id"].get<int>() == id) {
            cout << "Recipe ID: " << id << endl;
            cout << "Name: " << recipe["name"].get<string>() << endl;
            cout << "Ingredients: " << recipe["ingredients"].dump(4) << endl;
            cout << "Instructions: " << recipe["steps"].get<string>() << endl;
            found = true;
            break;
        }
    }
    cout << "\n";

    if (!found) {
        cout << "Recipe with ID " << id << " not found." << endl;
    }
}

void MyList::run() {
    
    while (true) {
        int menu;
        cout << "What operation do you want to do?\n1. Show favorite recipes\n2. Display recipe by ID\n0. Return to main menu" << endl;
        cin >> menu;
        switch (menu)
        {
        case 0:
            system("cls");
            cout << "Returning..." << endl;
            return;
        case 1:
            ShowMyList();
            break;
        case 2:
            int id;
            cout << "Please enter ID of the recipe to show: ";
            cin >> id;
            ViewRecipe(id);
            break;
        default:
            cout << "Unknown command! Please try again." << endl;
            break;
        }
    }
}
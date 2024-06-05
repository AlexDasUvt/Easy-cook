#include <iostream>
#include <string>
#include <stdlib.h>
#include ".\src\ShopList.h"
#include ".\src\RecipesManager.h"
#include ".\src\MyList.h"
using namespace std;

int main()
{
	int menu;

	while (true) {
		/*
			Infinite loop representing a menu.
		*/
		cout << "Welcome to Easy-cook!\n" << "Which option you would like to choose?\n" << "1. Recipes menu\n" << "2. Shop list\n" << "3. My lists\n" << "4. Exit\n" << endl;
		cin >> menu;
		system("cls");
		switch (menu) {
		case 1: {
			RecipeManager rm = RecipeManager();
			rm.run();
			break;
		}
		case 2: {
			shopList();
			break;
		}
		case 3: {
			MyList ml = MyList();
			ml.run();
			break;
		}
		case 4: {
			cout << "Exiting...";
			return 0;
			break;
		}
		default: {
			cout << "Unknown command! Please try again!\n";
			break;
		}
		}
	}
}

#include <iostream>
#include <string>
#include <stdlib.h>
#include ".\src\ShopList.h"
using namespace std;

int main()
{
	int menu;
	while (true) {
		cout << "Welcome to Easy-cook!\n" << "Which option you would like to choose?\n" << "1. Recipes menu\n" << "2. Shop list\n" << "3. My lists\n" << "4. Exit\n" << endl;
		cin >> menu;
		system("cls");
		switch (menu) {
		case 1:
			//Recipes menu TODO
			break;
		case 2:
			shopList();
			break;
		case 3:
			//My lists TODO
			break;
		case 4:
			cout << "Exiting...";
			return 0;
			break;
		default:
			cout << "Unknown command! Please try again!\n";
			break;
		}
	}
}


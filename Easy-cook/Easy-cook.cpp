#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void shopList() {
    int menu;
    while (true) {
        menu = 1;
        cout << "Please select what do you want to do.\n" << "1. View shop list(default)\n" << "2. Configure shop list\n" << "3. Exit shop list\n" << endl;
        cin >> menu;
        system("cls");
        switch (menu) {
        case 1:
            //View shop list TODO
            break;
        case 2:
            //Configure shop list TODO
            break;
        case 3:
            cout << "Returning to main menu...\n";
            return;
            break;
        default:
            cout << "Unknown command! Please try again!\n";
        }
    }
}

int main()
{
    int menu;
    while (true) {
        cout << "Welcome to Easy-cook!\n" << "Which option you would like to choose?\n" << "1. Recipes menu\n" << "2. Shop list\n" << "3. My lists\n" << "4. Exit\n" << endl;
        cin >> menu;
        system("cls");
        switch (menu){
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
        }
    }
}


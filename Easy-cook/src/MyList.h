#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#ifndef MYLIST
#define MYLIST

class MyList {
public:
	MyList() {};
	void run();
	virtual void ViewRecipe(int id);
private:
	void ShowMyList();
};
#endif
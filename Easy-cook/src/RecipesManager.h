#include <nlohmann/json.hpp>
#include <unordered_map>
#include <string>
#include "MyList.h"
#ifndef RECIPE_MANAGER
#define RECIPE_MANAGER

class RecipeManager : public MyList {
public:
    RecipeManager();
    void run();

private:
    void loadRecipes();
    void countTags();
    void displayTags();
    std::vector<std::string> getInputTags();
    void searchRecipes(const std::vector<std::string>& input_tags);
    bool searchAgain();
    void ViewRecipe(int id) override;

    nlohmann::json data;
    std::unordered_map<std::string, int> tag_count;
    bool fileLoaded = false;
};
#endif
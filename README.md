
# Easy-cook

This a C++ project for program Easy-cook.
In this app user will be able:
* to manage his recipe book by adding new recipes and searching through them using tags.
* to manage shop list containing products that should be bought.
* to create own lists of favourite recepies.

## How to use

Executable for the program is stored in `\Easy-cook` and should not be moved.

### Shop List
 
In Shop list menu, user can manipulate Shop list with products to buy in a light txt file.
File is automatically created if missing in `\Easy-cook\ShopList`.
Select "View shop list" to display items on the list.
Select "Modify shop list" to edit or delete items from shop list.

### Recipes menu

In recipe menu, user is able to search through database containing detailed recipes using tags.
User can search with up to 3 tags(case sensitive).
If recipe sounds interesting, user can save it in My list to access it later through My List menu.

### My list

In "My list" menu, user can view his list of favorite recipes and view them in detail.

## Recipes Database format

The RecipesDB should be placed in `\Easy-cook\RecipesDB`.
The JSON should have the following structure to work correctly:

    {
	"recipes": [
	{
	"name": "", // Name of the recipe
	"id": 1, // ID of the recipe
	"ingredients": { // Ingridients for the recipe. in1 and in2 are replaced by ingridient name
	"in1": "200g",
	"in2": "100g",
	...
	},
	"steps": "Step 1. step 2. step 3", // Instructions on how to execute recipe
	"tags": [ "Italian", "Pasta", "Quick" ] // Tags used to identify recipe in search
	}]
	}
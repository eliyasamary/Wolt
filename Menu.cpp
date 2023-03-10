#include "Menu.h"

/*-------------------------------------------------------------------------------*/
// Default constructor
Menu::Menu()
	:
	dishes(NULL),
	size(0) {}

/*-------------------------------------------------------------------------------*/
// Constructor
Menu::Menu(Dish* new_dishes, int new_size)
	:
	size(new_size)
{
	dishes = new Dish[new_size];
	if (dishes == NULL)
	{
		std::cout << "Memory error, Menu not created\n";
	}
	for (int i = 0; i < new_size; i++)
	{
		dishes[i] = new_dishes[i];
	}
}

/*-------------------------------------------------------------------------------*/
// Assignment operator
Menu& Menu::operator = (const Menu& menu)
{
	if (this != &menu)
	{
		delete[] dishes;
		size = menu.size;
		dishes = new Dish[size];
		if (dishes == NULL)
		{
			std::cout << "Memory error, Menu not copied\n";
		}
		for (int i = 0; i < menu.size; i++)
		{
			dishes[i] = menu.dishes[i];
		}
	}
	return *this;
}

/*-------------------------------------------------------------------------------*/
// Destructor
Menu::~Menu() {
	for (int i = 0; i < size; i++)
	{
		dishes[i].~Dish();
	}
}

/*-------------------------------------------------------------------------------*/
// Prints the menu
void Menu::printMenu()
{
	int counter = 1;
	for (int i = 0; i < size; i++)
	{
		if (dishes[i].getDishType() == Appetizer)
		{
			std::cout << counter << ".";
			dishes[i].printDish();
			counter++;
		}
	}
	std::cout << "\n****************************\n";
	for (int i = 0; i < size; i++)
	{
		if (dishes[i].getDishType() == MainCourse)
		{
			std::cout << counter << ".";
			dishes[i].printDish();
			counter++;
		}
	}
	std::cout << "\n****************************\n";
	for (int i = 0; i < size; i++)
	{
		if (dishes[i].getDishType() == Dessert)
		{
			std::cout << counter << ".";
			dishes[i].printDish();
			counter++;
		}
	}
}

/*-------------------------------------------------------------------------------*/
// returns the dish that the client choos (call from restaurant - makeOrder())
Dish Menu::returnDishByChoose(int c)
{
	int counter = 1;
	for (int i = 0; i < size; i++)
	{
		if (dishes[i].getDishType() == Appetizer)
		{
			if (counter == c)
			{
				dishes[i].printDishAdded();
				return dishes[i];
			}
			counter++;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (dishes[i].getDishType() == MainCourse)
		{
			if (counter == c)
			{
				dishes[i].printDishAdded();
				return dishes[i];
			}
			counter++;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (dishes[i].getDishType() == Dessert)
		{
			if (counter == c)
			{
				dishes[i].printDishAdded();
				return dishes[i];
			}
			counter++;
		}
	}
}
#include "Restaurant.h"

/*-------------------------------------------------------------------------------*/
// Default constructor
Restaurant::Restaurant()
	:
	name(NULL) {}

/*-------------------------------------------------------------------------------*/
// Constructor
Restaurant::Restaurant(const char* new_name, Address new_address, Menu new_menu)
	:
	street(new_address),
	menu(new_menu)
{
	name = new_name;
}

/*-------------------------------------------------------------------------------*/
// Assignment operator
Restaurant& Restaurant::operator = (const Restaurant& restaurant)
{
	if (this != &restaurant)
	{
		street = restaurant.street;
		menu = restaurant.menu;
		name = restaurant.name;
	}
	return *this;
}

/*-------------------------------------------------------------------------------*/
// Destructor
Restaurant::~Restaurant() {}

/*-------------------------------------------------------------------------------*/
// prints the restaurant name
void Restaurant::printRestaurant()
{
	std::cout << name << std::endl;
}

/*-------------------------------------------------------------------------------*/
// making the order (call from App - Order())
int Restaurant::makeOrder(Dish* dish_array)
{
	int num_of_dishes = 0;
	int choose = -1 ;
	std::cout << std::endl;
	std::cout << "Choose dishes from menu, to end order enter 0\n"
		<< "To change restaurant enter 9\n\n";
	menu.printMenu();
	do
	{
		std::cout << "\n>";
		std::cin >> choose;
		if (choose > 0 && choose < 6)
		{
			dish_array[num_of_dishes] = menu.returnDishByChoose(choose);
			num_of_dishes++;
		}
		if (choose == 9)
		{
			num_of_dishes = - 1;
			return num_of_dishes;
		}
	} while (choose != 0);
	return num_of_dishes;
}
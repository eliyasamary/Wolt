#pragma once
#include "Dish.h"

class Menu
{
public:
	Menu();
	Menu(Dish* new_dishes, int new_size);
	Menu& operator = (const Menu& menu);
	~Menu();
public:
	void printMenu();
	Dish returnDishByChoose(int c);
private:
	Dish* dishes;
	int size;
};
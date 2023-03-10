#pragma once
#include "Menu.h"
#include "Address.h"

class Restaurant
{
public:
	Restaurant();
	Restaurant(const char* new_name, Address new_address, Menu new_menu);
	Restaurant& operator = (const Restaurant& restaurant);
	~Restaurant();
public:
	void setName(const char* new_name) { name = new_name; }
	const char* callGetCity(){ return street.getCity(); }
	void setAddress(Address new_address) { street = new_address; }
	int callGetStreet() { return street.getStreet(); }
	void setMenu(Menu new_menu) { menu = new_menu; }
	void printRestaurant();
	int makeOrder(Dish* dish_array );

private:
	const char*		name;
	Address			street;
	Menu			menu;
};
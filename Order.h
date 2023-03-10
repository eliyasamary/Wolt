#pragma once
#include "Client.h"
#include "Restaurant.h"

class Order
{
public:
	Order();
	Order(Dish* dishes_order, Client client_order, Restaurant restaurant_order, int order_size);
	~Order();
public:
	Order& operator = (const Order& order);
	void PrintOrder();
	int getSize() { return dishes_size; }
	void setSize(int new_size) { dishes_size = new_size; }
	int getTotalSum() { return totalSum; }
	void deleteDishByIndex(int index);
	int	calcArrivalTime();
	void deleteOrder();
private:
	Dish*		dishes;
	int			dishes_size;
	int			totalSum;
	Client		client;
	Restaurant	restaurant;
};
#pragma once
#include "Client.h"
#include "Restaurant.h"
#include "Order.h"

class Application
{
public:
	Application();
	Application(Client *new_client, Restaurant* new_restaurants, int num_of_restaurants);
	~Application();
public:
	void makeOrder();
	void CheckOrder();

private:
	Client*		client;
	Restaurant* restaurants;
	int			num_of_restaurants;
	Order*		order;
};
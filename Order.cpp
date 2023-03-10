#include "Order.h"

/*-------------------------------------------------------------------------------*/
// Default constructor
Order::Order()
	:
	dishes(NULL),
	totalSum(0),
	dishes_size(0){}

/*-------------------------------------------------------------------------------*/
//Constructor
Order::Order(Dish* dishes_order, Client client_order, Restaurant restaurant_order, int order_size)
	:
	client(client_order),
	restaurant(restaurant_order),
	dishes_size(order_size)
{
	int sum = 0;
	dishes = new Dish[order_size];
	if (dishes == NULL)
	{
		std::cout << "Memory error, Order not created\n";
	}
	for (int i = 0; i < order_size; i++)
	{
		sum += dishes_order[i].getValue();
		dishes[i] = dishes_order[i];
	}
	totalSum = sum;
}

/*-------------------------------------------------------------------------------*/
// Destructor
Order::~Order()
{
	delete[] dishes;
}


/*-------------------------------------------------------------------------------*/
// Assigment operator
Order& Order::operator = (const Order& order)
{
	if (this != &order)
	{
		delete[] dishes;
		totalSum = order.totalSum;
		dishes_size = order.dishes_size;
		dishes = new Dish[dishes_size];
		if (dishes == NULL)
		{
			std::cout << "Memory error, Order not copied\n";
		}
		for (int i = 0; i < order.dishes_size; i++)
		{
			dishes[i] = order.dishes[i];
		}
		client = order.client;
		restaurant = order.restaurant;
	}
	return *this;
}
/*-------------------------------------------------------------------------------*/
// Calculate arrival time

int Order::calcArrivalTime()
{
	int client_street = client.callGetStreet();
	int restaurant_street = restaurant.callGetStreet();
	return abs(restaurant_street - client_street);
}

/*-------------------------------------------------------------------------------*/
// Order Print
void Order::PrintOrder()
{
	std::cout << "Your order:" << std::endl;
	for (int i = 0; i < dishes_size; i++)
	{
		std::cout << i+1 << " ";
		dishes[i].printDish();
		std::cout << std::endl;
	}
	std::cout << "Sum:" << totalSum << " NIS\n"
		<< "Arrival time:" << calcArrivalTime() << " min\n";
}

/*-------------------------------------------------------------------------------*/
// Delete dish by index

void Order::deleteDishByIndex(int index)
{
	if (index != dishes_size - 1) /*If the deleted dish in not the last in the array*/
	{
		dishes[index] = dishes[dishes_size - 1];
		dishes[dishes_size - 1].~Dish();
	}
	else dishes[index].~Dish();
	dishes_size--;
	int new_sum=0;
	for (int i = 0; i < dishes_size; i++)
	{
		new_sum += dishes[i].getValue();
	}
	totalSum = new_sum;
}


/*-------------------------------------------------------------------------------*/
// Delete Order

void Order::deleteOrder()
{
	for (int i = 0; i < dishes_size; i++)
	{
		dishes[i].~Dish();
	}
	dishes_size = 0;
	totalSum = 0;
	client.~Client();
	restaurant.~Restaurant();
}
#include "Application.h"
#define MAX_ORDER_SIZE 20

/*-------------------------------------------------------------------------------*/
// Default constructor
Application::Application()
	:
	client(NULL),
	restaurants(NULL){}

/*-------------------------------------------------------------------------------*/
//Constructor
Application::Application(Client *new_client, Restaurant* new_restaurants, int new_num_of_restaurants)
	:
	num_of_restaurants(new_num_of_restaurants)
{
	order = new Order;
	client = new Client;
	if (client == NULL)
	{
		std::cout << "Memory error, Application not created\n";
	}
	*client = *new_client;
	client = new_client;
	restaurants = new Restaurant[new_num_of_restaurants];
	if (restaurants == NULL)
	{
		std::cout << "Memory error, Application not created\n";
	}
	for (int i = 0; i < new_num_of_restaurants; i++)
	{
		restaurants[i] = new_restaurants[i];
	}
}

/*-------------------------------------------------------------------------------*/
// Destructor
Application::~Application()
{
	delete order;
	//delete client;

	for (int i = 0; i < num_of_restaurants; i++)
	{
		restaurants[i].~Restaurant();
	}
	delete[] restaurants;
}

/*-------------------------------------------------------------------------------*/
// Order func (call from main)
void Application::makeOrder()
{
	int choose = 0;
	do
	{
		std::cout << "\n1) Back <--\n";
		for (int i = 0; i < num_of_restaurants; i++)
		{
			std::cout << i + 2 << ") ";
			restaurants[i].printRestaurant();
		}
		std::cout << "\n>";
		std::cin >> choose;

	} while (choose < 1 || choose > num_of_restaurants + 1);
	if (choose == 1) return;
	int restaurantIndex = choose - 2;
	if (strcmp(restaurants[restaurantIndex].callGetCity(),client->callGetCity()) == 0)
	{
		Dish chosen_dishes[MAX_ORDER_SIZE];
		int order_size = restaurants[restaurantIndex].makeOrder(chosen_dishes);
		if (order_size == -1)
		{
			int t = 0;
			while (chosen_dishes[t].getValue() != 0)
			{
				chosen_dishes[t].Reset();
				t++;
			}
			makeOrder();
			return;
		}
		Order new_order(chosen_dishes, *client, restaurants[restaurantIndex], order_size);
		*order = new_order;
		std::cout << "\nPlease confirm the details of the order:\n\n";
		std::cout << "Client's details: ";
		client->printClient();
		std::cout << "Restaurant: ";
		restaurants[restaurantIndex].printRestaurant();
		int client_credit = client->getCredits();
		int order_sum = order->getTotalSum();
		if (client_credit < order_sum)
		{
			std::cout << "\nError! not enough credits. Please remove items\n"
				<< "Order total:" << order_sum << " NIS " << "\nAvailable balance:"
				<< client_credit << " NIS\n\n";
			CheckOrder();
		}
	}
	else std::cout << "This restaurant does not deliver to you!\n";
	return;
}

/*-------------------------------------------------------------------------------*/
// Check Order func (call from main)
void Application::CheckOrder()
{
	if (order->getSize() == 0)
	{
		std::cout << "You did not order anything yet!\n";
		return;
	}
	// print the order first
	order->PrintOrder();
	std::cout << "\nWould you like to change the order?" << std::endl << "1 - yes" 
		<< std::endl << "0 - No, leave the order" << std::endl << std::endl;
	int sel;
	do
	{
		std::cout << ">";
		std::cin >> sel;
	} while (sel != 0 && sel != 1);

	if (sel != 0)
	{
		// Changes
		std::cout << "\nWhich dish would you like to delete?" << std::endl
			<< "Select a dish by number\nEnter 0 to finish" << std::endl;;
		do
		{
			do
			{
				std::cout << ">";
				std::cin >> sel;
			} while (sel < 0 || sel > order->getSize());
			if (sel != 0)
			{
				order->deleteDishByIndex(sel - 1);
			}
		} while (sel != 0);
	}
	if (order->getTotalSum() <= client->getCredits())
	{
		std::cout << "Send order?\n1-Yes\n2-No\n>";
		std::cin >> sel;
		if (sel == 1)
		{
			client->chargeMoney(order->getTotalSum());
			order->PrintOrder();
			order->deleteOrder();
			std::cout << "Order sent! Bon a Petite'\n"
				<< "Remaining credits:" << client->getCredits() << " NIS\n";
			return;
		}
	}
	std::cout << "Order not sent!\n";
}
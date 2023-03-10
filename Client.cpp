#include "Client.h"

/*-------------------------------------------------------------------------------*/
// Default constructor
Client::Client()
	:
	credits(100),
	name(NULL),
	phoneNumber(NULL) {}

/*-------------------------------------------------------------------------------*/
// Constructor
Client::Client(const char* new_name, const char* new_phone_number, Address new_address)
	:
	credits(100)
{
	name = new_name;
	phoneNumber = new_phone_number;
	homeAddress = new_address;
}

/*-------------------------------------------------------------------------------*/
// Assignment operator
Client& Client::operator = (const Client& client)
{
	if (this != &client)
	{
		name = client.name;
		phoneNumber = client.phoneNumber;
		credits = client.credits;
		homeAddress = client.homeAddress;
	}
	return *this;
}

/*-------------------------------------------------------------------------------*/
// print client
void Client::printClient()
{
	std::cout << name << " " << phoneNumber << std::endl;
}
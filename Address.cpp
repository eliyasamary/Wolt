#include "Address.h"

/*-------------------------------------------------------------------------------*/
// Default constructor
Address::Address()
	:
	street(0)
{
	city = NULL;
}

/*-------------------------------------------------------------------------------*/
// constructor
Address::Address(int new_street, const char* new_city)
	:
	street(new_street)
{
	city = new_city;
}

/*-------------------------------------------------------------------------------*/
// Assignment operator
Address& Address::operator =(const Address& address) {
	if (this != &address)
	{
		street = address.street;
		city = address.city;
	}
	return *this;
}
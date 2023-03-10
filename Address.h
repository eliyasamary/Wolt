#pragma once
#include <iostream>
#include <string>

class Address
{
public:
	Address();
	Address(int new_street, const char* new_city);
	Address& operator =(const Address& address);
	~Address() {} 
public:
	const char* getCity() { return city; }
	int getStreet() { return street; }

private:
	int			street;
	const char*	city;
};

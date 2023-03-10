#pragma once
#include "Address.h"

class Client
{
public:
	Client();
	Client(const char* new_name, const char* new_phone_number, Address new_address);
	Client& operator =(const Client& client);
	~Client(){}
public:
	void setName(const char* new_name) { name = new_name; }
	int callGetStreet() { return homeAddress.getStreet(); }
	void setPhoneNumber(const char* new_phone_number) { phoneNumber = new_phone_number; }
	const char* callGetCity() { return homeAddress.getCity(); }
	void setAddress(Address new_address) { homeAddress = new_address; }
	int getCredits() { return credits; }
	void chargeMoney(int sum) { credits -= sum; }
	void printClient();

private:
	const char*		name;
	const char*		phoneNumber;
	int				credits;
	Address			homeAddress;
};
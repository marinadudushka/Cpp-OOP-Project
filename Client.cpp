
#include "Client.h"

Client::Client():productBought(0)
{
}

Client::Client(const char * name, int age):Person(name,age)
{
	productBought = 0;
}

Client::Client(const Client &other):Person(other)
{
	productBought = other.productBought;
}

Client & Client::operator=(const Client &other)
{
	if (this != &other)
	{
		Person::operator=(other);
		productBought = other.productBought;
	}
	return *this;
}

Client::~Client()
{
}


void Client::buyProduct() 
{
	productBought++;
}


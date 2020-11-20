
#include "Seller.h"

Seller::Seller():clientsServed(0),isBusy(false)
{
}

Seller::Seller(const char *name, int age):Person(name,age)
{
	clientsServed = 0;
}

Seller::Seller(const Seller &other):Person(other)
{
	clientsServed = other.clientsServed;
	isBusy = other.isBusy;
}

Seller & Seller::operator=(const Seller &other)
{
	if(this != &other)
	{
		Person::operator=(other);
		clientsServed = other.clientsServed;
		isBusy = other.isBusy;
	}
	return *this;
}

Seller::~Seller()
{}



void Seller::FreeToServe()
{
	isBusy = false;
}

bool Seller::Buzy() const
{
	return isBusy;
}

void Seller::serveClient()
{
	isBusy = true;
	clientsServed++;
	cout << "Your order has been fulfilled by: "<< getName() << endl;
}

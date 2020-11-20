
#include "Product.h"

Product::Product()
{
	name = nullptr;
	price = 0;
	quantity = 0;
}

Product::Product(const char * cname, double cprice, int cquantity)
{
	int s = strlen(cname) + 1;
	name = new char[s];
	strcpy_s(name, s, cname);
	price = cprice;
	quantity = cquantity;
}

Product::Product(const Product & other)
{
	name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);
	price = other.price;
	quantity = other.quantity;
}

Product& Product::operator=(const Product& other)
{
	if (this != &other)
	{
		delete[] name;
		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);
		price = other.price;
		quantity = other.quantity;
	}
	return *this;
}

Product::~Product()
{
	delete[] name;
}

void Product::printInfo() const
{
	cout << "\nname: " << name << endl
		<< "price: " << price << endl
		<< "quantity: " << quantity << endl;
}

void Product::sellProduct()
{
	quantity--;
}

ostream& operator<<(ostream & os, const Product & prod)
{
	prod.infoToStream(os);
	return os;
}

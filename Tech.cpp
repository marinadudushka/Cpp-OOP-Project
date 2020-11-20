
#include "Tech.h"

Tech::Tech()
{
	weight = 0;
	warranty = 0;
}

Tech::Tech(const char * name, double price, int quant, double cweight, int cwarranty):Product(name,price,quant)
{
	weight = cweight;
	warranty = cwarranty;
}

Tech::Tech(const Tech &other):Product(other)
{
	weight = other.weight;
	warranty = other.warranty;
}

Tech Tech::operator=(const Tech &other)
{
	if (this != &other)
	{
		Product::operator=(other);
		weight = other.weight;
		warranty = other.warranty;
	}
	return *this;
}

Tech::~Tech()
{
}

void Tech::infoToStream(ostream &os) const
{
	os <<getPrType()<<endl<< name <<endl<< price << endl << quantity << endl << weight << endl << warranty;
}

Type Tech::getPrType() const
{
	return TECH;
}

void Tech::printInfo() const
{
	Product::printInfo();
	cout << "weight: " << weight << endl
		<< "warranty: " << warranty << endl;
}

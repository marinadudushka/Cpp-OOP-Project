#include "Clothing.h"

Clothing::Clothing()
{
	sizec = 0;
	lenght = 0;
}

Clothing::Clothing(const char * name, double price, int quant, int siz, int len):Product(name,price,quant)
{
	sizec = siz;
	lenght = len;
}

Clothing::Clothing(const Clothing & other):Product(other)
{
	sizec = other.sizec;
	lenght = other.lenght;
}

Clothing Clothing::operator=(const Clothing & other)
{
	if (this != &other)
	{
		Product::operator=(other);
		sizec = other.sizec;
		lenght = other.lenght;
	}
	return *this;
}

Clothing::~Clothing()
{}

void Clothing::infoToStream(ostream &os) const
{
	os << getPrType() << endl << name << endl << price << endl << quantity << endl << sizec << endl << lenght;
}

Type Clothing::getPrType() const
{
	return CLOTHING;
}

void Clothing::printInfo() const
{
	Product::printInfo();
	cout<< "size: " << sizec << endl
		<< "lenght: " << lenght << endl;
}

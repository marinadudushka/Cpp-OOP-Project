
#include "Cosmetics.h"

Cosmetics::Cosmetics() : countryOfOrigin(nullptr), composition(nullptr)
{}

Cosmetics::Cosmetics(const char *name, double price, int quant, char * origin, char *compos): Product(name,price,quant)
{
	countryOfOrigin = new char[strlen(origin) + 1];
	strcpy_s(countryOfOrigin, strlen(origin) + 1, origin);
	composition = new char[strlen(compos) + 1];
	strcpy_s(composition, strlen(compos) + 1, compos);
}


Cosmetics::Cosmetics(const Cosmetics& other):Product(other)
{
	countryOfOrigin = new char[strlen(other.countryOfOrigin) + 1];
	strcpy_s(countryOfOrigin, strlen(other.countryOfOrigin) + 1, other.countryOfOrigin);
	composition = new char[strlen(other.composition) + 1];
	strcpy_s(composition, strlen(other.composition) + 1, other.composition);
}

Cosmetics Cosmetics::operator=(const Cosmetics &other)
{
	if (this != &other)
	{
		Product::operator=(other);
		delete[] countryOfOrigin;
		delete[] composition;
		countryOfOrigin = new char[strlen(other.countryOfOrigin) + 1];
		strcpy_s(countryOfOrigin, strlen(other.countryOfOrigin) + 1, other.countryOfOrigin);
		composition = new char[strlen(other.composition) + 1];
		strcpy_s(composition, strlen(other.composition) + 1, other.composition);
	}
	return *this;
}

void Cosmetics::infoToStream(ostream & os) const
{
	os <<getPrType()<<endl<< name << endl << price << endl << quantity << endl << countryOfOrigin << endl << composition ;
}

Cosmetics::~Cosmetics()
{
	delete[] countryOfOrigin;
	delete[] composition;
}

Type Cosmetics::getPrType() const
{
	return COSMETICS;
}

void Cosmetics::printInfo() const
{
	Product::printInfo();
	cout << "Country of origin: " << countryOfOrigin << endl
		 << "Composition: " << composition << endl;
}

#pragma once
#include <iostream>
#include <string.h>
using namespace std;
enum Type{CLOTHING,TECH,FOOD,COSMETICS,ALL};

class Product
{
protected:
	char* name;
	double price;
	int quantity;
public:
	Product();
	Product(const char*, double, int);
	Product(const Product&);
	Product& operator=(const Product&);

	virtual ~Product();
	virtual Type getPrType() const = 0;
	virtual void infoToStream(ostream&) const = 0;
	friend ostream& operator<<(ostream &,const Product&);
	virtual void  printInfo() const;

	char* getName() const { return name; }
	double getPrice() const { return price; }
	int getQuantity() const { return quantity; }
	void sellProduct();
};
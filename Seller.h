#pragma once
#include "Person.h"
class Seller:public Person
{
private:
	int clientsServed;
	bool isBusy;
public:
	Seller();
	Seller(const char*, int);
	Seller(const Seller&);
	Seller& operator=(const Seller&);
	~Seller();
	void FreeToServe();
	bool Buzy() const;
	void serveClient();
	


};
#pragma once
#include "Person.h"

class Client : public Person
{
private:
	int productBought;
public:
	Client();
	Client(const char*,int);
	Client(const Client&);
	Client& operator=(const Client&);
	~Client();
	
	void buyProduct() ;

};
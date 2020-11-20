#include "Person.h"

Person::Person():name(nullptr),age(0)
{
}

Person::Person(const char * name, int age)
{ 
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->age = age;
}

Person::Person(const Person &other)
{
	name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);
	age = other.age;
}

Person & Person::operator=(const Person &other)
{
	if (this != &other)
	{
		delete[] name;
		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);
		age = other.age;
	}
	return *this;
}

Person::~Person()
{
	delete[] name;
}

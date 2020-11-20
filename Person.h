#pragma once
#include <iostream>
#include <string.h>
using namespace std;
class Person
{
protected:
	char* name;
	int age;
public:
	Person();
	Person(const char*, int);
	Person(const Person&);
	Person& operator=(const Person&);
	~Person();
	char* getName() const { return name; }
	int getAge() const { return age; }
};
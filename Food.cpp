
#include "Food.h"

Food::Food():calories(0),grams(0),ingredients(nullptr){}

Food::Food(const char *name, double price, int quant,  int gr, int cal, const char * ingred):Product(name,price,quant)
{
	calories = cal;
	grams = gr;
	ingredients = new (nothrow) char[strlen(ingred) + 1];
	strcpy_s(ingredients, strlen(ingred) + 1, ingred);
}

Food::Food(const Food &other):Product(other)
{
	calories = other.calories;
	grams = other.grams;
	ingredients = new char[strlen(other.ingredients) + 1];
	strcpy_s(ingredients, strlen(other.ingredients) + 1, other.ingredients);
}

Food Food::operator=(const Food &other)
{
	if (this != &other)
	{
		Product::operator=(other);
		calories = other.calories;
		grams = other.grams;
		delete[] ingredients;
		ingredients = new char[strlen(other.ingredients) + 1];
		strcpy_s(ingredients, strlen(other.ingredients) + 1, other.ingredients);
	}
	return *this;
}

Food::~Food()
{
	delete[] ingredients;
}


void Food::infoToStream(ostream & os) const
{
	os <<getPrType()<<endl<< name << endl << price << endl << quantity << endl << calories << endl << grams<<endl<<ingredients;
}

Type Food::getPrType() const
{
	return FOOD;
}

void Food::printInfo() const
{
	Product::printInfo();
	cout << "grams: " << grams << endl
		<< "calories: " << calories << endl
		<< "ingredients: " << ingredients << endl;
}

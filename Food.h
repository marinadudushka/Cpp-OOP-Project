#pragma once 
#include "Product.h"
class Food : public Product
{
private:
	int calories;
	int grams;
	char* ingredients;
public:
	Food();
	Food(const char*, double, int, int, int,const char*);//name,price,quantity,grams,calories,description/ingredients
	Food(const Food&);
	Food operator=(const Food&);
	~Food();
	void infoToStream(ostream&) const;
	Type getPrType() const;
	void printInfo() const;
	int getCalories() const { return calories; }
	int getGrams() const { return grams; }
	char* getIngredients() const { return ingredients; }
};
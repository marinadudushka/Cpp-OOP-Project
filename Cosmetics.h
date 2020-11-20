#include "Product.h"
class Cosmetics : public Product
{
private:
	char* countryOfOrigin;
	char* composition;
public:
	Cosmetics();
	Cosmetics(const char*, double, int, char*, char*);//name,price,quantity,origin,compos
	Cosmetics(const Cosmetics&);
	Cosmetics operator=(const Cosmetics&);
	void infoToStream(ostream&) const;
	~Cosmetics();
	Type getPrType() const;
	void printInfo() const;
	char* getCountry() const { return countryOfOrigin; }
	char* getComposition() const { return composition; }
};
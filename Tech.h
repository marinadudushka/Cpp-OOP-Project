#include "Product.h"
class Tech : public Product
{
private:
	double weight;
	int warranty;
public:
	Tech();
	Tech(const char*, double, int, double, int);//name,price,quantity,weight,warranty
	Tech(const Tech&);
	Tech operator=(const Tech&);
	~Tech();
	void infoToStream(ostream&) const;
	Type getPrType() const;
	void printInfo() const;
	double getWeight() const { return weight; }
	int getWarranty() const { return warranty; }
};
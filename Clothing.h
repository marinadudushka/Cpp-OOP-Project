
#include "Product.h"
class Clothing : public Product
{
private:
	int sizec;
	int lenght;
public:
	Clothing();
	Clothing(const char*, double, int, int, int);//name,price,quantity,size,lenght
	Clothing(const Clothing&);
	Clothing operator=(const Clothing&);
	~Clothing();
	void infoToStream(ostream&) const;
	Type getPrType() const;
	void printInfo() const;
	int getSize() const { return sizec; }
	int getLenght() const { return lenght; }
};
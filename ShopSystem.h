#pragma once
#include <fstream>
#include "Client.h"
#include "Seller.h"
#include "Clothing.h"
#include "Cosmetics.h"
#include "Food.h"
#include "Tech.h"

class ShopSystem
{
private:
	const int maxSellers = 100;
	const int maxProducts = 5000;
	int maxClient;
	int currSeller;
	int currProduct;
	int currClient;
	Product** productArr;
	Client* clientArr;
	Seller* sellerArr;
public:
	ShopSystem();//default costructor
	ShopSystem(int);//constructor with parameters
	ShopSystem(const ShopSystem&);
	ShopSystem operator=(const ShopSystem&);
	~ShopSystem();

	void addProduct(Product*);

	void removeProduct(const char*); //removing product from array and setting it's pointer to nullptr
	void addClient(const Client&);//adding a client by registering to the system
	void addSeller(const Seller&);//hiring a seller as a system administrator
	void sellProduct(const char* ,const char*);//selling a product by reducing it's quantity 
	void saveProductsToBase(fstream& file) const;// saving all products to a base( a text file, because the products are not consistent
												//and use dynamic memory)
	void whatsThePrice(const char*, const char*) const;// getting the price for a product if the product exists
	void whatsTheInfo(const char*, const char*) const;//getting all information for a product if it exists
	void infoForAllOfAkind(const char*, int) const;//search and print products of the same type
	void printAllOfAKind(int) const;
	void printAllProducts() const;
	bool clNameTaken(const char*) const;//checks if the client name has been taken
private:

	int clientExists(const char* ) const;// finding if the client exists and returns his place in the array , else returns -1
	int findASeller();//finding if the seller, exists and returns his place in the array , else returns -1
	int productExists(const char*) const;//finding if the product, exists and returns his place in the array , else returns -1
};
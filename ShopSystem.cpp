#include "ShopSystem.h"

ShopSystem::ShopSystem(): maxClient(0),currSeller(0),currProduct(0), currClient(0),
						  productArr(nullptr),clientArr(nullptr),sellerArr(nullptr){}

ShopSystem::ShopSystem(int client):maxClient(client),currSeller(0),currClient(0)
{
	productArr = new Product*[maxProducts];
	clientArr = new Client[maxClient];
	sellerArr = new Seller[maxSellers]; 

}

ShopSystem::ShopSystem(const ShopSystem &other)
{
	productArr = new Product*[maxProducts];
	for (int i = 0; i < other.currProduct; i++)
	{
		if(other.productArr[i]!=nullptr)
			addProduct(other.productArr[i]);
	}
	maxClient = other.maxClient;

	clientArr = new Client[maxClient];
	currClient = other.currClient;
	for (int i = 0; i > currClient; i++)
		clientArr[i] = other.clientArr[i];

	sellerArr = new Seller[maxSellers];
	currSeller = other.currSeller;
	for (int i = 0; i < currSeller; i++)
		sellerArr[i] = other.sellerArr[i];

}

ShopSystem ShopSystem::operator=(const ShopSystem &other)
{
	if (this != &other)
	{
		for (int i = 0; i < currProduct; i++)
			delete productArr[i];
		delete productArr;
		currProduct = 0;
		delete[] sellerArr;
		delete[] clientArr;

		productArr = new Product*[maxProducts];
		for (int i = 0; i < other.currProduct; i++)
		{
			if (other.productArr[i] != nullptr)
				addProduct(other.productArr[i]);
		}
		maxClient = other.maxClient;

		clientArr = new Client[maxClient];
		currClient = other.currClient;
		for (int i = 0; i > currClient; i++)
			clientArr[i] = other.clientArr[i];

		sellerArr = new Seller[maxSellers];
		currSeller = other.currSeller;
		for (int i = 0; i < currSeller; i++)
			sellerArr[i] = other.sellerArr[i];
	}
	return *this;
}

ShopSystem::~ShopSystem()
{
	for (int i = 0; i < currProduct; i++)
		delete productArr[i];
	delete[] productArr;
	delete[] clientArr;
	delete[] sellerArr;
}

void ShopSystem::addProduct(Product *prod)
{
	int exist = productExists(prod->getName());
	if (exist == -1)
	{
		int prType = prod->getPrType();
		switch (prType)
		{
		case 0://clothing
			if (currProduct < maxProducts)
			{
				Clothing* temp = dynamic_cast<Clothing*>(prod);
				productArr[currProduct] = new Clothing(*temp);
				currProduct++;
			}
			break;
		case 1://tech
			if (currProduct < maxProducts)
			{
				Tech* temp = dynamic_cast<Tech*>(prod);
				productArr[currProduct] = new Tech(*temp);
				currProduct++;
			}
			break;
		case 2://food
			if (currProduct < maxProducts)
			{
				Food* temp = dynamic_cast<Food*>(prod);
				productArr[currProduct] = new Food(*temp);
				currProduct++;
			}
			break;
		case 3://cosmetics
			if (currProduct < maxProducts)
			{
				Cosmetics* temp = dynamic_cast<Cosmetics*>(prod);
				productArr[currProduct] = new Cosmetics(*temp);
				currProduct++;
			}
			break;
		}
	}
	else
		cerr << "Product already exists!" << endl;
}

void ShopSystem::removeProduct(const char* name)
{
	int exist = productExists(name);
	if (exist > -1)
	{
		delete productArr[exist];
		productArr[exist] = nullptr;
	}
}

void ShopSystem::addClient(const Client &cl)
{
	if (currClient < maxClient)
	{
		clientArr[currClient] = cl;
		currClient++;
	}
}

void ShopSystem::addSeller(const Seller & seller)
{
	if (currSeller < maxSellers)
	{
		sellerArr[currSeller] = seller;
		currSeller++;
	}
	else
		cerr << "Cannot hire more sellers!" << endl;
}

int ShopSystem::productExists(const char* name) const 
{
	for (int i = 0; i < currProduct; i++)
	{
		if(productArr[i]!=nullptr)
			if (strcmp(name, (productArr[i]->getName())) == 0)
				return i;
	}
	return -1;
}

void ShopSystem::sellProduct(const char* name,const char* clname)
{
	int clExist = clientExists(clname);
	if (clExist>-1)
	{
		int exist = productExists(name);
		if (exist > -1 && (productArr[exist]->getQuantity())>0)
		{
			int seller = findASeller();
			productArr[exist]->sellProduct();
			clientArr[clExist].buyProduct();
			if(seller>-1)
				sellerArr[seller].serveClient();
		}
		else
			cerr << "No such product" << endl;
	}
	else
		cerr << "No such client in shop!" << endl;
}

void ShopSystem::saveProductsToBase(fstream& file) const
{
	for (int i = 0; i < currProduct; i++)
	{

		if (productArr[i] != nullptr)
		{
			file << *productArr[i];
			if(i<currProduct-1)
				file << endl;
		}
	}
}

int ShopSystem::clientExists(const char* name) const
{
	for (int i = 0; i < currClient; i++)
	{
		if (strcmp(clientArr[i].getName(), name) == 0)
			return i;
	}
	return -1;
}
void ShopSystem::whatsThePrice(const char* clname, const char * namepr) const
{
	if (clientExists(clname)>-1)
	{
		int exist = productExists(namepr);
		if (exist > -1)
		{
			cout<< productArr[exist]->getPrice();
		}
		else
			cerr << "No such product!" << endl;
	}
	else
		cerr << "No such client!" << endl;
	
}

void ShopSystem::whatsTheInfo(const char* clname, const char * prname) const
{
	if (clientExists(clname)>-1)
	{
		int exist = productExists(prname);
		if (exist > -1)
		{
			productArr[exist]->printInfo();
		}
		else
			cerr << "No such product!" << endl;
	}
	else
		cerr << "No such client!" << endl;
}

void ShopSystem::infoForAllOfAkind(const char* clname, int type) const
{
	if (clientExists(clname)>-1)
		if (type == ALL)
			printAllProducts();
		else
			printAllOfAKind(type);
	else
		cerr << "No such client!" << endl;
}

void ShopSystem::printAllOfAKind(int type) const
{
		for (int i = 0; i < currProduct; i++)
		{
			if (type == productArr[i]->getPrType()&& productArr[i]!=nullptr)
				productArr[i]->printInfo();
		}

}

void ShopSystem::printAllProducts() const
{
	for (int i = 0; i < currProduct; i++)
		if(productArr[i]!=nullptr)
			productArr[i]->printInfo();
}

int ShopSystem::findASeller()
{
	if (currSeller > 0)
	{
		for (int i = 0; i < currSeller; i++)
		{

			if (sellerArr[i].Buzy()==false)
				return i;
		}
		for (int i = 0; i < currSeller; i++)
			sellerArr[i].FreeToServe();
		return 0;
	}
	else
		cerr << "No sellers hired!" << endl;
	return -1;
}

bool ShopSystem::clNameTaken(const char* name) const
{
	if (clientExists(name) > -1)
		return true;
	return false;
}

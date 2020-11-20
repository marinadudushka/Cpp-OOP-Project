#include "ShopSystem.h"
const int max_namesize = 100;
const char* filename = "base.txt";
const char* commandArr[] = { "addProduct","addClient","addSeller","buyProduct" };
bool fileExists();
void saveToFile(const ShopSystem&);
void setShopFromBase(ShopSystem&);
void createSystem(ShopSystem&);
void productTypes();
void addProduct(ShopSystem &shop);
void saveToFile(const ShopSystem & shop)
{
	if (fileExists())
	{
		fstream base(filename, ios::trunc | ios::out);
		if (base.is_open())
		{
			shop.saveProductsToBase(base);
			base.close();
		}
		else
			cerr << "Coulnd't open file for writing!" << endl;
	}
	else
	{
		ofstream file(filename);
		if (file.is_open())
		{
			file.close();
			fstream base(filename, ios::out);
			if (base.is_open())
			{
				shop.saveProductsToBase(base);
				base.close();
			}
		}
	}
}

void setShopFromBase(ShopSystem &shop)
{
	fstream base(filename, ios::in);
	if (!base.is_open())
		cerr << "Couldn't open base!" << endl;
	else
	{
		const int max_buffer = 200;
		int type;
		int quantity;
		double price;
		char buffer[max_buffer];

		while (!base.eof())
		{

			base >> type;
			base.get();
			base.getline(buffer, max_buffer);//name
			base >> price;
			base >> quantity;
			switch (type)
			{
				case 0://clothing
				{
					int size, lenght;
					base >> size;
					base >> lenght;
					Clothing cl(buffer, price, quantity, size, lenght);
					shop.addProduct(&cl);
					break;
				}
				case 1://tech
				{
					double weight;
					int warranty;
					base >> weight;
					base >> warranty;
					Tech th(buffer, price, quantity, weight, warranty);				
					shop.addProduct(&th);
					break;
				}
				case 2://FOOD
				{
					int calories, grams;
					char buffer2[max_buffer];
					base >> grams;
					base >> calories;
					base.get();
					base.getline(buffer2, max_buffer);
					Food fd(buffer, price, quantity, grams, calories, buffer2);
					shop.addProduct(&fd);
					break;
				}
				case 3://COSMETICS
				{
					char buffer2[max_buffer], buffer3[max_buffer];
					base.get();
					base.getline(buffer2, max_buffer);
					base.getline(buffer3, max_buffer);
					Cosmetics cm(buffer, price, quantity, buffer2, buffer3);
					shop.addProduct(&cm);
					break;
				}
			}

		}
		base.close();
	}
}

void createSystem(ShopSystem &shop)
{
	char command[20];
	cout << "Welcome to our shop creating system.\nPlease set up your shop.";
	int numOfPr;
	cout << "\nHow many products would you like to sell\n( you can add as many products as you like whenever you want)?: ";
	cin >> numOfPr;
	productTypes();
	for (int i = 0; i < numOfPr;i++)
	{
		addProduct(shop);
	}
}

void productTypes()
{
	cout << " Clothing: 0 \n Tech: 1 \n Food: 2 \n Cosmetics: 3\n ";
}

bool fileExists()
{
	fstream file(filename);
	if (file.is_open())
	{
		file.close();
		return true;
	}
	return false;
}
void addProduct(ShopSystem& shop)
{
	char name[max_namesize];
	double price;
	int quantity;
	int type;
	do
	{
		cout << "\nEnter product type: ";
		cin >> type;
	} while (type < 0 && type>3);
	cin.get();
	cout << "Enter product name: ";
	cin.getline(name, max_namesize);
	cout << "Enter product price: ";
	cin >> price;
	cout << "Enter product quantity: ";
	cin >> quantity;
	cin.get();
	switch (type)
	{
	case 0://clothing
	{
		int size, lenght;
		cout << "Enter size: ";
		cin >> size;
		cout << "Enter lenght: ";
		cin >> lenght;
		cin.get();
		Clothing cl(name, price, quantity, size, lenght);
		shop.addProduct(&cl);
		break;

	}
	case 1://tech
	{
		double weight;
		int warranty;
		cout << "Enter weight: ";
		cin >> weight;
		cout << "Enter warranty: ";
		cin >> warranty;
		cin.get();
		Tech th(name, price, quantity, weight, warranty);
		shop.addProduct(&th);
		break;
	}
	case 2://FOOD
	{
		int calories, grams;
		char ingredients[max_namesize];
		cout << "Enter grams: ";
		cin >> grams;
		cout << "Enter calories: ";
		cin >> calories;
		cin.get();//cin.ignore() cin.clear()
		cout << "Enter ingredients: ";
		cin.getline(ingredients, max_namesize);
		Food fd(name, price, quantity, grams, calories, ingredients);
		shop.addProduct(&fd);
		break;
	}
	case 3://COSMETICS
	{
		char origin[max_namesize], description[max_namesize];
		cout << "Enter country of origin: ";
		cin.getline(origin, max_namesize);
		cout << "Enter description: ";
		cin.getline(description, max_namesize);
		Cosmetics cm(name, price, quantity, origin, description);
		shop.addProduct(&cm);
		break;
	}
	
	}
}
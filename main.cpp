#include "HelperFunctions.h"
const int max_client = 100;

int main()
{
	//take system from file
	//create system
	ShopSystem shop(max_client);
	if (fileExists())
	{

		setShopFromBase(shop);
	}
	else
	{
		createSystem(shop);
	}
	char command[20];
	cout << "Welcome to our shop.\nFor: \n log in press ""li"" \n sign up press ""su""\n for log in as an system administrator press ""sa"" \n If you want to exit press x. "<<endl;
	do
	{
		
		cin .getline( command,20);
		if (strcmp(command, "li") == 0)//client buys, asks for price and so on
		{
			char clname[max_namesize];
			cout << "Enter username: ";
			cin.getline(clname, max_namesize);
			if (shop.clNameTaken(clname))//if name is taken , then there is a client
			{
				cout << "Welcome back! \n For: \n price of a product: price \n all information about a product: all\n buy a product: buy\n get information for products of the same or all type: same \n log out: lo \n";
				
				do
				{
					cin.getline(command, 20);
					char prname[max_namesize];
					if (strcmp(command, "price") == 0)
					{
						cout << "Enter product name: ";
						cin.getline(prname, max_namesize);
						shop.whatsThePrice(clname, prname);
					}
					else if (strcmp(command, "all") == 0)
					{
						cout << "Enter product name: ";
						cin.getline(prname, max_namesize);
						shop.whatsTheInfo(clname, prname);
					}
					else if (strcmp(command, "buy") == 0)
					{
						cout << "Enter product name: ";
						cin.getline(prname, max_namesize);
						shop.sellProduct(prname, clname);
					}
					else if (strcmp(command, "same") == 0)
					{
						productTypes();
						int type;
						cout << "for all types enter: 4" << endl;
						cin >> type;
						shop.infoForAllOfAkind(clname, type);
					}
					
					
				}while (strcmp(command, "lo") != 0 && strcmp(command, "x") != 0);
				cout << "Thanks for using our shop!" << endl;
			}
			else
				cerr << "No such user!" << endl;

		}
		else if (strcmp(command, "su") == 0)//add a client
		{
			char name[max_namesize];
			int age;
			do
			{
				cout << "Enter name/username: ";
				cin.getline(name, max_namesize);
			} while (shop.clNameTaken(name));
			cout << "Enter your age: ";
			cin >> age;
			Client cl(name, age);
			shop.addClient(cl);
			cout << "Your account has been created. Please log in." << endl;
		}
		else if (strcmp(command, "sa") == 0)//add seller,add product,remove product 
		{
			cout << "Welcome back! If you want to : \n add a product: add \n remove a product: rem \n hire a seller: hire \n log out :lo" << endl;

			do
			{
				cin.getline(command, 20);
				if (strcmp(command, "add")==0)
				{
					productTypes();
					addProduct(shop);
				}
				else if (strcmp(command, "rem") == 0)
				{
					char buff[max_namesize];
					cout << "Enter product name: ";
					cin.getline(buff, max_namesize);
					shop.removeProduct(buff);
				}
				else if (strcmp(command, "hire") == 0)
				{
					char buff[max_namesize];
					int age;
					cout << "Enter name: ";
					cin.getline(buff, max_namesize);
					cout << "Enter age: ";
					cin >> age;
					Seller sl(buff, age);
					shop.addSeller(sl);
				}
			} while (strcmp(command, "lo") != 0&& strcmp(command, "x") != 0);

		}
	}while (strcmp(command, "x") != 0);
	saveToFile(shop);

	return 0;
}


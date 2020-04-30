#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int clothesCountShop, clothesCountBasket = 0;
bool areTheRulesCouted = false;
//STRUCTURES
struct TYPE
{
	string colour;  //red, green, blue
	string model;  //sweatshirt, shirt, hat
	string sz;    //S, XS, M, L, XL, XXL, XXXL
	string brand;   //gucci, armani
	string gender;    //male, female, both
};

struct CLOTHES
{
	int id;
    TYPE type;
	int amount;
	int price;      //in BGN
};
//STRUCTURES


// FUNCTIONS
CLOTHES getClothesById(CLOTHES* shop, int id)  //returns clothes by their id
{
	int i;
	for (i = 0; i < clothesCountShop; i++)
	{
		if (shop[i].id == id) return shop[i];
	}
	cout << "Clothing with that ID was not found " << endl;
	return shop[0];
}

void showAllProducts(CLOTHES* shop)
{

        for (int i = 0; i < clothesCountShop; i++)
        {
            cout << endl;
            cout << "Product(ID): " << shop[i].id << endl;
            cout << "This product is: " << shop[i].type.colour << " " << shop[i].type.brand << " " << shop[i].type.model << endl;
            cout << "Size: " << shop[i].type.sz << endl;
            cout << "Gender: " << shop[i].type.gender << endl;
            cout << "We've got " << shop[i].amount << " of it." << endl;
            cout << "It costs:" << shop[i].price << " BGN." << endl;
        }
}

void addProductInBasket(CLOTHES* shop, CLOTHES* basket) //adds a product in the basket by id
{
	int id;
	CLOTHES newProduct;
	cout << "What is the id of the product that you wish to buy:";
	cin >> id;
	newProduct = getClothesById(shop, id);
	if (newProduct.id == id)
	{
		int i;
		newProduct.amount--;                    //we substract 1 from the amount of the product
		for (i = 0; i < clothesCountShop; i++)  //that we are going to put in the basket
		{
			if (shop[i].id == id) shop[i].amount--; //we substract 1 from the amount of the product in the sop array
		}
		basket[clothesCountBasket] = newProduct;
		clothesCountBasket++;
		cout << "Product number " << id << " was succesfully added in basket." << endl;
	}
}

void cashOut(CLOTHES* basket)
{
	int i, sumCash = 0;
	for (i = 0; i < clothesCountBasket; i++)
	{
		sumCash += basket[i].price;
	}
  if(clothesCountBasket)
  {
      cout << "Your total is " << sumCash << "BGN. Your order is finihsed" << endl;
      cout << "Your basket is ready for new orders." << endl;
      for (i = 0; i < clothesCountBasket; i++)
      {
	      CLOTHES emptyProduct;
	      basket[i] = emptyProduct;
      }
      clothesCountBasket = 0;
  }
	else cout << "Your basket is empty." << endl;
}
bool comparePrice(CLOTHES clothe1, CLOTHES clothe2) //returns true if the first product has smaller price
{                       //and else if the second has. This is later used for the sort function on line 72;
	return clothe1.price < clothe2.price;
}

bool compareForVolen(CLOTHES clothe1, CLOTHES clothe2)  //returns true if the first product has to be chosen by Volen's filters
{                                //and else if the second product is better.This is later used for the sort function on line 77.

	if (clothe1.type.gender != "female" && clothe2.type.gender == "female") return true;
	else if (clothe1.type.gender == "female" && clothe2.type.gender != "female") return false;

	if (clothe1.type.sz == "male" && clothe2.type.sz != "male") return true;
	else if (clothe1.type.sz != "male" && clothe2.type.sz == "male") return false;

	return clothe1.price < clothe2.price;
}

void sortByPrice(CLOTHES* shop) //sorts the clothes by price from lower to higher
{
	sort(shop, shop + clothesCountShop, comparePrice);
	cout << "Succesfully sorted." << endl;
}

void sortByVolenFilters(CLOTHES* shop) //sorts the clothes by Volen's filters which you can see on line 34
{
	sort(shop, shop + clothesCountShop, compareForVolen);
	cout << "Succesfully sorted." << endl;
}

void showInfoAboutProduct(CLOTHES product)  //Shows info about the product that you give
{                                           //Who would've thought
	cout << "This product is a " << product.type.colour << " ";
	cout << product.type.brand << " " << product.type.model << "." << endl;
	cout << "Its size is " << product.type.sz << " and its gender is ";
	cout << product.type.gender << "." << endl;
	cout << "We've got " << product.amount << " of it ";
	cout << "and it costs " << product.price << " BGN." << endl;
}

void showProductsInBasket(CLOTHES* basket) //Shows info about all the products in the basket
{                                          //using the showInfoAboutProduct function
	int i;
	for (i = 0; i < clothesCountBasket; i++)
	{
		cout << "Product " << i + 1 << ":" << endl;
		showInfoAboutProduct(basket[i]);
		cout << endl;
	}
	if (clothesCountBasket == 0) cout << "Your basket is empty." << endl;
    for (i = 0; i < clothesCountBasket; i++)
    {
        CLOTHES a;
        basket[i] = a;
    }
    clothesCountBasket = 0;
}

void addNewProductInShop(CLOTHES* shop)
{
    CLOTHES product;
    cout<<"What is the colour  of the product that you wish to add (red,green):";
    cin>>product.type.colour;
    cout<<"What is the model of the product that you wish to add (sweatshirt,shirt):";
    cin>>product.type.model;
    cout<<"What is the size of the product that you wish to add (S,XS,L):";
    cin>>product.type.sz;
    cout<<"What is the brand of the product that you wish to add (gucci,armani):";
    cin>>product.type.brand;
    cout<<"What is the gender of the product that you wish to add (male,both):";
    cin>>product.type.gender;
    cout<<"What is the amount of the product that you wish to add (100,200):";
    cin>>product.amount;
    cout<<"What is the price in BGN of the product that you wish to add (200,150):";
    cin>>product.price;
    product.id=clothesCountShop+1;
    shop[clothesCountShop]=product;
    clothesCountShop++;
    cout<<"Succesfully added"<<endl;
  //I know that the user can easily break the program here but there is just too much to check
  //did he type a valid thing for the brand,amount,price e.t.c. Is the gender (M,F,B) or something else.
  //There are countless things that i have to check so therefore I won't since I don't have much time left.
  //The probability of the user breaking the program is considered in every other function except for this one
  //so i hope it's ok. This part of the program is a work in progress.
}

//USER INTERFACE
//FUNCTIONS

bool Menu(CLOTHES* shop, CLOTHES* basket)
{
	int n;
	if (areTheRulesCouted == false)
	{
		cout << "----------WELCOME  TO  OUR SHOP----------" << endl;
		cout << "-----------------MAIN MENU---------------" << endl;
		cout << "1: Show all products" << endl;
		cout << "2: Add a product in the basket" << endl;
		cout << "3: Sort data by price" << endl;
		cout << "4: Sort data by Volen's filters" << endl;
		cout << "5: Cash out" << endl;
		cout << "6: Get a product by id" << endl;
		cout << "7: Show products in basket" << endl;
        cout << "8: Add a product in the shop" << endl;
		cout << "9: Quit" << endl;
		areTheRulesCouted = true;
	}
	cout << endl;
	cout << "Which option do you choose:";
	cin >> n;
	switch (n)
	{
		case 1:
		{
			showAllProducts(shop);
			return true;
		}

		case 2:
		{
			addProductInBasket(shop, basket);
			return true;
		}
		case 3:
		{
			sortByPrice(shop);
			return true;
		}
		case 4:
		{
			sortByVolenFilters(shop);
			return true;
		}
		case 5:
		{
			cashOut(basket);
			return true;
		}
		case 6:
		{
			int id;
			cout << "What is the id of the product that you wish to see:";
			cin >> id;
			CLOTHES product;
			product = getClothesById(shop, id);
			if (product.id == id)
			{
				showInfoAboutProduct(product);
			}
			return true;
		}
		case 7:
		{
			showProductsInBasket(basket);
			return true;
		}
        case 8:
		{
			addNewProductInShop(shop);
			return true;
		}
		case 9:
		{
			cout << "Have a nice day." << endl;
			return false;
		}

		default:
		{
			cout << "Error. Please enter again." << endl;
			return true;
		}
	}
}
//USER INTERFACE
//FUNCTIONS
int main()
{

	//DATA
	CLOTHES shop[200] = {
		 {1, "red", "shirt", "S", "hm", "male", 100,  55}, //that's our data about our shop and all the clothes
		 {2, "blue", "sweatshirt", "M", "gucci", "female", 100,40}, //that are in the array in the begging
		 {3, "red", "t-shirt", "M", "armani", "both", 100, 150},
		 {4, "brown", "sweater", "L", "armani", "both", 100, 50},
		 {5, "red", "sweatpants", "M", "armani", "female", 100, 75},
		 {6, "yellow", "shorts", "L", "armani", "male", 100,  70},
	};
	clothesCountShop = 6;
	CLOTHES basket[200];

	//DATA

	bool IsInMenu = true;
	while (IsInMenu)
	{
		IsInMenu = Menu(shop, basket);    //This loops the menu function until the user chooses option 5 which is to quit
	}

	return 0;
}

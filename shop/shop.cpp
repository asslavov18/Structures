#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int clothesCountShop, clothesCountBasket = 0;
bool areTheRulesCouted=false;
///STRUCTURES
struct TYPE
{
    string colour;  ///red, green, blue
    string model;  ///sweatshirt, shirt, hat
    string sz;    ///S, XS, M, L, XL, XXL, XXXL
    string brand;   ///gucci, armani
    char gender;    ///M, F, B
};

struct CLOTHES
{
    TYPE type;
    int amount;
    int id;
    int price;  ///in BGN
};
///STRUCTURES


/// FUNCTIONS
CLOTHES getClothesById(CLOTHES* shop, int id)  ///returns clothes by their id
{
    int i;
    for (i = 0; i < clothesCountShop; i++)
    {
        if (shop[i].id == id) return shop[i];
    }
    cout << "Clothing with that ID was not found" << endl;
}

void addProductInBasket(CLOTHES* shop, CLOTHES* basket)
{
    int id;
    CLOTHES newProduct;
    cout << "What is the id of the product that you wish to buy:";
    cin >> id;
    newProduct = getClothesById(shop, id); 
    basket[clothesCountBasket] = newProduct;
    clothesCountBasket++;
    cout << "Product number " << id << " was succesfully added in basket." << endl;
}
void cashOut(CLOTHES* basket)
{
    cout << "I'll finish this later" << endl;
}
bool comparePrice(CLOTHES clothe1, CLOTHES clothe2) //returns true if the first product has smaller price
{                                                   //and else if the second has. This is later used for the sort function on line 72;
    return clothe1.price < clothe2.price;
}

bool compareForVolen(CLOTHES clothe1, CLOTHES clothe2)  //returns true if the first product has to be chosen by Volen's filters
{                                                       //and else if the second product is better. This is later used for the sort function on line 77.
    if (clothe1.type.gender != 'F' && clothe2.type.gender == 'F') return true;
    else if (clothe1.type.gender == 'F' && clothe2.type.gender != 'F') return false;

    if (clothe1.type.sz == "M" && clothe2.type.sz != "M") return true;
    else if (clothe1.type.sz != "M" && clothe2.type.sz == "M") return false;

    return clothe1.price < clothe2.price;
}

void sortByPrice(CLOTHES* shop) ///sorts the clothes by price from lower to higher
{
    sort(shop, shop + clothesCountShop, comparePrice);
    cout << "Succesfully sorted." << endl;
}

void sortByVolenFilters(CLOTHES* shop) ///sorts the clothes by Volen's filters which you can see on line 34
{
    sort(shop, shop + clothesCountShop, compareForVolen);
    cout << "Succesfully sorted." << endl;
}


bool Menu(CLOTHES* shop, CLOTHES* basket)
{
    int n;
    if (areTheRulesCouted == false)
    {
        cout << "1: Add a product in the basket" << endl;
        cout << "2: Sort data by price" << endl;
        cout << "3: Sort data by Volen's filters" << endl;
        cout << "4: Cash out" << endl;
        cout << "5: Quit" << endl;
        areTheRulesCouted = true;
    }
    cout << endl;
    cout << "Which option do you choose:";
    cin >> n;
    switch (n)
    {
        case 1:
        {
            addProductInBasket(shop, basket);
            return true;
        }
        case 2:
        {
            sortByPrice(shop);
            return true;
        }
        case 3:
        {
            sortByVolenFilters(shop);
            return true;
        }
        case 4:
        {
            cashOut(basket); ///DEBUG!!!!!!!!
            return true;
        }
        case 5:
        {
            cout << "Have a nice day." << endl;
            return false;
        }
        default:
        {
            cout << "Error. Please enter again."<<endl;
            return true;
        }
    }
}
///FUNCTIONS
int main()
{

    ///DATA
    CLOTHES shop[200] = {
         {"red", "shirt", "S", "hm", 'M', 100, 1, 55},           ///that's our data about our shop and all the clothes that are in the array in the begging
         {"blue", "sweatshirt", "M", "gucci", 'W', 100, 2, 40},
         {"red", "t-shirt", "M", "armani", 'B', 100, 3, 150},
         {"brown", "sweater", "L", "armani", 'B', 100, 4, 50},
         {"red", "sweatpants", "M", "armani", 'W', 100, 5, 75},
         {"yellow", "shorts", "L", "armani", 'M', 100, 6, 70},
    };
    clothesCountShop = 6;
    CLOTHES basket[200];

    ///DATA

    ///TESTING THE FUNCTIONS

    /*sortByPrice(shop);
    cout << shop[0].price << endl;
    CLOTHES a;
    a = getClothesById(shop, 5);
    cout << a.id << endl;     
    if (CompareForVolen(shop[2], shop[3]) == true) cout << shop[2].type.model << "AAAA" << endl;
    else cout << shop[3].type.model << "BBB" << endl;*/
    bool IsInMenu=true;
    while (IsInMenu)
    {
        IsInMenu=Menu(shop, basket);    ///This loops the menu function until the user chooses option 5 which is to quit
    }
    

    ///TESTING THE FUNCTIONS
    return 0;
}

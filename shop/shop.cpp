#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

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
bool ComparePrice(CLOTHES clothe1, CLOTHES clothe2)
{
    return clothe1.price < clothe2.price;
}

bool CompareForVolen(CLOTHES clothe1, CLOTHES clothe2)
{
    if (clothe1.type.gender != 'F' && clothe2.type.gender == 'F') return true;
    else if (clothe1.type.gender == 'F' && clothe2.type.gender != 'F') return false;

    if (clothe1.type.sz == "M" && clothe2.type.sz != "M") return true;
    else if (clothe1.type.sz != "M" && clothe2.type.sz == "M") return false;
   
   return clothe1.price<clothe2.price;
}

void sortByPrice(CLOTHES* shop, int clothesCount) ///sorts the clothes by price from lower to higher
{
    sort(shop, shop + clothesCount, ComparePrice);
}



CLOTHES getClothesById(CLOTHES* shop, int clothesCount, int id)  ///returns clothes by their id
{
    int i;
    for (i = 0; i < clothesCount; i++)
    {
        if (shop[i].id == id) return shop[i];
    }
    cout << "Clothing with that ID was not found" << endl;
}

///FUNCTIONS
int main()
{

  ///DATA
   CLOTHES shop[200] = {
        {"red", "shirt", "S", "hm", 'M', 100, 1, 55},
        {"blue", "sweatshirt", "M", "gucci", 'W', 100, 2, 40},
        {"red", "t-shirt", "M", "armani", 'B', 100, 3, 150},
        {"brown", "sweater", "L", "armani", 'B', 100, 4, 50},
        {"red", "sweatpants", "M", "armani", 'W', 100, 5, 75},
        {"yellow", "shorts", "L", "armani", 'M', 100, 6, 70},
    };

   ///DATA

   ///TESTING THE FUNCTIONS

   int clothesCount = 6;
   /**sortByPrice(shop, clothesCount);
   cout << shop[0].price << endl;
   CLOTHES a;
   a = getClothesById(shop, clothesCount, 5);
   cout << a.id << endl;     */       
  if(CompareForVolen( shop[2], shop[3])==true) cout<<shop[2].type.model <<"AAAA"<<endl;
  else cout<<shop[3].type.model<<"BBB"<<endl;


   ///TESTING THE FUNCTIONS
  return 0;
}
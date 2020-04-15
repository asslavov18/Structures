#include<iostream>
#include<string>
using namespace std;
struct TYPE
{
    string colour;  ///red,green,blue
    string model;  ///sweatshirt,shirt,hat
    string sz;    ///S,XS,M,L,XL,XXL,XXXL
    string brand;   ///gucci,armani
    char gender;    ///M,F,B
};
struct CLOTHES
{
    TYPE type;
    int amount;
    int id;
    int price;  ///in BGN
};
int main()
{
    CLOTHES shop[200] = {
        {"red", "shirt", "S", "hm", 'M', 100, 1, 35},
        {"blue", "sweatshirt", "M", "gucci", 'W', 100, 2, 40},
        {"red", "t-shirt", "M", "armani", 'B', 100, 3, 150},
        {"brown", "sweater", "L", "armani", 'B', 100, 4, 50},
        {"red", "sweatpants", "M", "armani", 'W', 100, 5, 75},
        {"red", "shorts", "L", "armani", 'M', 100, 6, 70},
    };
    return 0;
}

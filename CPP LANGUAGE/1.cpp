#include <iostream>
using namespace std;

class MenuItem
{
protected:
    int item_id;
    char item_name[50];
    double price;

    virtual void setMenuItems() = 0;
    virtual void getMenuItems() = 0;
};

class Beverage
{
};

class MainCourse
{
};

class Dessert
{
};

int main()
{
    return 0;
}
#include <iostream>
#include <string.h>
using namespace std;

class MenuItem
{
protected:
    int item_id;
    char item_name[50];
    double price;

    // virtual void setMenuItems() = 0;
    // virtual void getMenuItems() = 0;
    virtual void menuDisplay() = 0;
};

class Beverage : public MenuItem
{
protected:
    double size;
    char ingredients[50];
    char category[50];

public:
    void setMenuItemsForBeverage()
    {
        system("cls");

        cout << endl
             << "\t Beverage" << endl;
        cout << "Enter Item Id\t: ";
        cin >> item_id;
        cout << "Enter Item Name\t: ";
        cin >> item_name;
        cout << "Enter Item Price\t: ";
        cin >> price;
        cout << "Enter Item Size\t: ";
        cin >> size;
        cout << "Enter Item Ingredients\t: ";
        cin >> ingredients;
        // getMenuItemsForBeverages();
    }

    void getMenuItemsForBeverages()
    {
        strcpy(category, "Beverages");
        cout << endl
             << "\t" << item_id << "\t" << item_name << "\t" << price << "\t" << size << "\t" << ingredients << "\t" << category << endl;
    }

    void menuDisplay()
    {
        cout << endl
             << "\t\t"
             << "DISPLAY ITEMS" << endl
             << endl;

        cout << endl
             << "\tITEM ID\tITEM NAME\tPRICE\tSIZE\tINGREDIENTS\tCATEGORY\t" << endl;
        cout << endl
             << "-------\t----------\t----\t----\t-----------\t--------\t" << endl;
    }
};

class MainCourse : public MenuItem
{
protected:
    double size;
    char ingredients[50];
    char category[50];

public:
    void setMenuItemsForMainCourse()
    {
        system("cls");

        cout << endl
             << "\t MainCourse" << endl;
        cout << "Enter Item Id\t: ";
        cin >> item_id;
        cout << "Enter Item Name\t: ";
        cin >> item_name;
        cout << "Enter Item Price\t: ";
        cin >> price;
        cout << "Enter Item Size\t: ";
        cin >> size;
        cout << "Enter Item Ingredients\t: ";
        cin >> ingredients;
    }

    void getMenuItemsForMainCourse()
    {
        strcpy(category, "Main Course");
        cout << endl
             << "\t" << item_id << "\t" << item_name << "\t" << price << "\t" << size << "\t" << ingredients << "\t" << category << endl;
    }
    void menuDisplay()
    {
        cout << endl
             << "\t\t"
             << "DISPLAY ITEMS" << endl
             << endl;

        cout << endl
             << "\tITEM ID\tITEM NAME\tPRICE\tSIZE\tINGREDIENTS\tCATEGORY\t" << endl;
        cout << endl
             << "-------\t----------\t----\t----\t-----------\t--------\t" << endl;
    }
};

class Dessert : public MenuItem
{
protected:
    double size;
    char ingredients[50];
    char category[50];

public:
    void setMenuItemsForDessert()
    {
        system("cls");

        cout << endl
             << "\t Dessert" << endl;
        cout << "Enter Item Id\t: ";
        cin >> item_id;
        cout << "Enter Item Name\t: ";
        cin >> item_name;
        cout << "Enter Item Price\t: ";
        cin >> price;
        cout << "Enter Item Size\t: ";
        cin >> size;
        cout << "Enter Item Ingredients\t: ";
        cin >> ingredients;
    }

    void getMenuItemsForDessert()
    {
        strcpy(category, "Dessert");
        cout << endl
             << "\t" << item_id << "\t" << item_name << "\t" << price << "\t" << size << "\t" << ingredients << "\t" << category << endl;
    }
    void menuDisplay()
    {
        cout << endl
             << "\t\t"
             << "DISPLAY ITEMS" << endl
             << endl;

        cout << endl
             << "\tITEM ID\tITEM NAME\tPRICE\tSIZE\tINGREDIENTS\tCATEGORY\t" << endl;
        cout << endl
             << "\t-------\t----------\t----\t----\t-----------\t--------\t" << endl;
    }
};

class Menu : public Beverage, public MainCourse, public Dessert
{
public:
    void menuAddMethods()
    {

        cout << endl
             << endl
             << endl
             << "\tWELCOME TO ONLINE FOOD ORDERING" << endl
             << endl;
        cout << "Please Enter 01 for Adding a new menu item" << endl;
        cout << "Please Enter 02 for Displaying the menu" << endl;
        cout << "Please Enter 03 for Calculating the total price of selected items" << endl;
        cout << "Please Enter 04 for Exit" << endl
             << endl;
    }

    void menuCategoties()
    {
        cout << endl
             << "\t\t"
             << "ADD ITEMS" << endl
             << endl;

        cout << "\tEnter B for Beverage Order" << endl;
        cout << "\tEnter M for Main Course Order" << endl;
        cout << "\tEnter D for Dessert Order" << endl;
    }
};

int main()
{
    Menu menu;

    int b = 0, m = 0, d = 0;
    int n;
    Beverage b1[b];
    MainCourse m1[m];
    Dessert d1[d];

    do
    {
        menu.menuAddMethods();

        cout << "Enter any choice\t: ";
        cin >> n;

        switch (n)
        {
        case 01:
            system("cls");
            menu.menuCategoties();

            char ch;
            cout << endl
                 << "Enter any choice\t: ";
            cin >> ch;

            switch (ch)
            {
            case 'B':
            case 'b':
                system("cls");
                b1[b].setMenuItemsForBeverage();
                b++;
                system("cls");
                break;

            case 'M':
            case 'm':
                system("cls");
                m1[m].setMenuItemsForMainCourse();
                m++;
                system("cls");
                break;

            case 'D':
            case 'd':
                system("cls");
                d1[d].setMenuItemsForDessert();
                d++;
                system("cls");
                break;

            default:
                system("cls");
                cout
                    << endl
                    << "Invalid Choice" << endl;
                break;
            }

            break;

        case 02:
            system("cls");

            menu.Dessert::menuDisplay();

            for (int i = 0; i < b; i++)
            {
                b1[i].getMenuItemsForBeverages();
            }
            for (int i = 0; i < m; i++)
            {
                m1[i].getMenuItemsForMainCourse();
            }
            for (int i = 0; i < d; i++)
            {
                d1[i].getMenuItemsForDessert();
            }

            break;

        case 03:
            break;

        case 04:
            cout << endl
                 << "EXIT" << endl;
            break;

        default:
            system("cls");
            cout << endl
                 << "Invalide Choice" << endl;
            break;
        }
    } while (n != 4);

    return 0;
}
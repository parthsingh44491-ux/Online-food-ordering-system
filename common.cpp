#include "models.h"

vector<User> users;
vector<CartItem> cart;

Food menu[] =
{
    {101, "Veg Burger", "Fast Food", 120},
    {102, "Cheese Pizza", "Pizza", 250},
    {103, "French Fries", "Snacks", 90},
    {104, "Veg Sandwich", "Snacks", 100},
    {105, "Pasta", "Italian", 180},
    {106, "Paneer Roll", "Fast Food", 130},
    {107, "Veg Momos", "Chinese", 80},
    {108, "Cold Coffee", "Beverages", 90},
    {109, "Chocolate Cake", "Dessert", 150},
    {110, "Masala Dosa", "South Indian", 110}
};

const int FOOD_COUNT = sizeof(menu) / sizeof(menu[0]);
const double DELIVERY_CHARGE = 40.0;

int loggedInUser = -1;

string deliveryAddress = "";
string deliveryPhone = "";
string deliveryType = "";

string readText(string prompt)
{
    string input;
    cout << prompt;

    if (!getline(cin, input))
        exit(0);

    return input;
}

int readNumber(string prompt)
{
    string input;
    int number;
    char extra;

    while (true)
    {
        cout << prompt;

        if (!getline(cin, input))
            exit(0);

        stringstream ss(input);

        if (ss >> number && !(ss >> extra))
            return number;

        cout << "Invalid input! Enter a whole number.\n";
    }
}
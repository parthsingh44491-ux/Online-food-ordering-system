#include "models.h"

int findFood(int id)
{
    for (int i = 0; i < FOOD_COUNT; i++)
    {
        if (menu[i].id == id)
            return i;
    }

    return -1;
}

void displayMenu()
{
    cout << "\n================ FOOD MENU ================\n";

    cout << left
         << setw(10) << "FOOD ID"
         << setw(23) << "FOOD NAME"
         << setw(18) << "CATEGORY"
         << "PRICE (Rs.)\n";

    cout << string(65, '-') << '\n';

    for (int i = 0; i < FOOD_COUNT; i++)
    {
        cout << left
             << setw(10) << menu[i].id
             << setw(23) << menu[i].name
             << setw(18) << menu[i].category
             << fixed << setprecision(2)
             << menu[i].price << '\n';
    }
}

void sortMenuByPrice()
{
    for (int i = 0; i < FOOD_COUNT - 1; i++)
    {
        for (int j = 0; j < FOOD_COUNT - i - 1; j++)
        {
            if (menu[j].price > menu[j + 1].price)
            {
                Food temp = menu[j];
                menu[j] = menu[j + 1];
                menu[j + 1] = temp;
            }
        }
    }

    cout << "Menu sorted by price.\n";
    displayMenu();
}
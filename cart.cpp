#include "models.h"

void addToCart()
{
    if (loggedInUser == -1)
    {
        cout << "Please log in before ordering.\n";
        return;
    }

    while (true)
    {
        displayMenu();

        int id = readNumber("Enter Food ID (0 to finish): ");

        if (id == 0)
            return;

        int index = findFood(id);

        if (index == -1)
        {
            cout << "Invalid Food ID!\n";
            continue;
        }

        int quantity = readNumber("Enter quantity: ");

        if (quantity < 1 || quantity > 100)
        {
            cout << "Quantity must be between 1 and 100.\n";
            continue;
        }

        bool found = false;

        for (CartItem &item : cart)
        {
            if (item.foodId == id)
            {
                if (item.quantity + quantity > 100)
                {
                    cout << "Maximum quantity is 100 per item.\n";
                    return;
                }

                item.quantity += quantity;
                found = true;
                break;
            }
        }

        if (!found)
            cart.push_back({id, quantity});

        cout << menu[index].name << " added to cart!\n";
    }
}

double displayCart()
{
    cout << "\n========== SHOPPING CART ==========\n";

    double total = 0;

    if (cart.empty())
    {
        cout << "Your cart is empty.\n";
        return 0;
    }

    cout << left
         << setw(23) << "FOOD ITEM"
         << setw(12) << "QUANTITY"
         << setw(15) << "PRICE"
         << "AMOUNT\n";

    for (const CartItem &item : cart)
    {
        int index = findFood(item.foodId);

        if (index == -1)
            continue;

        double amount = menu[index].price * item.quantity;
        total += amount;

        cout << left
             << setw(23) << menu[index].name
             << setw(12) << item.quantity
             << setw(15) << fixed << setprecision(2)
             << menu[index].price
             << amount << '\n';
    }

    cout << "Food subtotal: Rs. "
         << fixed << setprecision(2) << total << '\n';

    return total;
}
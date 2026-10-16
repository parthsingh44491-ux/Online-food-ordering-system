#include "models.h"

void selectDelivery()
{
    if (loggedInUser == -1)
    {
        cout << "Please log in first!\n";
        return;
    }

    cout << "\n========== DELIVERY OPTIONS ==========\n";
    cout << "1. Home Delivery (Rs. 40)\n";
    cout << "2. Self Pickup (Free)\n";

    int choice = readNumber("Choose delivery option: ");

    if (choice == 1)
    {
        string address = readText("Enter complete address: ");
        string phone = readText("Enter delivery phone number: ");

        if (address.empty() || phone.empty())
        {
            cout << "Address and phone cannot be empty!\n";
            return;
        }

        deliveryType = "Home Delivery";
        deliveryAddress = address;
        deliveryPhone = phone;

        cout << "Home delivery selected successfully!\n";
    }
    else if (choice == 2)
    {
        deliveryType = "Self Pickup";
        deliveryAddress = "";
        deliveryPhone = "";

        cout << "Self pickup selected. No delivery charge.\n";
    }
    else
    {
        cout << "Invalid delivery option!\n";
    }
}
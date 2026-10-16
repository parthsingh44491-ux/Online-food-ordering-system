#include "models.h"

void checkout()
{
    if (loggedInUser == -1)
    {
        cout << "Please log in before checkout.\n";
        return;
    }

    if (cart.empty())
    {
        cout << "Your cart is empty!\n";
        return;
    }

    if (deliveryType.empty())
    {
        cout << "Select a delivery option first.\n";
        selectDelivery();

        if (deliveryType.empty())
            return;
    }

    double subtotal = displayCart();

    double deliveryCharge =
        (deliveryType == "Home Delivery")
        ? DELIVERY_CHARGE : 0.0;

    double finalTotal = subtotal + deliveryCharge;

    cout << "\n========== FINAL BILL ==========\n";
    cout << "Customer: " << users[loggedInUser].name << '\n';
    cout << "User ID: " << users[loggedInUser].id << '\n';
    cout << "Delivery type: " << deliveryType << '\n';

    if (deliveryType == "Home Delivery")
    {
        cout << "Address: " << deliveryAddress << '\n';
        cout << "Phone: " << deliveryPhone << '\n';
    }

    cout << fixed << setprecision(2);
    cout << "Food subtotal: Rs. " << subtotal << '\n';
    cout << "Delivery charge: Rs. " << deliveryCharge << '\n';
    cout << "Final total: Rs. " << finalTotal << '\n';

    string confirm = readText("Confirm order? (yes/no): ");

    if (confirm == "yes" || confirm == "YES" ||
        confirm == "Yes")
    {
        cout << "Order placed successfully!\n";
        cout << "Thank you for ordering!\n";

        cart.clear();
        deliveryType = "";
        deliveryAddress = "";
        deliveryPhone = "";
    }
    else
    {
        cout << "Order not placed. Cart retained.\n";
    }
}
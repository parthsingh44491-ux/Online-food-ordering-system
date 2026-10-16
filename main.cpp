#include "models.h"

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    while (true)
    {
        cout << "\n============================================\n";
        cout << "       ONLINE FOOD ORDERING SYSTEM\n";
        cout << "============================================\n";
        cout << "1. Register User\n";
        cout << "2. Login\n";
        cout << "3. Display Registered Users\n";
        cout << "4. Display Food Menu\n";
        cout << "5. Add Food to Cart\n";
        cout << "6. View Shopping Cart\n";
        cout << "7. Sort Menu by Price\n";
        cout << "8. Checkout\n";
        cout << "9. Select Delivery Option\n";
        cout << "10. Exit\n";

        int choice = readNumber("Enter your choice: ");

        switch (choice)
        {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: displayUsers(); break;
            case 4: displayMenu(); break;
            case 5: addToCart(); break;
            case 6: displayCart(); break;
            case 7: sortMenuByPrice(); break;
            case 8: checkout(); break;
            case 9: selectDelivery(); break;

            case 10:
                cout << "Thank you for using our system!\n";
                return 0;

            default:
                cout << "Invalid choice! Select 1 to 10.\n";
        }
    }
}
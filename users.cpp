#include "models.h"

int findUser(string id)
{
    for (int i = 0; i < (int)users.size(); i++)
    {
        if (users[i].id == id)
            return i;
    }

    return -1;
}

void registerUser()
{
    cout << "\n========== USER REGISTRATION ==========\n";

    if (!verifyCaptcha())
        return;

    User u;

    u.id = readText("Enter User ID: ");

    if (u.id.empty() || findUser(u.id) != -1)
    {
        cout << "Invalid or already registered User ID!\n";
        return;
    }

    u.name = readText("Enter Name: ");
    u.phone = readText("Enter Phone Number: ");

    if (u.name.empty() || u.phone.empty())
    {
        cout << "Name and phone cannot be empty!\n";
        return;
    }

    users.push_back(u);

    cout << "Registration successful! Welcome, "
         << u.name << "!\n";
}

void loginUser()
{
    if (users.empty())
    {
        cout << "Register first.\n";
        return;
    }

    if (!verifyCaptcha())
        return;

    string id = readText("Enter User ID: ");
    int index = findUser(id);

    if (index == -1)
    {
        cout << "User not found!\n";
        return;
    }

    loggedInUser = index;

    cout << "Login successful! Welcome, "
         << users[index].name << "!\n";
}

void displayUsers()
{
    cout << "\n========== REGISTERED USERS ==========\n";

    if (users.empty())
    {
        cout << "No registered users found.\n";
        return;
    }

    cout << left
         << setw(15) << "USER ID"
         << setw(25) << "NAME"
         << "PHONE NUMBER\n";

    cout << string(55, '-') << '\n';

    for (const User &u : users)
    {
        cout << left
             << setw(15) << u.id
             << setw(25) << u.name
             << u.phone << '\n';
    }

    cout << "Total registered users: "
         << users.size() << '\n';
}
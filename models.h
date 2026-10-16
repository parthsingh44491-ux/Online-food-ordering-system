#ifndef MODELS_H
#define MODELS_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

struct User
{
    string id;
    string name;
    string phone;
};

struct Food
{
    int id;
    string name;
    string category;
    double price;
};

struct CartItem
{
    int foodId;
    int quantity;
};

extern vector<User> users;
extern vector<CartItem> cart;

extern Food menu[];
extern const int FOOD_COUNT;
extern const double DELIVERY_CHARGE;

extern int loggedInUser;
extern string deliveryAddress;
extern string deliveryPhone;
extern string deliveryType;

// Input module
string readText(string prompt);
int readNumber(string prompt);

// CAPTCHA module
bool verifyCaptcha();

// User module
int findUser(string id);
void registerUser();
void loginUser();
void displayUsers();

// Menu module
int findFood(int id);
void displayMenu();
void sortMenuByPrice();

// Cart module
void addToCart();
double displayCart();

// Delivery module
void selectDelivery();

// Checkout module
void checkout();

#endif
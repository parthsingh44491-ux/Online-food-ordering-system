#include "models.h"

bool verifyCaptcha()
{
    int a = 1 + rand() % 20;
    int b = 1 + rand() % 10;

    cout << "\n========== CAPTCHA ==========\n";
    cout << "Solve: " << a << " + " << b << " = ?\n";

    int answer = readNumber("Enter answer: ");

    if (answer == a + b)
    {
        cout << "CAPTCHA verified successfully!\n";
        return true;
    }

    cout << "Incorrect CAPTCHA!\n";
    return false;
}
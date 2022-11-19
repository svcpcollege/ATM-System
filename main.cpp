// An Automated Teller machine (ATM).

#include <iostream>
using namespace std;

#define MAX 10000000;

class User
{
    long int accountNumber;
    int pin;
    int balance;
    int withdraw;
    int deposit;
    int transfer;

public:
    User(long int accountNumber, int pin)
    {
        this->accountNumber = accountNumber;
        this->pin = pin;
        this->balance = 0;
        this->withdraw = 0;
        this->deposit = 0;
        this->transfer = 0;
    }

    void addFunds(int amount)
    {
        this->balance += amount;
        this->deposit += amount;
    }

    void displayUserInfo()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Pin: " << pin << endl;
        cout << "Balance: " << balance << endl;
        cout << "Withdraw: " << withdraw << endl;
        cout << "Deposit: " << deposit << endl;
        cout << "Transfer: " << transfer << endl;
    }
};

int main()
{
    User user1(123456789, 1234);
    user1.displayUserInfo();
    return 1;
}
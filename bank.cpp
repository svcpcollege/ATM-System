#include <iostream>
using namespace std;

#define TOTAL_ACCOUNTS 1000000

class BankAccounts
{
private:
    /* data */
protected:
    long int acc_number;
    long int acc_card_number;
    string acc_holder_name;
    long int acc_balance;
    long int acc_PIN;

public:
    BankAccounts(/* args */);
    ~BankAccounts();
};

BankAccounts::BankAccounts(/* args */)
{
    acc_number = 123456789;
    acc_card_number = 12341234;
    acc_holder_name = "John Doe";
    acc_balance = 100000;
    acc_PIN = 1234;
}

BankAccounts::~BankAccounts()
{
}

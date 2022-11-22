// An Automated teller Machine (ATM) program
#include <iostream>
using namespace std;

class User
{
private:
    /* data */
protected:
    long int user_account_number;
    long int user_card_number;
    int user_PIN;

public:
    User();
    ~User();
};

User::User()
{
}

User::~User()
{
}

class ATM : public User
{
private:
    const long int MAX_VOLUME = 1000000;
    const long int MAX_WITHDRAW = 100000;
    const bool ATM_Status = true;
    long int withdraw_amount;
    long int deposit_amount;
    long int transfer_amount;

public:
    ATM();
    ~ATM();
};

ATM::ATM()
{
}

ATM::~ATM()
{
}

int main()
{
    ATM atm;
    return 0;
}
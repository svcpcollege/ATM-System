// Automated Teller Machine (ATM) Project

#include <iostream>
#include <unistd.h> // windows.h for windows
#include "bank.cpp"
using namespace std;

class User
{
protected:
    long int user_card_number;
    int user_pin;

public:
    ~User()
    {
    }
    void get_user_card_number()
    {
        cout << "Enter your card number: ";
        cin.clear();
        cin >> user_card_number;
    }
    void get_user_pin()
    {
        cout << "Enter your pin: ";
        cin.clear();
        cin >> user_pin;
    }
};

class ATM : public User, public BankAccounts
{
private:
    const long int MAX_VOLUME = 1000000;
    const long int MAX_WITHDRAW = 100000;
    bool ATM_Status;

    // Variables needed to handle multiple accounts
    long int ATM_acc_number;
    long int ATM_acc_card_number;
    string ATM_acc_holder_name;
    long int ATM_acc_balance;
    long int ATM_acc_PIN;

public:
    ATM();
    ~ATM();

    void display_menu();

    void display_user_details();
    void withdraw()
    {
        get_user_card_number();
        get_user_pin();
        if (user_card_number == ATM_acc_card_number && user_pin == ATM_acc_PIN)
        {
            long int withdraw_amount;
            cout << "Enter the amount to withdraw: ";
            cin >> withdraw_amount;
            if (withdraw_amount > acc_balance)
            {
                cout << "Insufficient balance" << endl;
            }
            else if (withdraw_amount > MAX_WITHDRAW)
            {
                cout << "You can only withdraw max: " << MAX_WITHDRAW << endl;
            }
            else
            {
                acc_balance -= withdraw_amount;
                cout << endl;
                cout << "Please collect your cash" << endl;
                cout << "Your balance is: " << acc_balance << endl;
            }
        }
        else
        {
            cout << "Invalid card number or pin" << endl;
        }
    }
    void deposit()
    {
        get_user_card_number();
        get_user_pin();
        if (user_card_number == ATM_acc_card_number && user_pin == ATM_acc_PIN)
        {
            long int deposit_amount;
            cout << "Enter the amount to deposit: ";
            cin >> deposit_amount;
            if (deposit_amount > MAX_VOLUME)
            {
                cout << "You can only deposit max: " << MAX_VOLUME << endl;
            }
            else
            {
                acc_balance += deposit_amount;
                cout << endl;
                cout << "money deposited successfully" << endl;
                cout << "Your balance is: " << acc_balance << endl;
            }
        }
        else
        {
            cout << "Invalid card number or pin" << endl;
        }
    }
    void check_balance()
    {
        get_user_card_number();
        get_user_pin();
        if (user_card_number == ATM_acc_card_number && user_pin == ATM_acc_PIN)
        {
            cout << endl;
            cout << "Your balance is: " << acc_balance << endl;
            display_user_details();
        }
        else
        {
            cout << "Invalid card number or pin" << endl;
        }
    }
};

ATM::ATM()
{
    ATM_Status = true;
    ATM_acc_number = acc_number;
    ATM_acc_card_number = acc_card_number;
    ATM_acc_holder_name = acc_holder_name;
    ATM_acc_balance = acc_balance;
    ATM_acc_PIN = acc_PIN;

    // for(int acc_slot = 0; acc_slot < 1000000 ; acc_slot++)
    // for multiple accounts


    system("clear");
    cout << "----WELCOME TO ATM----" << endl;
    cout << "Time: " << __TIME__ << endl;
}

ATM::~ATM()
{
}

void ATM::display_menu()
{
    int choice;
    while (ATM_Status == true)
    {
        cout << endl;
        cout << "1. Check Balance and account details" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            check_balance();
            break;
        case 2:
            withdraw();
            break;
        case 3:
            deposit();
            break;
        case 4:
            ATM_Status = false;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}

void ATM::display_user_details()
{
    if (user_card_number == acc_card_number && user_pin == acc_PIN)
    {
        cout << endl;
        cout << "Account Number: " << ATM_acc_number << endl;
        cout << "Account Holder Name: " << ATM_acc_holder_name << endl;
        cout << "Card Number: " << ATM_acc_card_number << endl;
        cout << "Account Balance: " << ATM_acc_balance << endl;
        cout << endl;
    }
    else
    {
        cout << "Invalid card number or pin" << endl;
    }
}

int main()
{
    
    ATM session1;
    sleep(3);
    system("clear");
    session1.display_menu();
    cout << endl;
    cout << "Thank you for using our ATM" << endl;
    return 0;
}

#include <iostream>
#include <fstream>
using namespace std;

class Account
{
    long int accountNumber;
    long int balance;
    int password;
    string Name;

public:
    Account(long int accountNumber, long int balance, int password, string Name)
    {
        this->accountNumber = accountNumber;
        this->balance = balance;
        this->password = password;
        this->Name = Name;
    }
    ~Account()
    {
    }
    static long int returnNumber_of_accounts()
    {
        ifstream fin;
        fin.open("ACCOUNTS.txt");
        long int accountNumber;
        long int balance;
        int password;
        string Name;
        long int count = 0;
        while (fin >> accountNumber >> balance >> password >> Name)
        {
            count++;
        }
        fin.close();
        return count;
    }
    void addAccount()
    {
        ofstream fout;
        fout.open("ACCOUNTS.txt", ios::app);
        fout << accountNumber << " " << balance << " " << password << " " << Name << endl;
        fout.close();
    }

    int searchAccount()
    {
        ifstream fin;
        fin.open("ACCOUNTS.txt");
        long int accountNumber;
        long int balance;
        int password;
        string Name;
        while (fin >> accountNumber >> balance >> password >> Name)
        {
            if (accountNumber == this->accountNumber && Name == this->Name)
            {
                fin.close();
                cout << "Account Found" << endl;
                return 1;
            }
        }
        fin.close();
        cout << "Account Not Found" << endl;
        return 0;
    }

    void removeAccount()
    {
        ifstream fin;
        fin.open("ACCOUNTS.txt");
        ofstream fout;
        fout.open("TEMP.txt");
        long int accountNumber;
        long int balance;
        int password;
        string Name;
        while (fin >> accountNumber >> balance >> password >> Name)
        {
            if (accountNumber != this->accountNumber && Name != this->Name)
            {
                fout << accountNumber << " " << balance << " " << password << " " << Name << endl;
            }
        }
        fin.close();
        fout.close();
        remove("ACCOUNTS.txt");
        rename("TEMP.txt", "ACCOUNTS.txt");
    }

    long int returnAccountNumber()
    {
        return this->accountNumber;
    }
    long int returnBalance()
    {
        return this->balance;
    }
    int returnPassword()
    {
        return this->password;
    }
    string returnName()
    {
        return this->Name;
    }
};

int main()
{
    
    return 0;
}
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
        ifstream fin;
        fin.open("ACCOUNTS.txt", ios::in);
        long int accno;
        long int bal;
        int pass;
        string name;
        while (fin >> accno >> bal >> pass >> name)
        {
            if (accno == this->accountNumber && name == this->Name)
            {
                fin.close();
                return accno;
            }
        }
    }
    long int returnBalance()
    {
        ifstream fin;
        fin.open("ACCOUNTS.txt", ios::in);
        long int accno;
        long int bal;
        int pass;
        string name;
        while (fin >> accno >> bal >> pass >> name)
        {
            if (accno == this->accountNumber && name == this->Name)
            {
                fin.close();
                return bal;
            }
        }
    }
    int returnPassword()
    {
        ifstream fin;
        fin.open("ACCOUNTS.txt", ios::in);
        long int accno;
        long int bal;
        int pass;
        string name;
        while (fin >> accno >> bal >> pass >> name)
        {
            if (accno == this->accountNumber && name == this->Name)
            {
                fin.close();
                return pass;
            }
        }
    }
    string returnName()
    {
        ifstream fin;
        fin.open("ACCOUNTS.txt", ios::in);
        long int accno;
        long int bal;
        int pass;
        string name;
        while (fin >> accno >> bal >> pass >> name)
        {
            if (accno == this->accountNumber && name == this->Name)
            {
                fin.close();
                return name;
            }
        }
    }
};

int main()
{
    return 0;
}
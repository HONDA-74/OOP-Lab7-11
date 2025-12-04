#include <iostream>
using namespace std;

class BankAccount {
    string accountHolderName;
    int accountNumber;
    double balance;
    static int nextID;
    static int accountCount;

public:
    BankAccount() {
        accountHolderName = "Unknown";
        balance = 0.0;
        accountNumber = nextID++;
        accountCount++;
    }

    BankAccount(string name) {
        accountHolderName = name;
        balance = 0.0;
        accountNumber = nextID++;
        accountCount++;
    }

    BankAccount& deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Deposit amount must be positive!" << endl;
        }
        return *this;
    }

    BankAccount& withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: " << amount << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            cout << "Withdrawal amount must be positive!" << endl;
        }
        return *this;
    }

    void showAccount() const {
        cout << "\nAccount Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    double getBalance() const {
        return balance;
    }

    static void showCounter() {
        cout << "\nTotal accounts created: " << accountCount << endl;
    }

    ~ BankAccount(){
        accountCount--;
    }
};

int BankAccount::nextID = 1001;
int BankAccount::accountCount = 0;


int main() {
    BankAccount acc1("Alice");
    BankAccount acc2("Bob");

    acc1.deposit(500).withdraw(200);
    acc2.deposit(1000).withdraw(150);

    acc1.showAccount();
    acc2.showAccount();

    BankAccount::showCounter();

    return 0;
}

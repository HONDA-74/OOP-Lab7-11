#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    string accountHolderName;
    int accountNumber;
    double balance;
    static int nextID;
    static int accountCount;

public:
    BankAccount() = delete;

    BankAccount(string name, double bal = 0.0)
        : accountHolderName(name), balance(bal), accountNumber(nextID++) {
        accountCount++;
        cout << "Account created for " << name << " (ID: " << accountNumber << ")\n";
    }

    BankAccount(const BankAccount&) = delete;
    BankAccount& operator=(const BankAccount&) = delete;

    BankAccount(BankAccount&& other) noexcept
        : accountHolderName(other.accountHolderName),
          accountNumber(other.accountNumber),
          balance(other.balance) {
        other.balance = 0;
        other.accountNumber = -1;
        accountCount++;
        cout << "Move constructor called!\n";
    }

    BankAccount& operator=(BankAccount&& other) noexcept {
        if (this != &other) {
            accountHolderName = other.accountHolderName;
            balance = other.balance;
            accountNumber = other.accountNumber;

            other.balance = 0;
            other.accountNumber = -1;

            cout << "Move assignment operator called!\n";
        }
        return *this;
    }

    BankAccount& deposit(double amount) {
        if (amount > 0)
            balance += amount;
        else
            cout << "Invalid deposit!\n";
        return *this;
    }

    BankAccount& withdraw(double amount) {
        if (amount > 0 && amount <= balance)
            balance -= amount;
        else
            cout << "Invalid withdraw!\n";
        return *this;
    }

    void showAccount() const {
        cout << "---------------------------------\n";
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "---------------------------------\n";
    }

    static void showCounter() {
        cout << "\nTotal accounts created: " << accountCount << endl;
    }

    friend ostream& operator<<(ostream& out, const BankAccount& acc) {
        out << "[Account Holder: " << acc.accountHolderName
            << ", Number: " << acc.accountNumber
            << ", Balance: " << acc.balance << "]";
        return out;
    }

    friend istream& operator>>(istream& in, BankAccount& acc) {
        cout << "Enter account holder name: ";
        in >> acc.accountHolderName;
        cout << "Enter balance: ";
        in >> acc.balance;
        acc.accountNumber = nextID++;
        accountCount++;
        return in;
    }

    ~BankAccount() {
        cout << "Deleting account: " << accountNumber << " (" << accountHolderName << ")\n";
        accountCount--;
    }
};

int BankAccount::nextID = 1001;
int BankAccount::accountCount = 0;


int main() {
    // BankAccount acc0();
    BankAccount acc1("Ahmed", 500);
    BankAccount acc2("Ali", 1000);

    acc1.deposit(200).withdraw(150);
    acc2.withdraw(500);

    cout << acc1 << endl;
    cout << acc2 << endl;

    // BankAccount acc3 = acc1;
    // cout << acc3 << endl;

    cout << "--- Move constructor ---"<<endl;
    BankAccount acc4 = move(acc2);
    cout << acc4 << endl;

    cout << "--- Move assignment ---"<<endl;
    BankAccount acc5("TempName");
    acc5 = move(acc1);
    cout << acc5 << endl;

    BankAccount::showCounter();

    cout << "--- Cin Cout OP >> <<  ---"<<endl;
    BankAccount acc6("TempName");
    cin >> acc6;
    cout << acc6 << endl;


    BankAccount::showCounter();

    return 0;
}

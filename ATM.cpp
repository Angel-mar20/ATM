#include <iostream>
#include <string>

class ATM
{
private:
    std::string pin;
    double balance;

public:
    ATM(std::string initialPin, double initialBalance) : pin(initialPin), balance(initialBalance) {}

    void changePin(std::string newPin)
    {
        pin = newPin;
        std::cout << "PIN changed successfully." << std::endl;
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            std::cout << "Insufficient balance." << std::endl;
        }
        else
        {
            balance -= amount;
            std::cout << "Withdrawal successful. New balance: $" << balance << std::endl;
        }
    }

    void checkBalance()
    {
        std::cout << "Current balance: $" << balance << std::endl;
    }

    bool validatePin(std::string inputPin)
    {
        return pin == inputPin;
    }
};

int main()
{
    ATM atm("1234", 1000.0);
    std::string inputPin;
    int choice;
    double amount;

    std::cout << "Enter your PIN: ";
    std::cin >> inputPin;
    
    if (!atm.validatePin(inputPin))
    {
        std::cout << "Invalid PIN." << std::endl;
        return 0;
    }

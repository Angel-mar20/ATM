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
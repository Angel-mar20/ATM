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

    do
    {
        std::cout << "\n1. Withdraw\n2. Check Balance\n3. Change PIN\n4. Exit\nChoose an option: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter amount to withdraw: ";
            std::cin >> amount;
            atm.withdraw(amount);
            break;
        case 2:
            atm.checkBalance();
            break;
        case 3:
        {
            std::string newPin;
            std::cout << "Enter new PIN: ";
            std::cin >> newPin;
            atm.changePin(newPin);
            break;
        }
        case 4:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}

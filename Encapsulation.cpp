#include <iostream>

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double t_amount) 
    {
        if (balance > t_amount)
        {
            balance -= t_amount;

            std::cout << "Withdrawal successful. New balance: $" << balance << std::endl;
        }
        else
        {
            std::cout << "Insufficient funds for withdrawal." << std::endl;
        }
    }
};

class Thermostat {
private:
    double currentTemperature;

public:
    Thermostat(double temperature) : currentTemperature(temperature) {}

    double getCurrentTemperature() const {
        return currentTemperature;
    }
};

class HeatingSystem {
public:
    void checkIfHitTargetTemp(const Thermostat t_thermostat)
    {
        if (t_thermostat.getCurrentTemperature() < TARGET_TEMP) 
        {
            turnOn();
        }
        else
        {
            turnOff();
        }
    }

private:
    const float TARGET_TEMP = 20.0f;

    void turnOn() {
        std::cout << "Heating system turned on." << std::endl;
    }

    void turnOff() {
        std::cout << "Heating system turned off." << std::endl;
    }
};


#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    bool isAvailable;

public:
    Book(const std::string& title) : title(title), isAvailable(true) {}

    bool checkAvailability() const {
        return isAvailable;
    }

    void borrowBook() 
    {
        if (isAvailable)
        {
            isAvailable = false;
            std::cout << "Book borrowed successfully." << std::endl;
        }
        else
        {
            std::cout << "Book is not available for borrowing." << std::endl;
        }
    }

    void returnBook() 
    {
        isAvailable = true;
    }
};

class Library {
public:
    void processBookBorrowing(Book& book) 
    {
        book.borrowBook();
    }
};

class Player {
private:
    int health;
    int ammo;

public:
    Player() : health(100), ammo(10) {}

    int getHealth() const {
        return health;
    }

    int getAmmo() const {
        return ammo;
    }

    void takeDamage(int damage) {
        health -= damage;
    }

    void useAmmo() {
        ammo--;
    }
};

class Game {
public:
    void enemyAttack(Player& player) {
        if (player.getHealth() > 0 && player.getAmmo() > 0) {
            player.takeDamage(10);
            player.useAmmo();
            std::cout << "Player attacked and used ammo." << std::endl;
        }
        else {
            std::cout << "Player can't respond to attack." << std::endl;
        }
    }
};


int main() {
    //////////////////////////////////////////////////////////////////
    // Exercise 1
    //////////////////////////////////////////////////////////////////
    BankAccount account(1000.0);

    account.withdraw(500);

    //////////////////////////////////////////////////////////////////
    // Exercise 2
    //////////////////////////////////////////////////////////////////

    Thermostat thermostat(18.5);
    HeatingSystem heating;

    heating.checkIfHitTargetTemp(thermostat);
    
    //////////////////////////////////////////////////////////////////
    // Exercise 3
    //////////////////////////////////////////////////////////////////

    Book myBook("1984");
    Library library;

    library.processBookBorrowing(myBook);  // First borrow should succeed
    library.processBookBorrowing(myBook);  // Second attempt should show not available

    //////////////////////////////////////////////////////////////////
    // Exercise 4
    //////////////////////////////////////////////////////////////////
    Player player;
    Game game;

    game.enemyAttack(player); // Player can respond to attack

    return 0;
}

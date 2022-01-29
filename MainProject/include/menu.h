#ifndef MAINPROJECT_MENU_H
#define MAINPROJECT_MENU_H

#include "account.h"
#include "savings.h"
#include "currency.h"
#include "normal.h"


class Menu {
private:
    /// argument to call the program
    std::string argument;
public:
    /// constructor assigning help to argument
    Menu();

    /// assigning argv to argument
    /// \param argv - argument of program
    void getArgument(std::string argv);

    /// checking argument
    /// \return different value to every program argment
    int checking();

    /// menu of logged user
    /// \param acc1 - normal account
    /// \param acc2 - savings account
    /// \param acc3 - currency account
    /// \param logged - user
    void logged(Account *acc1, Savings *acc2, Currency *acc3, User *logged);

    /// checking if msg has letter
    /// \tparam msg - value to check
    template<typename T>
    void noLetter(T msg);

    /// showing menu
    void text() const;

    /// creating accounts
    /// \param acc1 - normal account
    /// \param acc2 - savings account
    /// \param acc3 - currency account
    void creating(Account *acc1, Savings *acc2, Currency *acc3);

    /// deposit money to accounts
    /// \param acc1 - normal account
    /// \param acc2 - savings account
    /// \param acc3 - currency account
    void deposit(Account *acc1, Savings *acc2, Currency *acc3);

    /// withdraw money form account
    /// \param acc1 - normal account
    /// \param acc3 - currency account
    void withdraw(Account *acc1, Currency *acc3);

    /// transfer money to different user
    /// \param acc1 - normal account
    void transfer(Account *acc1);

    /// exchanging money from currency account to normal or savings
    /// \param acc1 - normal account
    /// \param acc2 - savings account
    /// \param acc3 - currency account
    void cantor(Account *acc1, Savings *acc2, Currency *acc3);

    /// showing balance of accounts
    /// \param acc1 - normal account
    /// \param acc2 - savings account
    /// \param acc3 - currency account
    void showBalance(Account *acc1, Savings *acc2, Currency *acc3);

    /// closing accounts
    /// \param acc1 - normal account
    /// \param acc2 - savings account
    /// \param acc3 - currency account
    void closeBill(Account *acc1, Savings *acc2, Currency *acc3);

    /// default destructor
    ~Menu() noexcept = default;
};

#endif //MAINPROJECT_MENU_H

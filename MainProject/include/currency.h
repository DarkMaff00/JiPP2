#ifndef MAINPROJECT_CURRENCY_H
#define MAINPROJECT_CURRENCY_H

#include "account.h"
#include "savings.h"


class Currency : public Account {
private:
    /// shortcut of currency
    std::string sc;
public:
    /// constructor assigning values from user
    /// \param logged - user
    Currency(User logged);

    /// creating currency account
    void create();

    ///
    /// \return shortcut of currency
    std::string getSC();

    ///
    /// \param amount - amount of money to exchange
    /// \return amount after exchanging by rate of currency
    double transfer(double amount);

    /// add money to balance
    void addMoney();

    /// subtract money from balance
    void subMoney();

    /// transfers money from currency account to normal or saving
    /// \param acc1 - normal account
    /// \param acc2 - saving account
    void cantor(Account *acc1, Savings *acc2);

    /// default destructor
    ~Currency() noexcept = default;
};

#endif //MAINPROJECT_CURRENCY_H

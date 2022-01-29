#ifndef MAINPROJECT_SAVINGS_H
#define MAINPROJECT_SAVINGS_H

#include "account.h"
#include "user.h"


class Savings : public Account {
private:
    /// ratio of  the savings account
    double ratio;
public:
    /// constructor assigning values from user
    /// \param logged - user
    Savings(User logged);

    /// creating normal account
    void create();

    /// counting balance to add by multiplying by ratio
    /// \param amount - amount to add
    void addBalance(double amount);

    /// default constructor
    ~Savings() noexcept = default;
};

#endif //MAINPROJECT_SAVINGS_H

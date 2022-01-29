#ifndef MAINPROJECT_NORMAL_H
#define MAINPROJECT_NORMAL_H

#include "account.h"

class Normal : public Account {
public:
    /// constructor assigning values from user
    /// \param logged - user
    Normal(User logged);

    /// creating normal account
    void create();

    ///default destructor
    ~Normal() noexcept = default;
};

#endif //MAINPROJECT_NORMAL_H

#ifndef MAINPROJECT_ACCOUNT_H
#define MAINPROJECT_ACCOUNT_H

#include "user.h"

class Account {
protected:
    /// balance of account
    double balance;
    /// owner of account
    int owner;
    /// status of account
    bool status;
public:
    ///default constructor
    Account();

    /// constructor
    /// \param logged - user
    Account(User logged);

    ///default destructor
    ~Account() noexcept = default;

    /// creating account of given type
    virtual void create() = 0;

    /// updating data in database
    /// \param index - column in database
    /// \param data - data to change
    void update_base(int index, int data);

    /// updating data in database
    /// \param index - column in database
    /// \param data - data to change
    void update_base(int index, double data);

    /// updating data in database
    /// \param index - column in database
    /// \param data - data to change
    void update_base(int index, std::string data);

    /// transfer money to different user
    /// \param transferTo - account of that user
    virtual void transfer(Account *transferTo);

    /// checking if account exist
    int check();

    /// setting balance and status
    /// \param change - set status
    /// \param data - set balance
    void setter(int change, double data);

    /// returning balance
    /// \return balance
    double getBalance();

    /// adding money to balance
    /// \param money amount of money
    void addBalance(double money);

    /// subtracting money form account
    /// \param money amount of money
    void subBalance(double money);

    /// saving balance in database
    /// \param index - column to change
    void addMoney(int index);

    /// saving balance in database
    /// \param index - column to change
    void subMoney(int index);

    /// checking for errors in given amount of money
    /// \tparam T - type of data
    /// \param money - data to check
    template<typename T>
    void check_for_error(T money){
        try {
            if (std::cin.fail()) {
                throw 0;
            }
            if (money < 0) {
                throw 0;
            }
            if(money > std::numeric_limits<T> ::max()){
                throw std::invalid_argument("Argument jest zbyt duży");
            }
        }
        catch (int data){
            std::cin.clear();
            std::cin.ignore(256, '\n');
            money = data;
        }
        catch (std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
        }
    }

    /// adding money to different account
    /// \param rhs - amount of money
    /// \return - pointer to account
    Account &operator+(const double &rhs) {
        this->balance += rhs;
        return *this;
    }
};

#endif //MAINPROJECT_ACCOUNT_H

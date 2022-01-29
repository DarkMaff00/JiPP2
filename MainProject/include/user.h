#ifndef MAINPROJECT_USER_H
#define MAINPROJECT_USER_H


class User {
private:
    /// password of user
    std::string password;
    /// login of user
    std::string login;
public:
    /// id of user
    int userID;
    /// 0 - normal account dont exist; 1 - normal account exist
    bool normalAcc;
    /// 0 - saving account dont exist; 1 - saving account exist
    bool saving;
    /// 0 - currency account dont exist; 1 - currency account exist
    bool currency;
    /// keeps balance of every account of the user
    double balance[3];
    /// shortcut of currency
    std::string currSC;
public:
    /// default constructor
    User();

    /// comparing password and login, if everything is correct assigns data to variables
    void log_in();

    /// creating user
    void create_user();

    /// showing data about user
    void show_user();

    /// saving data of new created user to database
    void save_in_database();

    /// checking if user of name word exist in database and if yes assigns them to variables
    /// \param word - name of user
    /// \return 0 - if not exist; 1 - if exist
    int compare_with_data(std::string word);

    /// clearing row after deleted user
    void clear_file();

    /// deleting user from database
    void delete_user();

    /// checking if user with id is in the database
    /// \param id - id of user
    /// \return 0 if not exist; 1 if exist
    int checkID(int id);

    /// default destructor
    ~User() noexcept = default;
};

#endif //MAINPROJECT_USER_H

#include<iostream>
#include "../../domain/repository/AuthRepository.h"
using namespace std;

AuthRepository::AuthRepository() {
    initialize();
}

void AuthRepository::initialize() {
    const User admin(lastId++, "System", "Admin", "admin@site.com", 38,
                     "admin", "123456", Role::ADMIN);
    const User user(lastId++, "Ali", "Mansour", "ali@site.com", 38,
                    "ali", "123456", Role::USER);
    users.insertFirst(admin.id, admin);
    users.orderInsert(user.id, user);
}

void AuthRepository::signUp(const string &firstName, const string &lastName, const string &email, short age,
                            const string &username, const string &password, bool &result, User &currentUser) {
    const User user(lastId++, firstName, lastName, email, age, username, password);
    users.orderInsert(user.id, user);
    result = true;
    currentUser = user;
}

void AuthRepository::signIn(const string &username, const string &password, bool &result, User &user) {
    users.toFirst();
    while (!users.cursorIsEmpty()) {
        User currentUser;
        users.retrieveData(currentUser);
        if (currentUser.username == username && currentUser.password == password) {
            result = true;
            user = currentUser;
            break;
        }
        users.advance();
    }
}

#include "../../domain/repository/AuthRepository.h"

AuthRepository *AuthRepository::instance = nullptr;

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
                            const string &username, const string &password, bool &result) {
    const User user(lastId++, firstName, lastName, email, age, username, password);
    users.orderInsert(user.id, user);
    result = true;
}

void AuthRepository::signIn(const string &username, const string &password, bool &result) {
    users.toFirst();
    while (!users.cursorIsEmpty()) {
        User user;
        users.retrieveData(user);
        if (user.username == username && user.password == password) {
            result = true;
            currentUser = new User(user);
            break;
        }
        users.advance();
    }
}

void AuthRepository::signOut() {
    currentUser = nullptr;
    delete currentUser;
}

User *AuthRepository::getCurrentUer() {
    return currentUser;
}

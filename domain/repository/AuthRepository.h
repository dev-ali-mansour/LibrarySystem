#ifndef AUTH_REPOSITORY_H
#define AUTH_REPOSITORY_H

#include<iostream>
#include "../../data/ds/linked_list/List.h"
#include "../model/User.cpp"

using namespace std;

class AuthRepository {
    static AuthRepository *instance;
    List<long, User> users;
    long lastId{1};
    User *currentUser;

    AuthRepository();

    void initialize();

public:
    static AuthRepository *getInstance() {
        if (instance == nullptr) {
            instance = new AuthRepository();
        }
        return instance;
    }

    void signUp(const string &firstName, const string &lastName, const string &email, short age,
                const string &username, const string &password, bool &result);

    void signIn(const string &username, const string &password, bool &result);

    void signOut();

    User * getCurrentUer();
};

#endif //AUTH_REPOSITORY_H

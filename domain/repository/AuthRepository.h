#ifndef AUTH_REPOSITORY_H
#define AUTH_REPOSITORY_H

#include<iostream>
#include "../../data/ds/linked_list/List.h"
#include "../model/User.cpp"

using namespace std;

class AuthRepository {
    List<long, User> users;
    long lastId{1};

    void initialize();

public:
    AuthRepository();

    void signUp(const string &firstName, const string &lastName, const string &email, short age,
                const string &username, const string &password, bool &result, User &currentUser);

    void signIn(const string &username, const string &password, bool &result, User &user);
};

#endif //AUTH_REPOSITORY_H

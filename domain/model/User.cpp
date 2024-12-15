#include<iostream>
#include "Role.cpp"
using namespace std;

struct User {
    long id;
    string firstName;
    string lastName;
    string email;
    short age;
    string username;
    string password;
    Role role;

    // Default constructor
    User() = default;

    User(
        const long id,
        const string &first_name,
        const string &last_name,
        const string &email,
        const short age,
        const string &username,
        const string &password,
        const Role role = Role::USER)
        : id(id),
          firstName(first_name),
          lastName(last_name),
          email(email),
          age(age),
          username(username),
          password(password),
          role(role) {
    }
};

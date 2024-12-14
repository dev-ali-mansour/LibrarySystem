#include <iostream>
#include "../../repository/AuthRepository.h"

using namespace std;

class SignUpUseCase {
    AuthRepository repo;

public:
    explicit SignUpUseCase(const AuthRepository &repository): repo(repository) {
    }

    void execute(const string &firstName, const string &lastName, const string &email, const short age,
                 const string &username, const string &password, bool &result, User &currentUser) {
        repo.signUp(firstName, lastName, email, age, username, password, result, currentUser);
    }
};

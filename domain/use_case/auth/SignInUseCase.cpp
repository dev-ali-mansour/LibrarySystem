#include <iostream>
#include "../../repository/AuthRepository.h"

using namespace std;

class SignInUseCase {
    AuthRepository repo;

public:
    explicit SignInUseCase(AuthRepository &repository) : repo(repository) {
    }

    void execute(const string &username, const string &password, bool &result, User &user) {
        repo.signIn(username, password, result, user);
    }
};

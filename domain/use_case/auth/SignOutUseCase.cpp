#include "../../repository/AuthRepository.h"

class SignOutUseCase {
    AuthRepository *repo;

public:
    explicit SignOutUseCase(AuthRepository *repository) : repo(repository) {
    }

    void execute() {
        repo->signOut();
    }
};

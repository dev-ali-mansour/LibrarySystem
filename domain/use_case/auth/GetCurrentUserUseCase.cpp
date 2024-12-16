#include "../../repository/AuthRepository.h"

class GetCurrentUserUseCase {
    AuthRepository *repo;

public:
    explicit GetCurrentUserUseCase(AuthRepository *repository) : repo(repository) {
    }

    User *execute() {
        return repo->getCurrentUer();
    }
};

#include "../../repository/BookRepository.h"

class GetPendingRequestsUseCase {
    BookRepository *repo;

public:
    explicit GetPendingRequestsUseCase(BookRepository *repository) : repo(repository) {
    }

    vector<BorrowRequest> execute() {
        return repo->getPendingRequests();
    }
};

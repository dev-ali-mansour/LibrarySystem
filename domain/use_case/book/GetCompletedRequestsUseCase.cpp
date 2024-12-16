#include "../../repository/BookRepository.h"

class GetCompletedRequestsUseCase {
    BookRepository *repo;

public:
    explicit GetCompletedRequestsUseCase(BookRepository *repository) : repo(repository) {
    }

    vector<BorrowRequest> execute() {
        return repo->getCompletedRequests();
    }
};

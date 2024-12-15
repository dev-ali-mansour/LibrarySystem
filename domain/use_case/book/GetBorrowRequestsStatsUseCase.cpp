#include "../../repository/BookRepository.h"

class GetBorrowRequestsStatsUseCase {
    BookRepository *repo;

public:
    explicit GetBorrowRequestsStatsUseCase(BookRepository *repository) : repo(repository) {
    }

    void execute(int &pendingCount, int &completedCount) const {
        repo->getBorrowRequestsStats(pendingCount, completedCount);
    }
};

#include "../../repository/BookRepository.h"

class ProceedBorrowRequestUseCase {
    BookRepository *repo;

public:
    explicit ProceedBorrowRequestUseCase(BookRepository *repository) : repo(repository) {
    }

    void execute() const {
        repo->proceedBorrowRequest();
    }
};

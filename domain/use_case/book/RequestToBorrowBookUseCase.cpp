#include "../../repository/BookRepository.h"

class AddNewBorrowRequestUseCase {
    BookRepository *repo;

public:
    explicit AddNewBorrowRequestUseCase(BookRepository *repository) : repo(repository) {
    }

    void execute(const string &isbn, const long &user_id, const string &created) const {
        repo->requestToBorrowBook(isbn, user_id, created);
    }
};

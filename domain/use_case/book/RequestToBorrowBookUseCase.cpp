#include "../../repository/BookRepository.h"

class RequestToBorrowBookUseCase {
    BookRepository *repo;

public:
    explicit RequestToBorrowBookUseCase(BookRepository *repository) : repo(repository) {
    }

    void execute(const string &isbn, const long &user_id) const {
        repo->requestToBorrowBook(isbn, user_id);
    }
};

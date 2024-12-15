#include "../../repository/BookRepository.h"

class RemoveBookUseCase {
    BookRepository repo;

public:
    explicit RemoveBookUseCase(BookRepository &repository) : repo(repository) {
    }

    bool execute(const string &isbn) {
        return repo.removeBook(isbn);
    }
};

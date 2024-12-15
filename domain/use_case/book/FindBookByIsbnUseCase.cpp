#include "../../repository/BookRepository.h"

class FindBookByIsbnUseCase {
    BookRepository repo;

public:
    explicit FindBookByIsbnUseCase(BookRepository &repository) : repo(repository) {
    }

    vector<Book> execute(const string &isbn) {
        return repo.findBookByIsbn(isbn);
    }
};

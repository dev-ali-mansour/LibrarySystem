#include "../../repository/BookRepository.h"

class ListBooksUseCase {
    BookRepository *repo;

public:
    explicit ListBooksUseCase(BookRepository *repository) : repo(repository) {
    }

    vector<Book> execute() {
        return repo->listBooks();
    }
};

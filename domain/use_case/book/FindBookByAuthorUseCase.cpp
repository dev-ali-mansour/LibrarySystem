#include "../../repository/BookRepository.h"

class FindBookByAuthorUseCase {
    BookRepository *repo;

public:
    explicit FindBookByAuthorUseCase(BookRepository *repository) : repo(repository) {
    }

    vector<Book> execute(const string &author) {
        return repo->findBookByAuthor(author);
    }
};

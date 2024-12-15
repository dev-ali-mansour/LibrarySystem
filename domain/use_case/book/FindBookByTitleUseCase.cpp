#include "../../repository/BookRepository.h"

class FindBookByTitleUseCase {
    BookRepository *repo;

public:
    explicit FindBookByTitleUseCase(BookRepository *repository) : repo(repository) {
    }

    vector<Book> execute(const string &title) {
        return repo->findBookByTitle(title);
    }
};

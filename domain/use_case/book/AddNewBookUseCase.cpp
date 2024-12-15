#include "../../repository/BookRepository.h"

class AddNewBookUseCase {
    BookRepository *repo;

public:
    explicit AddNewBookUseCase(BookRepository *repository) : repo(repository) {
    }

    bool execute(
            const string &isbn,
            const string &title,
            const string &author,
            const short &version,
            const int &publishingYear,
            const int &pages) {
        return repo->addNewBook(isbn, title, author, version, publishingYear, pages);
    }
};

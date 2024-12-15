
#include "../../domain/repository/BookRepository.h"

void BookRepository::initialize() {
    const Book book1("9780134383583", "Discovering Modern C++", "Peter Gottschling", 1, 2015, 480);
    const Book book2("9781507707616", "C# Programming for Beginners", "Troy Dimes", 1, 2015, 106);
    const Book book3("9781517080402", "JAVA Programming for Beginners", "Tim Warren", 1, 2002, 68);
    books.insertFirst(book1.isbn, book1);
    books.orderInsert(book2.isbn, book2);
    books.orderInsert(book3.isbn, book3);
}

BookRepository::BookRepository() {
    initialize();
}

bool BookRepository::addNewBook(
        const string &isbn,
        const string &title,
        const string &author,
        const short &version,
        const int &publishingYear,
        const int &pages) {
    //Todo(Not Implemented Yet)
    return false;
}

bool BookRepository::removeBook(const string &isbn) {
    //Todo(Not Implemented Yet)
    return false;
}

vector<Book> BookRepository::findBookByIsbn(const string &isbn) {
    vector<Book> list;
    //Todo(Not Implemented Yet)
    return list;
}

vector<Book> BookRepository::findBookByAuthor(const string &author) {
    vector<Book> list;
    //Todo(Not Implemented Yet)
    return list;
}

vector<Book> BookRepository::listBooks() {
    vector<Book> list;
    if (books.listIsEmpty()) {
        cerr << "No books found!\n";
        return list;
    }
    Book book;
    books.toFirst();
    while (!books.cursorIsEmpty()) {
        books.retrieveData(book);
        list.push_back(book);
        books.advance();
    }
    return list;
}

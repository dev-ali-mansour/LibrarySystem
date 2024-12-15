#include "../../domain/repository/BookRepository.h"

BookRepository* BookRepository::instance = nullptr;

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

void BookRepository::undo() {
    if (actions.stackIsEmpty()) {
        cerr << "There is no more actions to undo!\n";
        return;
    }
    BookAction action;
    actions.pop(action);
    bool result = false;
    if (action.type == ActionType::ADD) {
        result = removeBook(action.book.isbn);
        cout << "Removing The book " << action.book.title << endl;
    } else if (action.type == ActionType::REMOVE) {
        result = addNewBook(
                action.book.isbn,
                action.book.title,
                action.book.author,
                action.book.version,
                action.book.publishingYear,
                action.book.pages);
        cout << "Re-adding The book " << action.book.title << endl;
    }
    if (result)cout << "Operation done successfully!\n";
    else cerr << "\nFailed to do operation!\n";
}

vector<Book> BookRepository::findBookByIsbn(const string &isbn) {
    vector<Book> list;
    //Todo(Not Implemented Yet)
    return list;
}

vector<Book> BookRepository::findBookByTitle(const string &title) {
    vector<Book> list;
    if (books.listIsEmpty()) {
        cerr << "\nNo books found!\n";
        return list;
    }
    Book book;
    books.toFirst();
    while (!books.cursorIsEmpty()) {
        books.retrieveData(book);
        // Check if book title contains the title parameter
        if (StringSearch::caseInsensitiveSubstringSearch(book.title, title))
            list.push_back(book);
        books.advance();
    }
    if (list.empty())cerr << "\nNo books matches your criteria (" << title << ")\n";
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
        cerr << "\nNo books found!\n";
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

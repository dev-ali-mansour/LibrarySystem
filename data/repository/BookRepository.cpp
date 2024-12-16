#include "../../domain/repository/BookRepository.h"
#include "../../data/util/Utilities.cpp"
#include <chrono>

using namespace chrono;

BookRepository *BookRepository::instance = nullptr;

void BookRepository::initialize() {
    const Book book1("9780134383583", "Discovering Modern C++", "Peter Gottschling", 1, 2015, 480);
    const Book book2("9781507707616", "C# Programming for Beginners", "Troy Dimes", 1, 2015, 106);
    const Book book3("9781517080402", "JAVA Programming for Beginners", "Tim Warren", 1, 2002, 68);
    books.insertFirst(book1.isbn, book1);
    books.orderInsert(book2.isbn, book2);
    books.orderInsert(book3.isbn, book3);
    const BorrowRequest request("9780134383583", 2, Utilities::getTime());
    pendingRequests.enqueue(request);
    const BorrowRequest request2("9781507707616", 2, Utilities::getTime());
    pendingRequests.enqueue(request2);
    const BorrowRequest request3("9781517080402", 2, Utilities::getTime());
    pendingRequests.enqueue(request3);
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
    const Book book1(isbn, title, author, version,publishingYear,pages );
    books.orderInsert(book1.isbn,book1);
    return true;
}

bool BookRepository::removeBook(const string &isbn) {
    books.toFirst();
    Book book;

    while (!books.cursorIsEmpty()) {
    books.retrieveData(book);
        if (book.isbn==isbn) {
            books.deleteNode();
            return true;
        }
        books.advance();
    }
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
        if (Utilities::caseInsensitiveSubstringSearch(book.title, title))
            list.push_back(book);
        books.advance();
    }
    if (list.empty())cerr << "\nNo books matches your criteria (" << title << ")\n";
    return list;
}

vector<Book> BookRepository::findBookByAuthor(const string &author) {
    vector<Book> list;
    if (books.listIsEmpty()) {
        cerr << "\nNo books found!\n";
        return list;
    }
    Book book;
    books.toFirst();
    while (!books.listIsEmpty()){
        books.retrieveData(book);
        //check if book author contains the author parameter
        if(Utilities::caseInsensitiveSubstringSearch(book.author,author)){

            list.push_back(book);
        }
        books.advance();
    }
    if (list.empty()) cerr<<"\nNo books matches your criteria (" << author << ")\n";
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

void BookRepository::requestToBorrowBook(
    const string &isbn,
    const long &user_id,
    const string &created) {
    BorrowRequest request(isbn, user_id, created);

}

void BookRepository::proceedBorrowRequest() {
    //Todo(Not Implemented Yet)
}

void BookRepository::getBorrowRequestsStats(int &pendingCount, int &completedCount) const {
    //Todo(Not Implemented Yet)
}

vector<BorrowRequest> BookRepository::getPendingRequests() {
    vector<BorrowRequest> list;
    //Todo(Not Implemented Yet)
    return list;
}

vector<BorrowRequest> BookRepository::getCompletedRequests() {
    vector<BorrowRequest> list;
    //Todo(Not Implemented Yet)
    return list;
}

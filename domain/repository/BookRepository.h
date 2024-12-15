#ifndef LIBRARYSYSTEM_BOOK_REPOSITORY_H
#define LIBRARYSYSTEM_BOOK_REPOSITORY_H

#include<iostream>
#include <vector>
#include "../../data/ds/linked_list/List.h"
#include "../../data/ds/stack/StackL.cpp"
#include "../../data/ds/queue/QueueL.cpp"
#include "../model/BookAction.cpp"
#include "../model/BorrowRequest.cpp"

class BookRepository {
    static BookRepository *instance;

    List<string, Book> books;
    StackL<BookAction> actions;
    QueueL<BorrowRequest> pendingRequests, completedRequests;

    void initialize();

    BookRepository();

public:
    static BookRepository *getInstance() {
        if (instance == nullptr) {
            instance = new BookRepository();
        }
        return instance;
    }

    bool addNewBook(
        const string &isbn,
        const string &title,
        const string &author,
        const short &version,
        const int &publishingYear,
        const int &pages);

    bool removeBook(const string &isbn);

    void undo();

    vector<Book> findBookByIsbn(const string &isbn);

    vector<Book> findBookByTitle(const string &title);

    vector<Book> findBookByAuthor(const string &author);

    vector<Book> listBooks();

    void requestToBorrowBook(const string &isbn, const long &user_id, const string &created);

    void proceedBorrowRequest();

    void getBorrowRequestsStats(int &pendingCount, int &completedCount) const;

    vector<BorrowRequest> getPendingRequests();

    vector<BorrowRequest> getCompletedRequests();
};

#endif //LIBRARYSYSTEM_BOOK_REPOSITORY_H

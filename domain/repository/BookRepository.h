#ifndef LIBRARYSYSTEM_BOOK_REPOSITORY_H
#define LIBRARYSYSTEM_BOOK_REPOSITORY_H

#include<iostream>
#include <vector>
#include "../../data/ds/linked_list/List.h"
#include "../../data/ds/stack/StackL.cpp"
#include "../../data/ds/queue/QueueL.cpp"
#include "../../data/util/StringSearch.cpp"
#include "../model/BookAction.cpp"

class BookRepository {
    static BookRepository *instance;

    List<string, Book> books;
    StackL<BookAction> actions;

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
};

#endif //LIBRARYSYSTEM_BOOK_REPOSITORY_H

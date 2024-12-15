#ifndef LIBRARYSYSTEM_BOOK_REPOSITORY_H
#define LIBRARYSYSTEM_BOOK_REPOSITORY_H

#include<iostream>
#include <vector>
#include "../../data/ds/linked_list/List.h"
#include "../model/Book.cpp"

class BookRepository {
    List<string, Book> books;
    long lastId{1};

    void initialize();

public:
    BookRepository();

    bool addNewBook(
            const string &isbn,
            const string &title,
            const string &author,
            const short &version,
            const int &publishingYear,
            const int &pages);

    bool removeBook(const string &isbn);

    vector<Book> findBookByIsbn(const string &isbn);

    vector<Book> findBookByAuthor(const string &author);

    vector<Book> listBooks();
};

#endif //LIBRARYSYSTEM_BOOK_REPOSITORY_H

#include <iostream>

using namespace std;

struct Book {
    string isbn;
    string title;
    string author;
    short version;
    int publishingYear;
    int pages;
    int copiesAvailable;

    Book() = default;

    Book(const string &isbn,
         const string &title,
         const string &author,
         const short &version,
         const int &publishing_year,
         const int &pages,const int &copiesAvailable=1
    ) : isbn(isbn),
        title(title),
        author(author),
        version(version),
        publishingYear(publishing_year),
        pages(pages),
        copiesAvailable(copiesAvailable){
    }
};

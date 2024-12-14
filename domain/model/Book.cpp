#include <iostream>

using namespace std;

struct Book {
    string isbn;
    string title;
    string author;
    short version;
    int publishingYear;

    Book(const string &isbn,
         const string &title,
         const string &author,
         const short version,
         const int publishing_year)
        : isbn(isbn),
          title(title),
          author(author),
          version(version),
          publishingYear(publishing_year) {
    }
};

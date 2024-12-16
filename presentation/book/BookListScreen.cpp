#include <limits>
#include "BookListScreen.h"
#include "../main/MainScreen.h"

ListBooksUseCase listBooksUseCase(BookRepository::getInstance());
FindBookByIsbnUseCase findBookByIsbnUseCase(BookRepository::getInstance());
FindBookByTitleUseCase findBookByTitleUseCase(BookRepository::getInstance());
FindBookByAuthorUseCase findBookByAuthorUseCase(BookRepository::getInstance());


void showBookList() {
    cout << "#############" << endl;
    cout << "Books Screen" << endl;
    cout << "#############" << endl;
    vector<Book> books;
    bool repeat = true;
    while (repeat) {
        books.clear();
        cout << "Choose an action:" << endl;
        cout << "1) List All Books" << endl;
        cout << "2) Search By ISBN" << endl;
        cout << "3) Search By Title" << endl;
        cout << "4) Search By Author" << endl;
        short choice;
        string query;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number!" << endl;
            continue;
        }
        cin.ignore();
        switch (choice) {
            case 1:
                books = listBooksUseCase.execute();
                break;
            case 2:
                cout << "Book ISBN: ";
                getline(cin, query);
                books = findBookByIsbnUseCase.execute(query);
                break;
            case 3:
                cout << "Book Title: ";
                getline(cin, query);
                books = findBookByTitleUseCase.execute(query);
                break;
            case 4:
                cout << "Book Author: ";
                getline(cin, query);
                books = findBookByAuthorUseCase.execute(query);
                break;
            default:
                cout << "Invalid choice! try again" << endl;
                break;
        }

        cout << "Results Count: " << books.size() << endl;
        cout << "================================" << endl;
        for (const auto &book: books) {
            cout << "ISBN: " << book.isbn << endl;
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "Version: " << book.version << endl;
            cout << "Publishing Year: " << book.publishingYear << endl;
            cout << "Pages: " << book.pages << endl;
            cout << "================================" << endl;
        }

        char backChoice;
        cout << "Go back to the main menu? Y = Yes: ";
        cin >> backChoice;
        if (tolower(backChoice) == 'y') {
            repeat = false;
            showMainMenu();
        }
    }
}
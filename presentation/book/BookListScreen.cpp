#include "BookListScreen.h"
#include<string>

ListBooksUseCase listBooksUseCase(BookRepository::getInstance());
FindBookByIsbnUseCase findBookByIsbnUseCase(BookRepository::getInstance());
FindBookByTitleUseCase findBookByTitleUseCase(BookRepository::getInstance());
FindBookByAuthorUseCase findBookByAuthorUseCase(BookRepository::getInstance());
AddNewBookUseCase addNewBookUseCase(BookRepository::getInstance());
RemoveBookUseCase removeBookUseCase(BookRepository::getInstance());
UndoUseCase undoUseCase(BookRepository::getInstance());

void showBookList(const User *userPtr) {
    cout << "#############" << endl;
    cout << "Books Screen" << endl;
    cout << "#############" << endl;
    vector<Book> books;
    string isbn;
    string title;
    string author;
    short version;
    int publishingYear;
    int pages;
    int copiesAvailable;
    bool repeat = true;
    while (repeat) {
        books.clear();
        cout << "Choose an action:" << endl;
        cout << "1) List All Books" << endl;
        cout << "2) Search By ISBN" << endl;
        cout << "3) Search By Title" << endl;
        cout << "4) Search By Author" << endl;
        if (userPtr->role == Role::ADMIN) {
            cout << "5) Add New Book" << endl;
            cout << "6) Remove Book" << endl;
            cout << "7) Undo" << endl;
        }
        short choice;
        string query;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number!" << endl;
            continue;
        }

        if (userPtr->role != Role::ADMIN && (choice > 4 || choice <1)) {
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
            case 5:
                cout<<"Enter Book data to be added\n";
                cout<<"ISBN\n";
                cin>>isbn;
                cout<<"Book Title";
                cin>>title;
                cout<<"Book Author";
                cin>>author;
                cout<<"Book Version";
                cin>>version;
                cout<<"Publishing Year";
                cin>>publishingYear;
                cout<<"Book Pages count";
                cin>>pages;
                cout<<"How many copies of the book you want to add";
                cin>>copiesAvailable;
                addNewBookUseCase.execute(
                        isbn,
                        title,
                        author,
                        version,
                        publishingYear,
                        pages,
                        copiesAvailable);
                break;
            case 6:
                removeBookUseCase.execute(isbn);
                break;
            case 7:
                undoUseCase.execute();
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

#include <limits>
#include "MainScreen.h"
#include "../book/BookListScreen.h"
#include "../book/BorrowRequestsScreen.h"

GetCurrentUserUseCase getCurrentUserUseCase(AuthRepository::getInstance());
SignOutUseCase signOutUseCase(AuthRepository::getInstance());

void showMainScreen() {
    User *userPtr = getCurrentUserUseCase.execute();
    if (userPtr == nullptr) showAuthMenu();
    else showMainMenu();
}

void showMainMenu() {
    cout << "###########" << endl;
    cout << "Main Screen" << endl;
    cout << "###########" << endl;
    const User *userPtr = getCurrentUserUseCase.execute();
    const string fullName = userPtr->firstName + " " + userPtr->lastName;
    cout << "Welcome back " << fullName << endl;
    cout << "Choose an action:" << endl;
    cout << "1) Books" << endl;
    cout << "2) Borrow Requests" << endl;
    cout << "3) Logout" << endl;
    bool repeat = true;
    while (repeat) {
        short choice;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number!" << endl;
            continue;
        }
        switch (choice) {
            case 1:
                showBookList(userPtr);
                repeat = false;
                break;
            case 2:
                showBorrowRequests(userPtr);
                break;
            case 3:
                signOutUseCase.execute();
                showMainScreen();
                repeat = false;
                break;

            default:
                cout << "Invalid choice! try again" << endl;
                break;
        }
    }
}

void showAuthMenu() {
    bool repeat = true;
    while (repeat) {
        cout << "Choose an action" << endl;
        cout << "1) Sign up" << endl;
        cout << "2) Sign in" << endl;
        cout << "3) Exit" << endl;
        short choice;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number!" << endl;
            continue;
        }
        switch (choice) {
            case 1:
                signUp();
                repeat = false;
                break;
            case 2:
                signIn();
                repeat = false;
                break;
            case 3:
                cout << "System Exit, Bye!" << endl;
                exit(0);
            default:
                cout << "Invalid choice! try again" << endl;
                break;
        }
    }
}

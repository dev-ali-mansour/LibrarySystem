#include <limits>
#include "MainScreen.h"
#include "../book/BookListScreen.h"

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
    User *userPtr = getCurrentUserUseCase.execute();
    string fullName = userPtr->firstName + " " + userPtr->lastName;
    cout << "Welcome back " << fullName << endl;
    cout << "Choose an action:" << endl;
    cout << "1) Show Book List" << endl;
    cout << "2) Logout" << endl;
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
                showBookList();
                repeat = false;
                break;

            case 2:
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
#include "SignInScreen.h"
#include "../main/MainScreen.h"

void signIn() {
    SignInUseCase signInUseCase(AuthRepository::getInstance());

    cout << "#############" << endl;
    cout << "Sign in Screen" << endl;
    cout << "#############" << endl;
    bool repeat = true;
    string username, password;

    while (repeat) {
        while (true) {
            cout << "Username: ";
            cin >> username;
            if (username.empty()) cout << "Please enter your username!" << endl;
            else break;
        }
        while (true) {
            cout << "Password: ";
            cin >> password;
            if (password.length() < 6) cout << "Please enter at least 6 characters password!" << endl;
            else break;
        }
        bool isValid;
        signInUseCase.execute(username, password, isValid);
        if (isValid) {
            repeat = false;
            showMainMenu();
        } else {
            cout << "Invalid username or password!\n";
            cout << "Go back to the main menu? Y = Yes: ";
            char choice;
            cin >> choice;
            if (tolower(choice) == 'y') {
                repeat = false;
                showAuthMenu();
            }
        }
    }
}
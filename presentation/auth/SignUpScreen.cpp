#include <sstream>
#include "SignUpScreen.h"
#include "SigninScreen.h"

void signUp() {
    SignUpUseCase signUpUseCase(AuthRepository::getInstance());

    cout << "#############" << endl;
    cout << "Signup Screen" << endl;
    cout << "#############" << endl;
    string firstName, lastName, email, username, password;
    short age;
    bool repeat = true;

    while (repeat) {
        while (true) {
            cin.ignore();
            cout << "First Name: ";
            getline(cin, firstName);
            if (firstName.empty()) cout << "Please enter your first name!\n";
            else break;
        }
        while (true) {
            cout << "Last Name: ";
            getline(cin, lastName);
            if (lastName.empty()) cout << "Please enter your last name!\n";
            else break;
        }
        bool inValidAge = true;
        while (inValidAge) {
            cout << "Age: ";
            string input;
            getline(cin, input);
            if (input.empty()) {
                cout << "Please enter your age!\n";
                continue;
            }
            stringstream ss(input);
            if (!(ss >> age) || !(ss.eof())) {
                cout << "Please enter a valid age!\n";
                continue;
            }
            if (age < 7) cout << "Please enter a valid age!\n";
            else inValidAge = false;
        }
        while (true) {
            cout << "Email Address: ";
            getline(cin,email);
            if (email.empty()) cout << "Please enter your email address!\n";
            else break;
        }
        while (true) {
            cout << "Username: ";
            getline(cin,username);
            if (username.empty()) cout << "Please enter your username!\n";
            else break;
        }
        while (true) {
            cout << "Password: ";
            getline(cin,password);
            if (password.length() < 6) cout << "Please enter at least 6 characters password!\n";
            else break;
        }

        bool result;
        signUpUseCase.execute(firstName, lastName, email, age, username, password, result);
        if (result) {
            repeat = false;
            cout << "Your account have been created successfully! You can sign in now" << endl;
            signIn();
        } else cout << "Failed to signup your account!\n";
    }
}
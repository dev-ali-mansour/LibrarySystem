#include <iostream>
#include "../domain/use_case/auth/SignInUseCase.cpp"
#include "../domain/use_case/auth/SignUpUseCase.cpp"

int main() {
    AuthRepository authRepo;
    SignInUseCase signInUseCase(authRepo);
    SignUpUseCase signUpUseCase(authRepo);
    string username, password;
    User currentUser;
    bool isValid;
    cout << "Login Screen\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    signInUseCase.execute(username, password, isValid, currentUser);
    if (isValid)
        cout << "Welcome back " << currentUser.firstName << " " << currentUser.lastName << endl;
    else cerr << "Invalid username or password!";

    return 0;
}

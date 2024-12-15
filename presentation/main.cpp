#include <iostream>
#include <vector>
#include "../domain/use_case/auth/SignInUseCase.cpp"
#include "../domain/use_case/auth/SignUpUseCase.cpp"
#include "../domain/use_case/book/ListBooksUseCase.cpp"

int main() {
    AuthRepository authRepo;
    BookRepository bookRepo;
    SignInUseCase signInUseCase(authRepo);
    SignUpUseCase signUpUseCase(authRepo);
    ListBooksUseCase listBooksUseCase(bookRepo);
    string username, password;
    User currentUser;
    bool isValid;
    cout << "Login Screen\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    signInUseCase.execute(username, password, isValid, currentUser);
    if (isValid) {
        cout << "Welcome back " << currentUser.firstName << " " << currentUser.lastName << endl;
        cout << "Books List\n";
        vector<Book> books = listBooksUseCase.execute();
        for (const auto &book: books) {
            cout << "ISBN: " << book.isbn << ", Title: " << book.title << endl;
        }
    } else cerr << "Invalid username or password!";

    return 0;
}

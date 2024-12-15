#include <iostream>
#include <vector>
#include "../domain/use_case/auth/SignInUseCase.cpp"
#include "../domain/use_case/auth/SignUpUseCase.cpp"
#include "../domain/use_case/book/ListBooksUseCase.cpp"
#include "../domain/use_case/book/FindBookByTitleUseCase.cpp"
#include "../domain/use_case/book/GetBorrowRequestsStatsUseCase.cpp"
#include "../domain/use_case/book/ProceedBorrowRequestUseCase.cpp"

int main() {
    SignInUseCase signInUseCase(AuthRepository::getInstance());
    SignUpUseCase signUpUseCase(AuthRepository::getInstance());
    ListBooksUseCase listBooksUseCase(BookRepository::getInstance());
    FindBookByTitleUseCase findBookByTitleUseCase(BookRepository::getInstance());
    GetBorrowRequestsStatsUseCase getStatsUseCase(BookRepository::getInstance());
    ProceedBorrowRequestUseCase proceedUseCase(BookRepository::getInstance());
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

        int pendingCount, completedCount;
        getStatsUseCase.execute(pendingCount, completedCount);
        cout << "Pending Requests Count: " << pendingCount << endl;
        cout << "Completed Requests Count: " << completedCount << endl;
        proceedUseCase.execute();
        getStatsUseCase.execute(pendingCount, completedCount);
        cout << "Pending Requests Count: " << pendingCount << endl;
        cout << "Completed Requests Count: " << completedCount << endl;

        cout << endl << "Enter Book Title To Search: ";
        string title;
        cin.ignore();
        getline(cin, title);
        vector<Book> results = findBookByTitleUseCase.execute(title);
        for (const auto &book: results) {
            cout << "ISBN: " << book.isbn << ", Title: " << book.title << endl;
        }
    } else cerr << "Invalid username or password!";

    return 0;
}

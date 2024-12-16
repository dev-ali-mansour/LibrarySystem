#include "BorrowRequestsScreen.h"

GetBorrowRequestsStatsUseCase getBorrowRequestsStatsUseCase(BookRepository::getInstance());
RequestToBorrowBookUseCase requestToBorrowBookUseCase(BookRepository::getInstance());
ProceedBorrowRequestUseCase proceedBorrowRequestUseCase(BookRepository::getInstance());
GetCompletedRequestsUseCase getCompletedRequestsUseCase(BookRepository::getInstance());
GetPendingRequestsUseCase getPendingRequestsUseCase(BookRepository::getInstance());

void showBorrowRequests(const User *userPtr) {
    cout << "#######################" << endl;
    cout << "Borrow Requests Screen" << endl;
    cout << "#######################" << endl;
    vector<BorrowRequest> requests;

    bool repeat = true;
    while (repeat) {
        requests.clear();
        cout << "Choose an action:" << endl;
        cout << "1) Create Borrow Request" << endl;
        if (userPtr->role == Role::ADMIN) {
            cout << "2) Proceed Borrow Request" << endl;
            cout << "3) Get Pending Requests" << endl;
            cout << "4) Get Completed Requests" << endl;
        }
        short choice;
        string isbn;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number!" << endl;
            continue;
        }

        if (userPtr->role != Role::ADMIN && choice > 1) {
            cout << "Please enter a valid number!" << endl;
            continue;
        }
        cin.ignore();
        switch (choice) {
            case 1:
                cout << "ISBN: ";
                getline(cin, isbn);
                requestToBorrowBookUseCase.execute(isbn, userPtr->id);
                break;
            case 2:
                proceedBorrowRequestUseCase.execute();
                break;
            case 3:
                requests = getPendingRequestsUseCase.execute();
                showRequests(requests, "Pending Requests:");
                break;
            case 4:
                requests = getCompletedRequestsUseCase.execute();
                showRequests(requests, "Completed Requests:");
                break;
            default:
                cout << "Invalid choice! try again" << endl;
                break;
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

void showRequests(const vector<BorrowRequest> &requests, const string &title) {
    cout << title << endl;
    cout << "Results Count: " << requests.size() << endl;
    cout << "================================" << endl;
    for (const auto &request: requests) {
        cout << "ISBN: " << request.isbn << endl;
        cout << "User: " << request.userId << endl;
        cout << "Created: " << request.created << endl;
        cout << "================================" << endl;
    }
}

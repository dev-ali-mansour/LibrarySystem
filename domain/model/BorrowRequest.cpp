#include<iostream>

using namespace std;

struct BorrowRequest {
    string isbn;
    long userId;
    string created;

    BorrowRequest() = default;

    BorrowRequest(
        const string &isbn,
        const long &userId,
        const string created)
        : isbn(isbn),
          userId(userId),
          created(created) {
    }
};

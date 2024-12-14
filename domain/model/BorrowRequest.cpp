#include<iostream>

using namespace std;

struct BorrowRequest {
    string isbn;
    long userId;
    long created;

    BorrowRequest(
        const string &isbn,
        const long user_id,
        const long created)
        : isbn(isbn),
          userId(user_id),
          created(created) {
    }
};

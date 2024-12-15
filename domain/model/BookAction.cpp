#include "ActionType.cpp"
#include "Book.cpp"

struct BookAction {
    ActionType type;
    Book book;

    BookAction() = default;

    BookAction(ActionType type, const Book &book) : type(type), book(book) {}
};
#include "../../repository/BookRepository.h"

class UndoUseCase {
    BookRepository *repo;

public:
    explicit UndoUseCase(BookRepository *repository) : repo(repository) {
    }

    void execute() {
        return repo->undo();
    }
};

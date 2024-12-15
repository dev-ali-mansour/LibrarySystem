cmake_minimum_required(VERSION 3.30)
project(LibrarySystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(LibrarySystem
        presentation/main.cpp
        data/ds/linked_list/List.h
        data/ds/linked_list/List.tpp
        data/ds/stack/StackL.h
        data/ds/stack/StackL.cpp
        data/ds/queue/QueueL.h
        data/ds/queue/QueueL.cpp
        domain/model/User.cpp
        domain/model/Book.cpp
        domain/model/BorrowRequest.cpp
        domain/model/Role.cpp
        domain/use_case/auth/SignUpUseCase.cpp
        domain/use_case/auth/SignInUseCase.cpp
        domain/use_case/book/ListBooksUseCase.cpp
        domain/use_case/book/AddNewBookUseCase.cpp
        domain/use_case/book/RemoveBookUseCase.cpp
        domain/use_case/book/FindBookByIsbnUseCase.cpp
        domain/use_case/book/FindBookByTitleUseCase.cpp
        domain/use_case/book/FindBookByAuthorUseCase.cpp
        domain/repository/AuthRepository.h
        domain/repository/BookRepository.h
        data/repository/AuthRepository.cpp
        data/repository/BookRepository.cpp
        data/util/StringSearch.cpp
)

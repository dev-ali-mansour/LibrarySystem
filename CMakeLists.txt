cmake_minimum_required(VERSION 3.30)
project(LibrarySystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(LibrarySystem
        presentation/main.cpp
        data/ds/linked_list/List.h
        data/ds/linked_list/List.cpp
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
        domain/repository/AuthRepository.h
        data/repository/AuthRepository.cpp
)

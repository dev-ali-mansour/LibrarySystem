#ifndef LIBRARYSYSTEM_BORROWREQUESTSSCREEN_H
#define LIBRARYSYSTEM_BORROWREQUESTSSCREEN_H
#include <limits>
#include "../../domain/use_case/book/GetBorrowRequestsStatsUseCase.cpp"
#include "../../domain/use_case/book/GetCompletedRequestsUseCase.cpp"
#include "../../domain/use_case/book/GetPendingRequestsUseCase.cpp"
#include "../../domain/use_case/book/ProceedBorrowRequestUseCase.cpp"
#include "../../domain/use_case/book/RequestToBorrowBookUseCase.cpp"
#include "../main/MainScreen.h"

void showBorrowRequests(const User *userPtr);

void showRequests(const vector<BorrowRequest> &requests, const string &title);

#endif //LIBRARYSYSTEM_BORROWREQUESTSSCREEN_H

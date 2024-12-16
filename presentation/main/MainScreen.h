#ifndef LIBRARY_SYSTEM_MAIN_SCREEN_H
#define LIBRARY_SYSTEM_MAIN_SCREEN_H
#include "../../domain/use_case/auth/GetCurrentUserUseCase.cpp"
#include "../../domain/use_case/auth/SignOutUseCase.cpp"
#include "../auth/SignUpScreen.h"
#include "../auth/SignInScreen.h"

void showMainScreen();

void showMainMenu();

void showAuthMenu();

#endif //LIBRARY_SYSTEM_MAIN_SCREEN_H

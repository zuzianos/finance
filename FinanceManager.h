#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H
#include <iostream>
#include "UserManager.h"

using namespace std;

class FinanceManager {

    UserManager userManager;
    const string fileNameWithUsers;

public:
    FinanceManager(string fileNameWithUsers): userManager(fileNameWithUsers){};

    void userRegistration ();
    void userLoggin();
    bool isUserLoggedIn();

};
#endif

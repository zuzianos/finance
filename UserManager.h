#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>

#include "FileWithUsers.h"
#include "User.h"


using namespace std;

class UserManager {

int idOfLoggedUser;
 vector<User> users;

 User giveDataOfNewUser();
 int getIdOfNewUser();
 FileWithUsers fileWithUsers;
 string getLine();
 bool isLoginExist(string login);

public:
    UserManager(string fileNameWithUsers): fileWithUsers(fileNameWithUsers){
        idOfLoggedUser=0;
        users=fileWithUsers.getUsersFromFile();
    };
    void userRegistration ();
    void userLoggin();
    bool isUserLoggedIn();

};
#endif


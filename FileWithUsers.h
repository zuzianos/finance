#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>

#include "User.h"
#include "XmlHendler.h"
#include "Markup.h"

using namespace std;

class FileWithUsers : public XmlHendler
{
public:
    FileWithUsers(string fileNameWithUsers) : XmlHendler(fileNameWithUsers) {};
    vector <User> getUsersFromFile();
    void addUserToFile (User user);
};
#endif

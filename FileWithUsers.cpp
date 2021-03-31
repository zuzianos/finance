#include <iostream>
#include "FileWithUsers.h"
#include "Markup.h"

vector <User> FileWithUsers::getUsersFromFile() {

    CMarkup xml;
    User user;
    vector <User> users;

    bool fileExist= xml.Load("users.xml");

    if (!fileExist) {
        xml.AddElem("Users");
    }

    else {
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("User") ) {
            xml.IntoElem();
            xml.FindElem("UserId");
            user.setId (atoi( MCD_2PCSZ (xml.GetData() ) ));
            xml.FindElem("Login");
            user.setLogin(xml.GetData());
            xml.FindElem("Password");
            user.setPassword(xml.GetData());
            users.push_back(user);
            xml.OutOfElem();
        }
    }
    return users;
}

void FileWithUsers:: addUserToFile (User user){

       CMarkup xml;
       int id;
       string login="", password="";


    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());

    xml.Save("users.xml");
}





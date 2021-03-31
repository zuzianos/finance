# include"UserManager.h"

void UserManager::userRegistration () {
    User user = giveDataOfNewUser();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::giveDataOfNewUser() {
    User user;

    user.setId(takeIdOfNewUser());

    string name;
    cout<<"Podaj imie: ";
    cin>> name;
    user.setName(name);
    string surname;
    cout<<"Podaj nazwisko: ";
    cin>> surname;
    user.setSurname(surname);
    string login;
    do {
        cout<< "Podaj login: ";
        cin>> login;
        user.setLogin(login);
    } while (isLoginExist(user.getLogin()) == true);
    string password;
    cout << "Podaj haslo: ";
    cin>> password;
    user.setPassword(password);
    return user;
}
bool UserManager::isLoginExist(string login) {
    for (int i=0; i< users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }

    }
    return false;
}
int UserManager::takeIdOfNewUser() {

    int id= 10;
    string strId;
    CMarkup xml;
    bool fileExists = xml.Load("users.xml");
    if (!fileExists) {
        id=11;
    } else {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("User") ) {
            xml.IntoElem();
            xml.FindElem("UserId");
            id = atoi( MCD_2PCSZ (xml.GetData() ) );
            xml.OutOfElem();
        }
    }
    return id+1;
}

void UserManager::userLoggin() {
    User user;
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = getLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {

        if ((*itr).getLogin()==login  ) {
            for (int numberOfTrials = 3; numberOfTrials > 0; numberOfTrials--) {
                cout << "Podaj haslo Pozostalo prob: " << numberOfTrials << ": ";
                password = getLine();

                if ((*itr).getPassword() == password) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    idOfLoggedUser =itr -> getId();
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

string UserManager::getLine() {
    string enter = "";
    getline(cin, enter);
    return enter;
}


bool UserManager::isUserLoggedIn() {
    if (idOfLoggedUser > 0)
        return true;
    else
        return false;
}


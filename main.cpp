#include <iostream>
#include "financemanager.h"

using namespace std;

char choseOptionFromMainMenu();
char choseOptionFromUserMenu();
char getChar();

int main()
{
      FinanceManager financeManager("users.xml");

    char choice;
   while (true)
    {
        if (financeManager.isUserLoggedIn() == false)
        {
            choice = choseOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                financeManager.userRegistration();
                break;
            case '2':
                financeManager.userLoggin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = choseOptionFromUserMenu();

            switch (choice)
            {
            case '1':
                //financeManager.addIncomes();
                break;
            case '2':
                //financeManager.addExpenses();
                break;
            case '3':
               //financeManager.ShowBalanceFormTheCurrentMonth ();
                break;
            case '4':
               // financeManager.ShowBalanceFormTheChosenPeriod ();
                break;
            case '5':
                //financeManager.ShowBalanceFormTheLastMonth();
                break;
            case '6':
                //financeManager.changePasswordOfLoggedUser();
                break;
            case '7':
                //financeManager.logOutUser();
                break;
            }
        }
    }
    return 0;
}



char choseOptionFromMainMenu()
{
    char chose;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    chose = getChar();

    return chose;
}

char choseOptionFromUserMenu()
{
    char chose;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychód" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Wyœwietl bilans z bie¿¹cego misiaca" << endl;
    cout << "4. Wyœwietl bilans z wybranego okresu" << endl;
    cout << "5. Wyœwietl bilans z poprzedniego miesiaca" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    chose = getChar();

    return chose;
}

char getChar()
{
    string enter = "";
    char sign  = {0};
    cin.sync();

    while (true)
    {
        getline(cin, enter);

        if (enter.length() == 1)
        {
            sign = enter[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}

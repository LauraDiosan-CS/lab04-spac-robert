#include <iostream>
#include "Repo.h"
#include "Test.h"
using namespace std;
void menu() {
    cout << "0.Exit"<<endl;
    cout << "1.Add" << endl;
    cout << "2.Print" << endl;
}
bool except_date(char* string){
    int list_of_days[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int nrok = 0, nrzile, nrluni, i;
    int nran = 0;
    if ('9' >= string[0] and string[0] >= '0' and '9' >= string[1] and string[1]>= '0' and string[2] == '.' and string[5] == '.') {
        nrzile = (string[0]-'0') * 10 + (string[1]-'0');
        nrluni = (string[3]-'0') * 10 + (string[4]-'0');
    }
    else
        return false;
    i = 6;
        while(i < strlen(string)){
            if (string[i] == '.')
                return false;
            nran = nran * 10 + (string[i]-'0');
            i = i + 1;
        }
            
        if (0 < nrluni and nrluni <= 12 and list_of_days[nrluni] >= nrzile and nrzile > 0 and (nran % 4 == 0 or nran % 400 == 0))
            nrok = nrok + 1;
        else
            if (0 < nrluni and nrluni <= 12 and list_of_days[nrluni] > nrzile and nrzile > 0)
                nrok = nrok + 1;
        if (nrok == 1)
            return true;
        else
        return false;
}
int main()
{
    tests();
    int opt = 1,price;
    char date[250],name[250];
    Repo repo;

    while (opt) {
        cout << "Chose an option " << endl;
        menu();
        cout << "Your option is: ";
        cin >> opt;
        if (opt == 1) {
            cout << "Give a name: ";
            cin >> name;
            int ok = 1;
            while(ok==1){
                cout << "Give a date: ";
                cin >> date;
                if (except_date(date))
                    ok=0;
            }
            cout << "Give a price: ";
            cin>>price;
            cout << endl;
            Shop shop(name, date,price);
            repo.insert(shop);
        }
        if (opt == 2) {
            for (int i = 0; i < repo.get_len(); i++)
                cout << repo.get_all()[i] << endl;
        }
    }
    return 0;
}

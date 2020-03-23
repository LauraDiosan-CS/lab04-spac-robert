#include "UI.h"
#include "Test.h"
#include "Functions.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

char *allocate_memory()
{
    char* name = new char[0];
    string string_name;

    cin >> string_name;
    name = new char[string_name.size()+1];
    strcpy_s(name, 1 + string_name.size(), string_name.c_str());

    return name;
}

int kill_covit_19() {

    return rand() % 3;
}

void UI::add() {
    
    char *date= new char[0],* name=new char[0];
    int price;
    do {
        cout << "Give a name: ";
        name = allocate_memory();

        int ok = 1;
        while (ok == 1) {
            cout << "Give a date: ";
            date = allocate_memory();
            if (except_date(date))
                ok = 0;
            else
                cout << "Invalid date! ";
        }
        cout << "Give a price: ";
        cin >> price;
        cout << endl;
        if (kill_covit_19()==0)

            cout << "The object is infested wit COVID-19. BURN IT! "<<endl;

    } while (kill_covit_19()==0);
        this->service.insert_service(name, date, price);
}

void UI::print() {

    int n = this->service.get_len();
    Shop *array = this->service.get_all();
    for (int i = 0; i < n; i++)
        cout << array[i] << endl;
}

void UI::update_shop(){

    char* date = new char[0], * name = new char[0];
    int price;

    cout << "Give a name: ";
    name = allocate_memory();

    int ok = 1;
    while (ok == 1) {
        cout << "Give a date: ";
        date = allocate_memory();
        if (except_date(date))
            ok = 0;
        else
            cout << "Invalid date! ";
    }

    cout << "Give a price: ";
    cin >> price;
    cout << endl;
    this->service.update_shop(name, date, price);
}

void UI::delete_shop()
{
    cout << "Give a name for deleting: ";
    char* name= allocate_memory();
    this->service.delete_shop(name);
}

void UI::run() {
  
    string opt;
    bool ok = true;
    //Shop* undo_array;

    do {
        cout << endl << "Chose an option "<<endl;
        menu();
        cout << "Your option is: ";
        cin >> opt;

        if (opt.size() == 1)
        {
            if (opt[0] == '1') {
                this->add();
            }
            else
                if (opt[0] == '2') {
                    this->print();
                }
                else
                    if (opt[0] == '3') {
                        this->update_shop();
                    }
                    else
                        if (opt[0] == '4'){
                            this->delete_shop();
                        }
                        else
                            if (opt[0] == 'x') {
                                ok = false;
                            }
                             else
                                 cout << endl << "Invalid option!" << endl;
        }
        else
            cout << endl << "Invalid option!" << endl;
    } while (ok);
}
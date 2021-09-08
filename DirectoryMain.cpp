/*
    Група ПВ011
    08.09.21
    ЄРШОВ АНДРІЙ ВАСИЛЬОВИЧ
    Завдання 26.
    Створити клас «Довідник» з наступними полями:
        1. Назва фірми;
        2. Власник;
        3. Телефон;
        4. Адреса;
        5. Рід діяльності.
    Реалізувати такі можливості:
        1. Пошук за назвою;
        2. Пошук за власником;
        3. Пошук за номером телефону;
        4. Пошук за родом діяльності;
        5. Виведення на екран всіх записів і додавання.
    Вся інформація, повинна зберігатися в файлі, повинна бути реалізована можливість додавання нових даних.
*/
#include <iostream>
#include <string>
#include "Directory.h"
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
using std::ifstream;
using std::ofstream;

void menu();
void showfile(ifstream& in, string namefile);
void add(Directory& d, ofstream& out, string namefile);
void searchName(ifstream& in, string namefile);
void searchOwner(ifstream& in, string namefile);
void searchAdress(ifstream& in, string namefile);
void searchPhone(ifstream& in, string namefile);
void searchActivity(ifstream& in, string namefile);

// функція, яка приймає ВІДКРИТИЙ файл як аргумент 
// і читає з нього один пункт довідника
Directory readFile(ifstream& in);

int main()
{
    Directory d;
    string namefile = "directory.txt";
    ofstream out;
    ifstream in;
    char exit;

    do
    {
        system("cls");
        cout << "\n\t\t==== MENU ====\n";
        menu();
        char key;
        cout << "Make your choose: "; cin >> key;

        switch (key)
        {
        case's':
            showfile(in, namefile);
            break;
        case'+':
            cin.get();
            add(d, out, namefile);
            break;
        case'n':
            searchName(in, namefile);
            break;
        case'o':
            searchOwner(in, namefile);
            break;
        case'a':
            searchAdress(in, namefile);
            break;
        case'p':
            searchPhone(in, namefile);
            break;
        case't':
            searchActivity(in, namefile);
            break;
        default:
            cout << "The data entered is incorrect!\n";
            break;
        }
        cout << "If you want to exit press 'e'"; cin >> exit;
    } while (exit != 'e');
    system("pause");
    return 0;
}

void menu()
{
    cout << "If you want to review the directory, press 's'\n";
    cout << "If you want to add the directory, press '+'\n";
    cout << "If you want to find the company by name, press 'n'\n";
    cout << "If you want to find the company by owner, press 'o'\n";
    cout << "If you want to find the company by address, press 'a'\n";
    cout << "If you want to find the company by phone number 'p'\n";
    cout << "If you want to find the company by type of the activity 't'\n";
}


void showfile(ifstream& in, string path)
{
    in.open(path);
    if (!in.is_open())
    {
        cerr << "Can not open file for output.\n";
        exit(1);
    }
    else
    {
        char ch;
        while (in.get(ch))
            cout << ch;
    }
    in.close();
}

void add(Directory& d, ofstream& out, string namefile)
{
    out.open(namefile, std::ios::out | std::ios::app);
    if (out.is_open())
    {
        d.setData();
        out << d;
    }
    else
    {
        cerr << "Can not open " << namefile << " file for output.\n";
        exit(1);
    }
    out.close();
}

// пошук за назвою компанії, але перед цим необхідно прочитати файл в об'єкт
// реалізува функцію readFile можна читати об'єкт з файла.
void searchName(ifstream& in, string namefile)
{
    in.open(namefile);

    if (in.is_open())
    {
        string searchname;
        cout << "Enter the name of the company: ";
        std::cin.ignore(1, '\0'); // для коректної работи getline
        getline(cin, searchname);

        // поки файл не прочитаний до кінця
        while (!in.eof())
        {
            // отримання наступного елементу з файлу
            Directory d = readFile(in);

            // якщо збігається назва з введеною для пошуку
            if (d.getName() == searchname)
            {
                // працює!!!
                cout << "Found directory:\n";
                cout << d << endl;
            }
        }
    }
    else
    {
        cerr << "Can not open " << namefile << " file for output.\n";
        exit(1);
    }
    in.close();
}

void searchOwner(ifstream& in, string namefile)
{
    in.open(namefile);

    if (in.is_open())
    {
        string searchowner;
        cout << "Enter the name of the owner: ";
        std::cin.ignore(1, '\0'); // для коректної работи getline
        getline(cin, searchowner);

        // поки файл не прочитаний до кінця
        while (!in.eof())
        {
            // отримання наступного елементу з файлу
            Directory d = readFile(in);

            // якщо збігається ім'я з введеним для пошуку
            if (d.getOwner() == searchowner)
            {
                cout << "Found directory:\n";
                cout << d << endl;
            }
        }
    }
    else
    {
        cerr << "Can not open " << namefile << " file for output.\n";
        exit(1);
    }
    in.close();
}

void searchAdress(ifstream& in, string namefile)
{
    in.open(namefile);

    if (in.is_open())
    {
        string searchaddress;
        cout << "Enter the address of the company: ";
        std::cin.ignore(1, '\0'); // для коректної работи getline
        getline(cin, searchaddress);

        // поки файл не прочитаний до кінця
        while (!in.eof())
        {
            // отримання наступного елементу з файлу
            Directory d = readFile(in);

            // якщо збігається адреса з введеною для пошуку
            if (d.getAddress() == searchaddress)
            {
                cout << "Found directory:\n";
                cout << d << endl;
            }
        }
    }
    else
    {
        cerr << "Can not open " << namefile << " file for output.\n";
        exit(1);
    }
    in.close();
}

void searchPhone(ifstream& in, string namefile)
{
    in.open(namefile);

    if (in.is_open())
    {
        string searchphone;
        cout << "Enter the phone number of the company: ";
        std::cin.ignore(1, '\0'); // для коректної работи getline
        getline(cin, searchphone);

        // поки файл не прочитаний до кінця
        while (!in.eof())
        {
            // отримання наступного елементу з файлу
            Directory d = readFile(in);

            // якщо збігається адреса з введеною для пошуку
            if (d.getNumberP() == searchphone)
            {
                cout << "Found directory:\n";
                cout << d << endl;
            }
        }
    }
    else
    {
        cerr << "Can not open " << namefile << " file for output.\n";
        exit(1);
    }
    in.close();
}

void searchActivity(ifstream& in, string namefile)
{
    in.open(namefile);

    if (in.is_open())
    {
        string searchactivity;
        cout << "Enter the type of activity of the company: ";
        std::cin.ignore(1, '\0'); // для коректної работи getline
        getline(cin, searchactivity);

        // пока файл не прочитаний до кінця
        while (!in.eof())
        {
            // отримання наступного елементу з файлу
            Directory d = readFile(in);

            // якщо збігається адреса з введеною для пошуку
            if (d.getTypeA() == searchactivity)
            {
                cout << "Found directory:\n";
                cout << d << endl;
            }
        }
    }
    else
    {
        cerr << "Can not open " << namefile << " file for output.\n";
        exit(1);
    }
    in.close();
}

// функція, яка приймає ВІДКРИТИЙ файл як аргумент 
// і читає з нього один пункт довідника
Directory readFile(ifstream& in)
{
    // буфер, в який буде скидатись сміття з файлу
    char bff[256];
    // рядки-поля майбутнього об'єкта
    string name;
    string owner;
    string number_phone;
    string address;
    string type_activity;

    // читання полів порядково, пропускаючи непотрібні дані
    // "The name of the company: "
    in.read(bff, 25);
    getline(in, name);

    // "The owner of the company: "
    in.read(bff, 26);
    getline(in, owner);

    // "The phone number of the company: "
    in.read(bff, 33);
    getline(in, number_phone);

    // "The address of the company: "
    in.read(bff, 28);
    getline(in, address);

    // "The type of activity of the company: "
    in.read(bff, 37);
    getline(in, type_activity);

    // создание и возвращение новопрочитанного объекта
    return Directory(name, owner, number_phone, address, type_activity);
}